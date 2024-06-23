#ifndef PERSSOA_H
#define PERSSOA_H

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
        void setNumQuarto();
        void setHospedes();
        void setDiaria();
        void setStatus();
};
#endif