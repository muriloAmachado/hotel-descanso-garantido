#ifndef QUARTOS_H
#define QUARTOS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <string>

using namespace std;
class Quarto
{
    private:
        int numQuarto;
        int hospedes;
        float diaria;
        bool status;
    public:
        Quarto();
        int getNumQuarto();
        int getHospedes();
        float getDiaria();
        bool getStatus();
        //-------------------//
        void setNumQuarto(int numero);
        void setHospedes(int capacidade);
        void setDiaria(float valorDiaria);
        void setStatus(bool x);
        void newQuarto();
};
#endif