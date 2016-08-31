#ifndef ABBINAMENTI_H
#define ABBINAMENTI_H

#include "Giocatore.h"
#include "Classifica.h"

class Abbinamenti
{
private:
    void creaArrayConNumeriTuttiDiversi(int numeroGiocatori, int vettore[]);

public:
    Giocatore matriceAbbinamenti[255][2];
    Classifica *classifica;
    std::string getCoppia(int index);
    Abbinamenti();
    void creaAbbinamentiPrimoTurno();
};

#endif // ABBINAMENTI_H
