#include "Giocatore.h"

class Classifica
{
    private:
        Giocatore arrClassifica[255];

    public:
        Classifica()
        {

        }
        Giocatore getPrimo()
        {
            return arrClassifica[0];
        }

        void aggiungiGiocatore(Giocatore giocatore, int index)
        {
            arrClassifica[index] = giocatore;
        }
};
