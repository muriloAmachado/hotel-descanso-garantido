#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include "pessoa.h"

using namespace std;
// ------- INICIALIZAR CONSTRUTOR ----------- //
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
void Person::setCodigo(int cod){
    codigo = cod;
};

void Person::setNome(string& name){
    nome = name;
};

void Person::setTelefone(string& tel){
    telefone = tel;
};
