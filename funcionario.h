#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string>

using namespace std;
class Funcionario: public Person
{
    private:
        string cargo;
        float salario;
    public:
        Funcionario();
        string getCargo();
        float getSalario();
        void setCargo(string& x);
        void setSalario(float x);
        void newFuncionario();
        bool searchExists(Funcionario& funcionarioEncontrado);
};
#endif