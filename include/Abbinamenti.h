#ifndef ABBINAMENTI_H
#define ABBINAMENTI_H

#include "Giocatore.h"
#include "Classifica.h"

class Abbinamenti
{
private:
    Giocatore matriceAbbinamenti[255][2];
    void creaArrayConNumeriTuttiDiversi(int numeroGiocatori, int vettore[]);

public:
    Classifica *classifica;
    std::string getCoppia(int index);
    Abbinamenti();
    void creaAbbinamentiPrimoTurno();
};

#endif // ABBINAMENTI_H
