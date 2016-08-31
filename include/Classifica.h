#ifndef CLASSIFICA_H
#define CLASSIFICA_H

#include <vector>
#include <Giocatore.h>

class Classifica
{
public:
    std::vector<Giocatore> vClassifica;
    Classifica();
    int getVectorSize();
    void aggiungiGiocatore(Giocatore *giocatore);
    Giocatore getAtIndex(int index);
};

#endif // CLASSIFICA_H
