#include "Classifica.h"

Classifica::Classifica()
{

}

int Classifica::getVectorSize()
{
    return vClassifica.size();
}

void Classifica::aggiungiGiocatore(Giocatore *giocatore)
{
    vClassifica.push_back (*giocatore);
}

Giocatore Classifica::getAtIndex(int index)
{
    return vClassifica.at(index);
}
