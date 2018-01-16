
#ifndef __PDFTOJPGDLG_H__
#define __PDFTOJPGDLG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/hyperlink.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>


#include <wx/progdlg.h>


#undef pdftojpgDlg_STYLE
#define pdftojpgDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX


class pdftojpgDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		pdftojpgDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("pdftojpg"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = pdftojpgDlg_STYLE);
		virtual ~pdftojpgDlg();
		void WxButton1Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void WxHyperLinkCtrl1HyperLink(wxHyperlinkEvent& event);
	
	private:
		wxStaticText *WxStaticText3;
		wxDirDialog *DirDialog;
		wxFileDialog *OpenFileDialog;
		wxButton *WxButton1;
		wxHyperlinkCtrl *WxHyperLinkCtrl1;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxSpinCtrl *sp_com;
		wxComboBox *cb_DPI;
		wxStaticBox *WxStaticBox3;
		wxTextCtrl *te_outputFolder;
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxStaticBox *WxStaticBox2;
		wxTextCtrl *te_fileName;
		wxStaticBox *WxStaticBox1;
		
	private:

		enum
		{
			ID_WXSTATICTEXT3 = 1021,
			ID_WXBUTTON1 = 1020,
			ID_WXHYPERLINKCTRL1 = 1019,
			ID_WXSTATICTEXT2 = 1017,
			ID_WXSTATICTEXT1 = 1016,
			ID_SP_COM = 1015,
			ID_CB_DPI = 1014,
			ID_WXSTATICBOX3 = 1013,
			ID_TE_OUTPUTFOLDER = 1011,
			ID_WXBUTTON3 = 1010,
			ID_WXBUTTON2 = 1009,
			ID_WXSTATICBOX2 = 1008,
			ID_TE_FILENAME = 1007,
			ID_WXSTATICBOX1 = 1006
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
