from flask import Flask, make_response, jsonify, request
from users import Users, User

app = Flask(__name__)
adminUser = User('admin', 'password', 1, firstName='Sysadmin', lastName='Sysadmin')
app_users = Users()
app_users.add_user(adminUser)

@app.route('/api/login', methods=['POST'])
def login():
    status = 404
    if request.is_json:
        json_data = request.get_json()
        username = json_data.get('username')
        password = json_data.get('password')
        matched_user = app_users.check_login(username, password)
        response_content = jsonify({'error': 'user not found'})
        if matched_user is not None:
            response_content = matched_user.to_json()
            status = 200
        response = make_response(response_content, status)
        response.headers['Content-Type'] = 'application/json'
        return response
    return 'error', 500

@app.route('/api/test', methods=['GET'])
def test():
    return 'TEST'

if __name__ == '__main__':
    app.run(debug=True)
