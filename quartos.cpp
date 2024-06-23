#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "quartos.h"

using namespace std;

Quarto::Quarto(){};

//-----------get----------//
int Quarto::getNumQuarto(){
    return numQuarto;
}
int Quarto::getHospedes(){
    return hospedes;
}
float Quarto::getDiaria(){
    return diaria;
}
bool Quarto::getStatus(){
    return status;
}
//-----------set----------//
void Quarto::setNumQuarto(){}