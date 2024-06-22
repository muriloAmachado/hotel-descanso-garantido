#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include "pessoa.h"

using namespace std;

Person::Person(){};

// ------- METODOS GETERS ----------- //
int Person::getCodigo(){
    return codigo;
}

string Person::getNome(){
    return nome;
}

string Person::getTelefone(){
    return telefone;
}
// ------- METODOS SETERS ----------- //

void Person::setCodigo(){
    int code;
    printf("Digite um codigo:");
    fflush(stdin);
    scanf("%i", &code);
    codigo = code;

    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
};

void Person::setNome(){
    string name;
    printf("Digite um nome:");
    getline(cin, name);
    nome = name;
};

void Person::setTelefone(){
    string tel;
    printf("Digite um telefone:");
    getline(cin, tel);
    telefone = tel;
};
