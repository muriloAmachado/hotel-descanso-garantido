#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include "funcionario.h"

// ------- INICIALIZAR CONSTRUTOR ----------- //
Funcionario::Funcionario(){};

// ------- METODOS GETERS ----------- //
string Funcionario::getCargo(){
    return cargo;
}

float Funcionario::getSalario(){
    return salario;
}

// ------- METODOS SETERS ----------- //
void Funcionario::setCargo(){
   string x;
    printf("Cargo do funcionario:");
    getline(cin, x);
    cargo = x;
};

void Funcionario::setSalario(){
    float teste;
    printf("Salário do funcionário:");
    fflush(stdin);
    scanf("%f", &teste);
    salario = teste;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
};
