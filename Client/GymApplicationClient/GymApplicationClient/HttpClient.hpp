#include <iostream>
#include <string>
#include <curl/curl.h>
#include <vector>

class HttpClient {
public:
    HttpClient() {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
    }

    ~HttpClient() {
        if (curl) {
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    std::string get(const std::string& url, const std::vector<std::string>& headers = {}) {
        return performRequest(url, HTTP_GET, "", headers);
    }

    std::string post(const std::string& url, const std::string& data, const std::vector<std::string>& headers = {}) {
        return performRequest(url, HTTP_POST, data, headers);
    }

    std::string put(const std::string& url, const std::string& data, const std::vector<std::string>& headers = {}) {
        return performRequest(url, HTTP_PUT, data, headers);
    }

    std::string del(const std::string& url, const std::vector<std::string>& headers = {}) {
        return performRequest(url, HTTP_DELETE, "", headers);
    }

private:
    CURL* curl;

    enum HttpRequestType {
        HTTP_GET,
        HTTP_POST,
        HTTP_PUT,
        HTTP_DELETE
    };

    static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t totalSize = size * nmemb;
        output->append((char*)contents, totalSize);
        return totalSize;
    }

    std::string performRequest(const std::string& url, HttpRequestType type, const std::string& data = "", const std::vector<std::string>& headers = {}) {
        if (!curl) {
            std::cerr << "cURL initialization failed." << std::endl;
            return "";
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        if (type == HTTP_POST || type == HTTP_PUT) {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        }

        if (!headers.empty()) {
            struct curl_slist* headerList = nullptr;
            for (const auto& header : headers) {
                headerList = curl_slist_append(headerList, header.c_str());
            }
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
        }

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        if (type == HTTP_PUT) {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        }
        else if (type == HTTP_DELETE) {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
        }

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
        }

        return response;
    }
};