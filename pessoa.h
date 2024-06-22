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
        void setCodigo();
        void setNome();
        void setTelefone();
};