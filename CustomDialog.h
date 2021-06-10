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
	bool added = true;
	double x, y, amplitude, frequency;

	enum
	{
		ID_WXEDIT_X = 1001,
		ID_WXEDIT_Y = 1002,
		ID_WXEDIT_AMP = 1003,
		ID_WXEDIT_FREQ = 1004
	};

protected:
	wxStaticText* m_staticText_x;
	wxTextCtrl* m_textCtrl_x;
	wxStaticText* m_staticText_y;
	wxTextCtrl* m_textCtrl_y;
	wxStaticText* m_staticText_amp;
	wxTextCtrl* m_textCtrl_amp;
	wxStaticText* m_staticText_freq;
	wxTextCtrl* m_textCtrl_freq;
	wxStdDialogButtonSizer* m_sdbSizer_OK_CANCEL;
	wxButton* m_sdbSizer_OK;
	wxButton* m_sdbSizer_Cancel;

public:

	MyDialog(wxWindow* parent = NULL, wxWindowID id = wxID_ANY, const wxString& title = "Setting Parameters", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(365, 418), long style = wxDEFAULT_DIALOG_STYLE | wxSIMPLE_BORDER);
	~MyDialog();
	bool running() const { return added; }
	const auto getX() const { return x; }
	const auto getY() const { return y; }
	const auto getAmplitude() const { return amplitude; }
	const auto getFrequency() const { return frequency; }
};

#endif //__NONAME_H__
