#include "Giocatore.cpp"
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
        void aggiungiGiocatore(Giocatore &giocatore)
        {
            vClassifica.push_back (giocatore);
        }
        Giocatore getAtIndex(int index)
        {
            return vClassifica.at(index);
        }

};
