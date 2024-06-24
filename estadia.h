#ifndef ESTADIA_H
#define ESTADIA_H

#include "pessoa.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Estadia {
    private:
        string dataEntrada;
        string dataSaida;
        int diarias;
        int idCliente;
        int numeroQuarto;
    public:
        Estadia();
        string getDataEntrada();
        string getDataSaida();
        int getDiarias();
        int getIdCliente();
        int getNumeroQuarto();
        void setDataEntrada(string& x);
        void setDataSaida(string& x);
        void setDiarias(int x);
        void setIdClient(int x);
        void setNumeroQuarto(int x);
        void newEstadia();
        void checkout(int x);
};   
#endif