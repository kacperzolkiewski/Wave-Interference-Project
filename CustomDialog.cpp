///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CustomDialog.h"

///////////////////////////////////////////////////////////////////////////

MyDialog::MyDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* vertSizer;
	vertSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* sbSizer;
	sbSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Set Parameters")), wxVERTICAL);

	m_staticText1 = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Set X"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->Wrap(-1);
	sbSizer->Add(m_staticText1, 0, wxALL, 5);

	m_textCtrl1 = new wxTextCtrl(sbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl1, 0, wxALL, 5);

	m_staticText2 = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Set Y"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	sbSizer->Add(m_staticText2, 0, wxALL, 5);

	m_textCtrl2 = new wxTextCtrl(sbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl2, 0, wxALL, 5);

//	m_staticText3 = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Set Z"), wxDefaultPosition, wxDefaultSize, 0);
	//m_staticText3->Wrap(-1);
	//sbSizer->Add(m_staticText3, 0, wxALL, 5);

	//m_textCtrl3 = new wxTextCtrl(sbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	//sbSizer->Add(m_textCtrl3, 0, wxALL, 5);

	m_staticText4 = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Amplitude [m]"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	sbSizer->Add(m_staticText4, 0, wxALL, 5);

	m_textCtrl4 = new wxTextCtrl(sbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl4, 0, wxALL, 5);

	m_staticText5 = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Frequency [Hz]"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText5->Wrap(-1);
	sbSizer->Add(m_staticText5, 0, wxALL, 5);

	m_textCtrl5 = new wxTextCtrl(sbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl5, 0, wxALL, 5);


	vertSizer->Add(sbSizer, 4, wxALIGN_CENTER_HORIZONTAL | wxALL | wxSHAPED, 5);

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton(this, wxID_OK);
	m_sdbSizer1->AddButton(m_sdbSizer1OK);
	m_sdbSizer1Cancel = new wxButton(this, wxID_CANCEL);
	m_sdbSizer1->AddButton(m_sdbSizer1Cancel);
	m_sdbSizer1->Realize();

	vertSizer->Add(m_sdbSizer1, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);


	this->SetSizer(vertSizer);
	this->Layout();

	this->Centre(wxBOTH);

	//////////////////////////////
	//Controlling Parameters
	//////////////////////////////


	x = 100;
	if (x < 0.0 || x > 1000.0){
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}
	y = 100;
	if (y < 0.0 or y > 1000.0) {
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}
	//z = wxAtof(m_textCtrl3->GetValue());
	//if (z < 0.0 or z > 1000.0) {
		//flag = false;
		//wxLogMessage("Given wrong parameter!!!");
	//}
	amplitude = 4;
	if (amplitude < 0 || amplitude > 9.999) {
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}
	frequency = 2;
	if (frequency < 0 || frequency > 9.99999) {
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}


}

MyDialog::~MyDialog()
{
	Destroy();
}
