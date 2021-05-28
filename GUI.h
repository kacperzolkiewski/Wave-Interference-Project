///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame2
///////////////////////////////////////////////////////////////////////////////
class MyFrame2 : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel2;
		wxButton* m_saveToFile;
		wxButton* m_addSource1;
		wxButton* m_addSource2;
		wxStaticText* m_labelX;
		wxStaticText* m_labelY;
		wxStaticText* m_labelZ;
		wxSlider* m_sliderX;
		wxSlider* m_sliderY;
		wxSlider* m_sliderZ;
		wxButton* m_next;
		wxButton* m_prev;
		wxButton* m_copy;
		wxButton* m_start;
		wxButton* m_button8;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void saveToFileClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onScrollX( wxScrollEvent& event ) { event.Skip(); }
		virtual void onScrollY( wxScrollEvent& event ) { event.Skip(); }
		virtual void onScrollZ( wxScrollEvent& event ) { event.Skip(); }
		virtual void nextClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void prevClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void copyClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void startClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void resetClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PROJEKT 09"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame2();
	
};

#endif //__GUI_H__
