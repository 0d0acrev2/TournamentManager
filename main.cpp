#include <windows.h>
#include <windowsx.h>    // per Scompositore di messaggi

#include "resource.h"    // Risorse

#include "Abbinamenti.h"

HINSTANCE ghinstApp;          // h. di istanza dell'applicazione

HWND ghwndApp;                // h. di finestra principale dell'applicazione

HWND hAggiungiGiocatore;                 // h. di un controllo button
HWND hCreaAbbinamenti;
HWND hFinestraAggiungiGiocatore;
HWND hClassifica;
HWND hAbbinamenti;

//Altri handle di altra dialog
HWND hOk;
HWND hCancel;
HWND hNome;

Abbinamenti *abbinamenti = new Abbinamenti();

//Prototipi Interni (MPF)//////////////////////////////////////////////////////////
BOOL CALLBACK Dlg_Proc (HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

BOOL Dlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void Dlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void Dlg_OnClose(HWND hwnd);

//Aggiungi Giocatore dialog

BOOL Dlg_OnInitAggiungiGiocatoreProc(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void Dlg_AggiungiGiocatore(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
BOOL APIENTRY DlgAggiungiGiocatore(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
void Dlg_OnCloseAggiungiGiocatore(HWND hwnd);

//Implementazioni//////////////////////////////////////////////////////////////////

int WINAPI WinMain (HINSTANCE hinstExe, HINSTANCE hinstPrev, LPSTR lpszCmdLine, int nCmdShow)
{
	// salvataggio h. di istanza globale dell'applicazione
	ghinstApp = hinstExe;
	// avvio del dialogo (bloccante)
	DialogBox(hinstExe, MAKEINTRESOURCE(IDD_DIALOGMAIN), NULL, Dlg_Proc);
	return(0);
}

BOOL CALLBACK Dlg_Proc (HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
		HANDLE_MSG(hDlg, WM_INITDIALOG, Dlg_OnInitDialog);
		HANDLE_MSG(hDlg, WM_COMMAND, Dlg_OnCommand);
		HANDLE_MSG(hDlg, WM_CLOSE, Dlg_OnClose);
	default:
		break;
	}

	return FALSE;
}

BOOL APIENTRY DlgAggiungiGiocatore(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hDlg, WM_INITDIALOG, Dlg_OnInitAggiungiGiocatoreProc);
        HANDLE_MSG(hDlg, WM_COMMAND, Dlg_AggiungiGiocatore);
		HANDLE_MSG(hDlg, WM_CLOSE, Dlg_OnCloseAggiungiGiocatore);

    default:
	//return FALSE;
	break;
    }

    return FALSE;
}

BOOL Dlg_OnInitAggiungiGiocatoreProc(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    hOk = GetDlgItem(hwnd,ID_OK);
	hCancel = GetDlgItem(hwnd,ID_CANCEL);
    hNome = GetDlgItem(hwnd, IDC_NOME);

    return TRUE;
}

void Dlg_AggiungiGiocatore(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    char szNomeGiocatoreInserito[255];
    szNomeGiocatoreInserito[0] = 0;

	switch(id)
	{
        case ID_OK:
            GetWindowText(hNome, szNomeGiocatoreInserito, 80);
            if(szNomeGiocatoreInserito[0] == 0)
            {
                MessageBox(hwnd, "Non hai inserito nessuna stringa!", "Attenzione", 0);
            }
            else
            {
                abbinamenti->classifica->aggiungiGiocatore(new Giocatore(szNomeGiocatoreInserito));
                SendMessage(hClassifica, LB_ADDSTRING, NULL, (LPARAM)szNomeGiocatoreInserito);
                Dlg_OnCloseAggiungiGiocatore(hwnd);
            }

            break;
	}

}


BOOL Dlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{

	// salvataggio h. globale finestra principale dell'applicazione
	ghwndApp = hwnd;

	// Impostazione icona per l'applicazione
	//SetClassLong(hwnd, GCL_HICON, (LONG) LoadIcon(ghinstApp, MAKEINTRESOURCE(IDI_ICONA)));

    // Lettura dell'handle del bottone
	hAggiungiGiocatore = GetDlgItem(hwnd,IDC_AGGIUNGI_GIOCATORE);
	hCreaAbbinamenti = GetDlgItem(hwnd,IDC_ABBINAMENTI);
    hClassifica = GetDlgItem(hwnd,IDC_LIST_CLASSIFICA);
    hAbbinamenti = GetDlgItem(hwnd,IDC_LIST_ABBINAMENTI);

	return TRUE;
}

void Dlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{

	switch(id)
	{
        case IDC_AGGIUNGI_GIOCATORE:
            hFinestraAggiungiGiocatore = CreateDialog(ghinstApp, MAKEINTRESOURCE(IDD_AGGIUNGIGIOCATORE), ghwndApp, DlgAggiungiGiocatore);
            break;
        case IDC_ABBINAMENTI:
            MessageBox(hwnd, "Gli Abbinamenti sono stati creati!", "Ok!", MB_OK);
            break;
	}

}

void Dlg_OnClose(HWND hwnd)
{
        // Chiusura del dialogo
        EndDialog(hwnd,0);

}

void Dlg_OnCloseAggiungiGiocatore(HWND hwnd)
{
        // Chiusura del dialogo
        EndDialog(hwnd,0);

}
