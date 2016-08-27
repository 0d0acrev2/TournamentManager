#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <string>

class Giocatore
{
private:
    int iPartiteVinte, iPunteggio;
    std::string szListaMazzi, szNome;

public:
    Giocatore();
    Giocatore(const std::string &stringapassata);
    int getNumeroPartiteVinte();
    void aggiungiVittoria();
    std::string getNome();
};

#endif // GIOCATORE_H
