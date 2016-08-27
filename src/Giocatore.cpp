#include "Giocatore.h"

Giocatore::Giocatore()
{
    iPartiteVinte = 0;
    iPunteggio = 0;
}
Giocatore::Giocatore(const std::string &stringapassata)
{
    iPartiteVinte = 0;
    iPunteggio = 0;
    szNome = stringapassata;
    //szListaMazzi = szListaMazzi;
}
int Giocatore::getNumeroPartiteVinte()
{
    return iPartiteVinte;
}
void Giocatore::aggiungiVittoria()
{
    iPartiteVinte++;
    iPunteggio = iPunteggio + 1;
}
std::string Giocatore::getNome()
{
    return szNome;
}

