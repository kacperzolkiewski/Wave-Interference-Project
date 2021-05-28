///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame2::MyFrame2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	bSizer6->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer3->Add( bSizer6, 2, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_saveToFile = new wxButton( this, wxID_ANY, wxT("SAVE TO FILE"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_saveToFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_addSource1 = new wxButton( this, wxID_ANY, wxT("AddSource1"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_addSource1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_addSource2 = new wxButton( this, wxID_ANY, wxT("AddSource2"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_addSource2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_labelX = new wxStaticText( this, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labelX->Wrap( -1 );
	bSizer9->Add( m_labelX, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_labelY = new wxStaticText( this, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labelY->Wrap( -1 );
	bSizer9->Add( m_labelY, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_labelZ = new wxStaticText( this, wxID_ANY, wxT("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labelZ->Wrap( -1 );
	bSizer9->Add( m_labelZ, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_sliderX = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer10->Add( m_sliderX, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderY = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer10->Add( m_sliderY, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderZ = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer10->Add( m_sliderZ, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer8->Add( bSizer10, 3, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer8, 1, wxEXPAND, 5 );
	
	m_next = new wxButton( this, wxID_ANY, wxT("NEXT"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_next, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_prev = new wxButton( this, wxID_ANY, wxT("PREV"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_prev, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_copy = new wxButton( this, wxID_ANY, wxT("COPY"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_copy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_start = new wxButton( this, wxID_ANY, wxT("START"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_start, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button8 = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer4->Add( m_button8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_panel2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame2::onUpdateUI ), NULL, this );
	m_saveToFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::saveToFileClick ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_next->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::nextClick ), NULL, this );
	m_prev->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::prevClick ), NULL, this );
	m_copy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::copyClick ), NULL, this );
	m_start->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::startClick ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::resetClick ), NULL, this );
}

MyFrame2::~MyFrame2()
{
	// Disconnect Events
	m_panel2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame2::onUpdateUI ), NULL, this );
	m_saveToFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::saveToFileClick ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame2::onScrollX ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame2::onScrollY ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame2::onScrollZ ), NULL, this );
	m_next->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::nextClick ), NULL, this );
	m_prev->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::prevClick ), NULL, this );
	m_copy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::copyClick ), NULL, this );
	m_start->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::startClick ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::resetClick ), NULL, this );
	
}
