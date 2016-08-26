#include <string>

class Giocatore
{
    private:
        int iPartiteVinte, iPunteggio;
        std::string szListaMazzi, szNome;

    public:
        Giocatore()
        {
            iPartiteVinte = 0;
            iPunteggio = 0;
        }
        Giocatore(const std::string &stringapassata)
        {
            iPartiteVinte = 0;
            iPunteggio = 0;
            szNome = stringapassata;
            //szListaMazzi = szListaMazzi;
        }
        int getNumeroPartiteGiocate()
        {
            return iPartiteVinte;
        }
        void aggiungiVittoria()
        {
            iPartiteVinte++;
        }
        std::string getNome()
        {
            return szNome;
        }
};
