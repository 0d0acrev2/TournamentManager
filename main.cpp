#include <iostream>

using namespace std;

#include "Abbinamenti.h"

int main()
{
    Abbinamenti abbinamenti;

    abbinamenti.creaAbbinamentiPrimoTurno();

    //DA FARE CON INTERFACCIA GRAFICA LETS TEST SOME SHIT
    cout << "Chi Ha vinto il primo turno? ";
    cout << abbinamenti.getCoppia(0) + "?";

    return 0;
}
