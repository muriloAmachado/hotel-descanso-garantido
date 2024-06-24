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
        int pontos;
    public:
        Cliente();
        string getEndereco();
        int getPontos();
        void setEndereco(string& endereco);
        void newClient();
        bool searchExists(Cliente& clienteEncontrado);
        void setPoints(int x);
};
