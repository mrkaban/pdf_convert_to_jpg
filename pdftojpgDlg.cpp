///-----------------------------------------------------------------
///
/// @file      pdftojpgDlg.cpp
/// @author    tariel
/// Created:   05.04.2012 11:41:24
/// @section   DESCRIPTION
///            pdftojpgDlg class implementation
///
///------------------------------------------------------------------
#include "pdftojpgDlg.h"
#include "iapi.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// pdftojpgDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(pdftojpgDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(pdftojpgDlg::OnClose)
	EVT_BUTTON(ID_WXBUTTON1,pdftojpgDlg::WxButton1Click)
	EVT_BUTTON(ID_WXBUTTON3,pdftojpgDlg::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON2,pdftojpgDlg::WxButton2Click)
END_EVENT_TABLE()
////Event Table End

pdftojpgDlg::pdftojpgDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

pdftojpgDlg::~pdftojpgDlg()
{
	delete DirDialog;
	delete OpenFileDialog;
	delete WxHyperLinkCtrl1;
	delete WxStaticText2;
	delete sp_com;
	delete cb_DPI;
	delete WxStaticBox3;
	delete te_outputFolder;
	delete WxButton3;
	delete WxButton2;
	delete WxStaticBox2;
	delete te_fileName;
	delete WxStaticBox1;
	delete WxButton1;

} 

void pdftojpgDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("КонтинентСвободы"), wxPoint(22, 395), wxDefaultSize, 0, wxT("WxStaticText3"));

	DirDialog =  new wxDirDialog(this, wxT("Choose a directory"), wxT(""));

	OpenFileDialog =  new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("*.pdf"), wxFD_OPEN);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Convert"), wxPoint(465, 402), wxSize(97, 29), 0, wxDefaultValidator, wxT("WxButton1"));

	WxHyperLinkCtrl1 = new wxHyperlinkCtrl(this, ID_WXHYPERLINKCTRL1, wxT("http://КонтинентСвободы.рф"), wxT("http://КонтинентСвободы.рф"), wxPoint(21, 419), wxSize(171, 28), wxNO_BORDER | wxHL_CONTEXTMENU, wxT("WxHyperLinkCtrl1"));
	WxHyperLinkCtrl1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, true, wxT("MS Sans Serif")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Compression"), wxPoint(262, 310), wxDefaultSize, 0, wxT("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("DPI"), wxPoint(47, 311), wxDefaultSize, 0, wxT("WxStaticText1"));

	sp_com = new wxSpinCtrl(this, ID_SP_COM, wxT("100"), wxPoint(263, 333), wxSize(104, 24), wxSP_ARROW_KEYS, 0, 100, 100);

	wxArrayString arrayStringFor_cb_DPI;
	arrayStringFor_cb_DPI.Add(wxT("100"));
	arrayStringFor_cb_DPI.Add(wxT("200"));
	arrayStringFor_cb_DPI.Add(wxT("300"));
	arrayStringFor_cb_DPI.Add(wxT("400"));
	arrayStringFor_cb_DPI.Add(wxT("500"));
	arrayStringFor_cb_DPI.Add(wxT("600"));
	cb_DPI = new wxComboBox(this, ID_CB_DPI, wxT("100"), wxPoint(46, 333), wxSize(104, 23), arrayStringFor_cb_DPI, wxTE_READONLY, wxDefaultValidator, wxT("cb_DPI"));

	WxStaticBox3 = new wxStaticBox(this, ID_WXSTATICBOX3, wxT("Options"), wxPoint(21, 283), wxSize(541, 91));

	te_outputFolder = new wxTextCtrl(this, ID_TE_OUTPUTFOLDER, wxT(""), wxPoint(43, 189), wxSize(503, 22), 0, wxDefaultValidator, wxT("te_outputFolder"));

	WxButton3 = new wxButton(this, ID_WXBUTTON3, wxT("Browse"), wxPoint(459, 226), wxSize(87, 29), 0, wxDefaultValidator, wxT("WxButton3"));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT("Open"), wxPoint(455, 93), wxSize(86, 29), 0, wxDefaultValidator, wxT("WxButton2"));

	WxStaticBox2 = new wxStaticBox(this, ID_WXSTATICBOX2, wxT("Output Folder"), wxPoint(23, 152), wxSize(539, 113));

	te_fileName = new wxTextCtrl(this, ID_TE_FILENAME, wxT(""), wxPoint(39, 55), wxSize(503, 22), 0, wxDefaultValidator, wxT("te_fileName"));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, wxT("File to Convert"), wxPoint(23, 16), wxSize(540, 119));

	SetTitle(wxT("PDF Converter v1.26"));
	SetIcon(wxNullIcon);
	SetSize(8,8,605,487);
	Center();
	
	////GUI Items Creation End
}

void pdftojpgDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}



/*
 * WxButton1Click
 */
void pdftojpgDlg::WxButton1Click(wxCommandEvent& event)
{
	wxString fileName = te_fileName->GetValue();
	
    if ( fileName == wxT("") ){
        wxMessageBox( _T("Please select pdf file name!!!"));
        return;
    }

	wxString outputFolder = te_outputFolder->GetValue();

	if ( outputFolder == wxT("") ){
        wxMessageBox( _T("Please select output folder!!!")); 
        return;
    }

	if (outputFolder.Last() != '\\')
		outputFolder += '\\';
    
    const char* gsargv[] =
    {
    	"pdf2img",
    	"-dNOPAUSE",
    	"-dBATCH",
        "-sDEVICE=jpeg",
		"-dJPEGQ=100",
		"-dSAFER", 
		"-r300" ,
    	"-sOutputFile=d:\\temp\\form-%02d.jpg",
		"d:\\temp\\form.pdf"
    };
    
	char c_dpi[MAX_PATH];
	wxString dpi = cb_DPI->GetValue();
	if (dpi == wxT("100"))
		strcpy(c_dpi , "-r100" );
	else if (dpi == wxT("200"))
		strcpy(c_dpi , "-r200");
	else if (dpi == wxT("300"))
		strcpy(c_dpi , "-r300");
	else if (dpi == wxT("400"))
		strcpy(c_dpi , "-r400");
	else if (dpi == wxT("500"))
		strcpy(c_dpi , "-r500");
	else if (dpi == wxT("600"))
		strcpy(c_dpi , "-r600");

	gsargv[6] = c_dpi;

	int q = sp_com->GetValue();
	
	if (q > 0 && q < 101)
	{
		char c_com[MAX_PATH];
		sprintf(c_com, "-dJPEGQ=%d",q);
		gsargv[4] = c_com;	
	}

	
	

	char c_file[MAX_PATH * 4];

	strcpy(c_file,fileName.mb_str().data());
	gsargv[8] = c_file;
	fileName.Remove(fileName.Length()-4,4);
	fileName = fileName.AfterLast('\\');
	fileName += wxT("-%03d.jpg");
	
	char c_outFile[MAX_PATH * 4];
	sprintf(c_outFile, "-sOutputFile=%s", outputFolder.mb_str().data());
	strcat(c_outFile,fileName.mb_str().data());
	gsargv[7] = c_outFile;
    
    
	void* pGS;
	if (gsapi_new_instance(&pGS, NULL) < 0)
	{
        wxMessageBox(wxT("ERROR Init gsdll"));
		return;
	}
	
	wxProgressDialog progressDlg(_("Please wait"), _("Converting"),	0, this, wxPD_APP_MODAL );

	gsapi_init_with_args(pGS, 9, (char**)gsargv);
	gsapi_exit(pGS);
	gsapi_delete_instance(pGS);

}

/*
 * WxButton2Click
 */
void pdftojpgDlg::WxButton2Click(wxCommandEvent& event)
{
    if (wxID_OK == OpenFileDialog->ShowModal())
    {
        wxString dir = OpenFileDialog->GetDirectory();
        if ( dir[ dir.Length()-1 ] != wxT('\\') )
            dir.Append( wxT("\\") );

        wxString fileName = dir + OpenFileDialog->GetFilename();
        te_fileName->Clear();
        te_fileName->AppendText(fileName);
        
        if (te_outputFolder->GetValue() == wxT(""))
        {
            te_outputFolder->Clear();
            te_outputFolder->AppendText(dir);
        }
        
    }
}

/*
 * WxButton3Click
 */
void pdftojpgDlg::WxButton3Click(wxCommandEvent& event)
{
	if (DirDialog->ShowModal()==wxID_OK)
    {
        te_outputFolder->Clear();
        wxString s = DirDialog->GetPath();
        te_outputFolder->AppendText(s);
     
    }

}
