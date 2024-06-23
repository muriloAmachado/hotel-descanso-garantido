#include "pessoa.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string>

using namespace std;

class Cliente: public Person
{
    private:
        string endereco;
    public:
        Cliente();
        string getEndereco();
        void setEndereco(string& endereco);
        void newClient();
};
