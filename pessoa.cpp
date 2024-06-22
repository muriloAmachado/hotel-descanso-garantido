#include <iostream>
#include <string>
#include "pessoa.h"

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
        void setCodigo();
        string getNome();
        void setNome();
        string getTelefone();
        void setTelefone();
};