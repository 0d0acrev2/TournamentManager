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

public:
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

        //Crea Array con numeri tutti diversi
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
                    if(listaNumeriDiversi[k] == temp)
                        error = 1;
                }
            }
            while(error == 1);
            listaNumeriDiversi[i] = temp;
        }
        //Stampa di Prova e aggiunta delle stringhe nella matrice
        for(int i=0, int k=0; i<numeroGiocatori; i=i+2, k++)
        {
            std::cout << classifica.getAtIndex(listaNumeriDiversi[i]).getNome();
            std::cout << " VS ";
            std::cout << classifica.getAtIndex(listaNumeriDiversi[i+1]).getNome() << std::endl;

            //inserimento giocatori in matrice degli abbinamenti
            matriceDegliAbbinamenti[0][k] = classifica.getAtIndex(listaNumeriDiversi[i]);
            matriceDegliAbbinamenti[0][k+1] = classifica.getAtIndex(listaNumeriDiversi[i]);
        }

    }
};

#endif // ABBINAMENTI_H
