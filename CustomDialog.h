///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/wx.h>
#include <array>
#include <string>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog
///////////////////////////////////////////////////////////////////////////////
class MyDialog : public wxDialog
{
private:
	bool add = true;
	double x, y, amplitude, frequency;
protected:
	wxStaticText* m_staticText1;
	wxTextCtrl* m_textCtrl1;
	wxStaticText* m_staticText2;
	wxTextCtrl* m_textCtrl2;
	//wxStaticText* m_staticText3;
	//wxTextCtrl* m_textCtrl3;
	wxStaticText* m_staticText4;
	wxTextCtrl* m_textCtrl4;
	wxStaticText* m_staticText5;
	wxTextCtrl* m_textCtrl5;
	wxStdDialogButtonSizer* m_sdbSizer1;
	wxButton* m_sdbSizer1OK;
	wxButton* m_sdbSizer1Cancel;

public:

	MyDialog(wxWindow* parent = NULL, wxWindowID id = wxID_ANY, const wxString& title = "Setting Parameters", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(365, 418), long style = wxDEFAULT_DIALOG_STYLE | wxSIMPLE_BORDER);
	~MyDialog();
	bool running() const { return add; }
	const auto get_x() const { return x; }
	const auto get_y() const { return y; }
	//const auto get_z() const { return z; }
	const auto get_amplitude() const { return amplitude; }
	const auto get_frequency() const { return frequency; }
};

#endif //__NONAME_H__
