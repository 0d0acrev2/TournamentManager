#include <Abbinamenti.h>

#include <time.h>
#include <stdlib.h>
#include <iostream>

void Abbinamenti::creaArrayConNumeriTuttiDiversi(int numeroGiocatori, int vettore[])
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

std::string Abbinamenti::getCoppia(int index)
{
    return matriceAbbinamenti[index][0].getNome() + " o " + matriceAbbinamenti[index][1].getNome();
}

Abbinamenti::Abbinamenti()
{
    classifica = new Classifica();
}

void Abbinamenti::creaAbbinamentiPrimoTurno()
{
    int numeroGiocatori = classifica->getVectorSize();
    int listaNumeriDiversi[numeroGiocatori];

    creaArrayConNumeriTuttiDiversi(numeroGiocatori, listaNumeriDiversi);

    //Creazione Abbinamenti Primo Turno ed aggiunta di essi alla matrice
    {
        int k=0;
        for(int i=0; i<numeroGiocatori; i=i+2, k++)
        {
            std::cout << classifica->getAtIndex(listaNumeriDiversi[i]).getNome();
            std::cout << " VS ";
            std::cout << classifica->getAtIndex(listaNumeriDiversi[i+1]).getNome() << std::endl;

            //inserimento giocatori in matrice degli abbinamenti
            matriceAbbinamenti[k][k] = classifica->getAtIndex(listaNumeriDiversi[i]);
            matriceAbbinamenti[k][k+1] = classifica->getAtIndex(listaNumeriDiversi[i+1]);
        }
    }
}

