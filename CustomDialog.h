#pragma once
#include <wx/wx.h>
#include <array>
#include <string>
class CustomDialogAdd : public wxDialog {
public:
	CustomDialogAdd(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(300, 400)) {

		wxPanel* panel = new wxPanel(this, -1);

		wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
		wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

		wxStaticBox* st = new wxStaticBox(panel, -1, wxT("Parameters"),
			wxPoint(5, 5), wxSize(250, 350));

		wxTextCtrl* tc1 = new wxTextCtrl(panel, -1, wxT("X"), wxPoint(15, 60));
		wxStaticText* t1 = new wxStaticText(panel, -1, wxT("Set X from [0 - 770]"), wxPoint(15, 30));
		wxTextCtrl* tc2 = new wxTextCtrl(panel, -1, wxT("Y"), wxPoint(15, 120));
		wxStaticText* t2 = new wxStaticText(panel, -1, wxT("Set Y from [0 - 235]"), wxPoint(15, 90));
		wxTextCtrl* tc3 = new wxTextCtrl(panel, -1, wxT("Amplitude"), wxPoint(15, 180));
		wxStaticText* t3 = new wxStaticText(panel, -1, wxT("Set Aplitude from (0 - 9.9]"), wxPoint(15, 150));
		wxTextCtrl* tc4 = new wxTextCtrl(panel, -1, wxT("Frequency"), wxPoint(15, 240));
		wxStaticText* t4 = new wxStaticText(panel, -1, wxT("Set Frequency from (0 - 9.9]"), wxPoint(15, 210));


		wxButton* okButton = new wxButton(this, wxID_OK, _("OK"),
			wxDefaultPosition, wxSize(70, 30));
		wxButton* closeButton = new wxButton(this, wxID_CANCEL, _("Cancel"),
			wxDefaultPosition, wxSize(70, 30));

		hbox->Add(okButton, 1);
		hbox->Add(closeButton, 1, wxLEFT, 5);

		vbox->Add(panel, 1);
		vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

		SetSizer(vbox);
		Centre();
		ShowModal();

		x = atof(tc1->GetValue());
		if (x < 0 || x > 770) {
			add = false;
			wxLogMessage("Wrong x parameter");
		}
		y = atof(tc2->GetValue());
		if (y < 0 || y > 235) {
			add = false;
			wxLogMessage("Wrong y parameter");
		}
		amp = atof(tc3->GetValue());
		if (amp <= 0 || amp > 9.9) {
			add = false;
			wxLogMessage("Wrong amp parameter");
		}
		freq = atof(tc4->GetValue());
		if (freq <= 0 || freq > 9.9) {
			add = false;
			wxLogMessage("Wrong freq parameter");
		}
		Destroy();
	}
	wxPoint return_Point() const {
		return wxPoint(x, y);
	}
	double get_x()const { return x; }
	double get_y()const { return y; }
	double return_freq()const {
		return freq;
	}
	double return_amp()const {
		return amp;
	}
	bool isOK()const { return add; }
private:
	bool add = true;
	double x, y, amp, freq;
};

