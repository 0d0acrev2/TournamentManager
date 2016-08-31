#include <windows.h>
#include <windowsx.h>    // per Scompositore di messaggi
#include <fstream>
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <sstream>

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

bool changeBehavior = true;

//Prototipi Interni (MPF)//////////////////////////////////////////////////////////
BOOL CALLBACK Dlg_Proc (HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

BOOL Dlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void Dlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void Dlg_OnClose(HWND hwnd);

//Aggiungi Giocatore dialog
Giocatore trovaGiocatore(char passata[]);

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
    char buffer[20];
    int itemIndex;

    switch (uMsg)
    {
        HANDLE_MSG(hDlg, WM_INITDIALOG, Dlg_OnInitDialog);
        HANDLE_MSG(hDlg, WM_COMMAND, Dlg_OnCommand);
        HANDLE_MSG(hDlg, WM_CLOSE, Dlg_OnClose);
    case WM_CONTEXTMENU:
        itemIndex = (int) SendMessage(hClassifica, LB_GETCURSEL, (WPARAM)0, (LPARAM) 0);

        if ((HWND)wParam == hClassifica && itemIndex != -1)
        {
            HMENU hTastoDestroMenu = CreatePopupMenu();

            SendMessage(hClassifica, LB_GETTEXT, itemIndex,(LPARAM) buffer);
            InsertMenu(hTastoDestroMenu, 0, MF_BYCOMMAND | MF_STRING | MF_ENABLED, 1, "Punteggio");
            InsertMenu(hTastoDestroMenu, 0, MF_BYCOMMAND | MF_STRING | MF_ENABLED, 1, "Aggiungi Vittoria");
            InsertMenu(hTastoDestroMenu, 0, MF_BYCOMMAND | MF_STRING | MF_ENABLED, 1, buffer);
            printf("%s", buffer);
            int cliccato = TrackPopupMenu(hTastoDestroMenu, TPM_TOPALIGN | TPM_LEFTALIGN | TPM_RETURNCMD, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), 0, hClassifica, 0);
            if (cliccato == 1)
            {
                Giocatore giocatore = trovaGiocatore(buffer);
                int appoggioPunteggio = giocatore.getPunteggio();
                std::stringstream stros;
                stros << appoggioPunteggio;
                MessageBox(ghwndApp, stros.str().c_str(), "Punteggio", MB_OK);
                //printf("%d", giocatore.getPunteggio());
            }
            if (cliccato == 1)
            {
                Giocatore giocatore = trovaGiocatore(buffer);
                giocatore.aggiungiVittoria();

            }
        }
    default:
        break;
    }

    //free(buffer);

    return FALSE;
}

BOOL APIENTRY DlgAggiungiGiocatore(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hDlg, WM_INITDIALOG, Dlg_OnInitAggiungiGiocatoreProc);
        HANDLE_MSG(hDlg, WM_COMMAND, Dlg_AggiungiGiocatore);
        HANDLE_MSG(hDlg, WM_CLOSE, Dlg_OnClose);
        break;
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

void creaStringaPerStampaClassifica(char stringaDaPassare[])
{
    SendMessage(hClassifica, LB_ADDSTRING, 0, (LPARAM)stringaDaPassare);

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
            MessageBox(hwnd, "Non hai inserito nessun nome!", "Attenzione!", MB_ICONWARNING);
        }
        else
        {
            abbinamenti->classifica->aggiungiGiocatore(new Giocatore(szNomeGiocatoreInserito));
            creaStringaPerStampaClassifica(szNomeGiocatoreInserito);
            Dlg_OnClose(hwnd);
        }

        break;
    case ID_CANCEL:
        Dlg_OnClose(hwnd);
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
    hAggiungiGiocatore = GetDlgItem(hwnd,IDC_LEGGI_AGGIUNGI);
    hCreaAbbinamenti = GetDlgItem(hwnd,IDC_ABBINAMENTI);
    hClassifica = GetDlgItem(hwnd,IDC_LIST_CLASSIFICA);
    hAbbinamenti = GetDlgItem(hwnd,IDC_LIST_ABBINAMENTI);

    return TRUE;
}

void Dlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{

    switch(id)
    {
    case IDC_LEGGI_AGGIUNGI:
        if(changeBehavior == false)
        {
            hFinestraAggiungiGiocatore = CreateDialog(ghinstApp, MAKEINTRESOURCE(IDD_AGGIUNGIGIOCATORE), ghwndApp, DlgAggiungiGiocatore);
        }
        else
        {
            std::string line;
            std::ifstream myfile ("ListaGiocatori.txt");
            if (myfile.is_open())
            {
                while (getline (myfile,line))
                {
                    abbinamenti->classifica->aggiungiGiocatore(new Giocatore(line));
                    creaStringaPerStampaClassifica((char*)line.c_str());
                }
                myfile.close();
            }
        }
        changeBehavior = false;
        SetWindowText(hAggiungiGiocatore, "Aggiungi Giocatore");

        break;
    case IDC_ABBINAMENTI:
        MessageBox(hwnd, "Gli Abbinamenti sono stati diocane!", "Ok!", MB_OK);
        abbinamenti->creaAbbinamentiPrimoTurno();

        std::cout << abbinamenti->matriceAbbinamenti[1][1].getNome();
        //SendMessage(hAbbinamenti, LB_ADDSTRING, 0, (LPARAM)abbinamenti->matriceAbbinamenti[0][0].getNome().c_str());
        SendMessage(hAbbinamenti, LB_ADDSTRING, 0, (LPARAM)"LPARAM");
        break;
    }

}

Giocatore trovaGiocatore(char passata[])
{
    for (int i=0; i<abbinamenti->classifica->getVectorSize(); i++)
    {
        if(lstrcmp(passata, abbinamenti->classifica->getAtIndex(i).getNome().c_str()) == 0)
            return abbinamenti->classifica->getAtIndex(i);
    }

}

void Dlg_OnClose(HWND hwnd)
{
    // Chiusura del dialogo
    EndDialog(hwnd,0);

}
