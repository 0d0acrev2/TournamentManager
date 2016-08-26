#ifndef ABBINAMENTI_H
#define ABBINAMENTI_H

#include "Classifica.cpp"

class Abbinamenti
{
    private:
        int matriceDegliAbbinamenti[255][255];
        Classifica classifica;
        void creaAbbinamenti();

    public:
        Abbinamenti()
        {
            classifica = Classifica();
        }
};

#endif // ABBINAMENTI_H
