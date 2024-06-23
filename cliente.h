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
        // void cadClient(int cod, const char *nome,const char *telefone,const char *endereco);
    public:
        Cliente();
        string getEndereco();
        void setEndereco(string& endereco);
        void newClient();
};
