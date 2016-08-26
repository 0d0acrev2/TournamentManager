#include "Giocatore.h"
#include <vector>

class Classifica
{
    private:
        std::vector<Giocatore> vClassifica;

    public:
        Classifica()
        {

        }
        int getVectorSize()
        {
            return vClassifica.size();
        }
        void aggiungiGiocatore(Giocatore giocatore, int index)
        {
            vClassifica.push_back (giocatore);
        }
        Giocatore getPrimo()
        {
            return vClassifica.at(0);
        }


};
