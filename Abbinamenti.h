#ifndef ABBINAMENTI_H
#define ABBINAMENTI_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Classifica.cpp"

class Abbinamenti
{
private:
    Giocatore matriceAbbinamenti[255][2];
    Classifica classifica;
    void creaArrayConNumeriTuttiDiversi(int numeroGiocatori, int vettore[])
    {
        srand (time(NULL));
        for(int i=0; i<numeroGiocatori; i++)
        {
            int error = 0;
            int temp = 0;
            do             // controlla se già presente nell'array
            {
                temp = rand() % numeroGiocatori;
                error = 0;
                for(int k=0; k<=i; k++)
                {
                    if(vettore[k] == temp)
                        error = 1;
                }
            }
            while(error == 1);
            vettore[i] = temp;
        }
    }

public:
    std::string getCoppia(int index)
    {
        return matriceAbbinamenti[index][0].getNome() + " o " + matriceAbbinamenti[index][1].getNome();
    }
    Abbinamenti()
    {
        Giocatore giocatoreProva("0d0acre");
        Giocatore giocatoreProva2("Alassio");
        Giocatore giocatoreProva3("Marcello");
        Giocatore giocatoreProva4("Povia");

        classifica.aggiungiGiocatore(giocatoreProva);
        classifica.aggiungiGiocatore(giocatoreProva2);
        classifica.aggiungiGiocatore(giocatoreProva3);
        classifica.aggiungiGiocatore(giocatoreProva4);

    }
    void creaAbbinamentiPrimoTurno()
    {
        int numeroGiocatori = classifica.getVectorSize();
        int listaNumeriDiversi[numeroGiocatori];

        creaArrayConNumeriTuttiDiversi(numeroGiocatori, listaNumeriDiversi);

        //Creazione Abbinamenti Primo Turno ed aggiunta di essi alla matrice
        {
            int k=0;
            for(int i=0; i<numeroGiocatori; i=i+2, k++)
            {
                std::cout << classifica.getAtIndex(listaNumeriDiversi[i]).getNome();
                std::cout << " VS ";
                std::cout << classifica.getAtIndex(listaNumeriDiversi[i+1]).getNome() << std::endl;

                //inserimento giocatori in matrice degli abbinamenti
                matriceAbbinamenti[k][k] = classifica.getAtIndex(listaNumeriDiversi[i]);
                matriceAbbinamenti[k][k+1] = classifica.getAtIndex(listaNumeriDiversi[i+1]);
            }
        }
    }
};

#endif // ABBINAMENTI_H
