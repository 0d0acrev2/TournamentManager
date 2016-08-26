#ifndef GIOCATORE_H_INCLUDED
#define GIOCATORE_H_INCLUDED

#include <string>

class Giocatore
{
    private:
        int iPartiteGiocate, iPartiteVinte, iPuntiTotali;
        std::string szListaMazzi, szNome;

    public:
        int getPartiteGiocate()
        {
            return iPartiteGiocate;
        }
};

#endif // GIOCATORE_H_INCLUDED
