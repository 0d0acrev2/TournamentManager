#include "Giocatore.h"

#include <sstream>

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
Giocatore::Giocatore(char passato[])
{
    iPartiteVinte = 0;
    iPunteggio = 0;
    std::stringstream stringStreamAppoggio;
    stringStreamAppoggio << passato;
    stringStreamAppoggio >> szNome;
}

int Giocatore::getNumeroPartiteVinte()
{
    return iPartiteVinte;
}
int Giocatore::getPunteggio()
{
    return iPunteggio;
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

