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
    Giocatore(char passato[]);
    int getNumeroPartiteVinte();
    int getPunteggio();
    void aggiungiVittoria();
    std::string getNome();
};

#endif // GIOCATORE_H
