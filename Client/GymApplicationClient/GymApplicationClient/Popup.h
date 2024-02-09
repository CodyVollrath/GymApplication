#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>
using namespace std;

class Popup : public wxDialog {
public:
	Popup(wxWindow* parent, const wxString& title, const vector<wxString>& fieldNames);
	virtual ~Popup();
};