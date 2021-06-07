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

	m_staticText_x = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Set X"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_x->Wrap(-1);
	sbSizer->Add(m_staticText_x, 0, wxALL, 5);

	m_textCtrl_x = new wxTextCtrl(sbSizer->GetStaticBox(), ID_WXEDIT_X, wxEmptyString, wxPoint(15, 60), wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl_x, 0, wxALL, 5);

	m_staticText_y = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Set Y"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_y->Wrap(-1);
	sbSizer->Add(m_staticText_y, 0, wxALL, 5);

	m_textCtrl_y = new wxTextCtrl(sbSizer->GetStaticBox(), ID_WXEDIT_Y, wxEmptyString, wxPoint(15, 120), wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl_y, 0, wxALL, 5);

//	m_staticText3 = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Set Z"), wxDefaultPosition, wxDefaultSize, 0);
	//m_staticText3->Wrap(-1);
	//sbSizer->Add(m_staticText3, 0, wxALL, 5);

	//m_textCtrl3 = new wxTextCtrl(sbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	//sbSizer->Add(m_textCtrl3, 0, wxALL, 5);

	m_staticText_amp = new wxStaticText(sbSizer->GetStaticBox(), ID_WXEDIT_AMP, wxT("Amplitude [m]"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_amp->Wrap(-1);
	sbSizer->Add(m_staticText_amp, 0, wxALL, 5);

	m_textCtrl_amp = new wxTextCtrl(sbSizer->GetStaticBox(), ID_WXEDIT_FREQ, wxEmptyString, wxPoint(15, 180), wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl_amp, 0, wxALL, 5);

	m_staticText_freq = new wxStaticText(sbSizer->GetStaticBox(), wxID_ANY, wxT("Frequency [Hz]"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_freq->Wrap(-1);
	sbSizer->Add(m_staticText_freq, 0, wxALL, 5);

	m_textCtrl_freq = new wxTextCtrl(sbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxPoint(15, 240), wxDefaultSize, 0);
	sbSizer->Add(m_textCtrl_freq, 0, wxALL, 5);


	vertSizer->Add(sbSizer, 4, wxALIGN_CENTER_HORIZONTAL | wxALL | wxSHAPED, 5);

	Bind(wxEVT_TEXT, &MyDialog::updateX, this, ID_WXEDIT_X);
	Bind(wxEVT_TEXT, &MyDialog::updateY, this, ID_WXEDIT_Y);
	Bind(wxEVT_TEXT, &MyDialog::updateAMP, this, ID_WXEDIT_AMP);
	Bind(wxEVT_TEXT, &MyDialog::updateFREQ, this, ID_WXEDIT_FREQ);

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer_OK = new wxButton(this, wxID_OK);
	m_sdbSizer1->AddButton(m_sdbSizer_OK);
	m_sdbSizer_Cancel = new wxButton(this, wxID_CANCEL);
	m_sdbSizer1->AddButton(m_sdbSizer_Cancel);
	m_sdbSizer1->Realize();

	vertSizer->Add(m_sdbSizer1, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);


	this->SetSizer(vertSizer);
	this->Layout();

	this->Centre(wxBOTH);

	this->ShowModal();

	
	if (m_textCtrl_x) x = wxAtof(m_textCtrl_x->GetValue());

	if (x < 0.0 || x > 1000.0) {
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}

	if (m_textCtrl_y) y = wxAtof(m_textCtrl_y->GetValue());
	if (y < 0.0 or y > 1000.0) {
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}

	//z = wxAtof(m_textCtrl3->GetValue());
	//if (z < 0.0 or z > 1000.0) {
		//flag = false;
		//wxLogMessage("Given wrong parameter!!!");
	//}
	if (m_textCtrl_amp) amplitude = wxAtof(m_textCtrl_amp->GetValue());

	if (amplitude < 0 || amplitude > 9.999) {
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}

	if (m_textCtrl_freq) frequency = wxAtof(m_textCtrl_freq->GetValue());

	if (frequency < 0 || frequency > 9.99999) {
		add = false;
		wxLogMessage("Given wrong parameter!!!");
	}

	

}

MyDialog::~MyDialog()
{
	Destroy();
}


//////////////////////////////////////////
//Controlling and Updating Parameters
//////////////////////////////////////////
void MyDialog::updateX(wxCommandEvent& e )
{
	
}

void MyDialog::updateY(wxCommandEvent& e)
{
	
}

void MyDialog::updateAMP(wxCommandEvent& e)
{
	
}

void MyDialog::updateFREQ(wxCommandEvent& e)
{
	
}



