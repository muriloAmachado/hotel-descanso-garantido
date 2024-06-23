#ifndef PERSSOA_H
#define PERSSOA_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <string>

using namespace std;
class Person
{
    private:
        int codigo;
        string nome;
        string telefone;
    public:
        Person();
        int getCodigo();
        string getNome();
        string getTelefone();
        void setCodigo(int cod);
        void setNome(string& name);
        void setTelefone(string& tel);
};
#endif