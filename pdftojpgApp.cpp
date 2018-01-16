#include "pdftojpgApp.h"
#include "pdftojpgDlg.h"

IMPLEMENT_APP(pdftojpgDlgApp)

bool pdftojpgDlgApp::OnInit()
{
	pdftojpgDlg* dialog = new pdftojpgDlg(NULL);
	SetTopWindow(dialog);
	dialog->Show(true);		
	return true;
}
 
int pdftojpgDlgApp::OnExit()
{
	return 0;
}
