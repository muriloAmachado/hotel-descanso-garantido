#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include "cliente.h"

// ------- INICIALIZAR CONSTRUTOR ----------- //
Cliente::Cliente(){};

// ------- METODOS GETERS ----------- //
string Cliente::getEndereco(){
    return endereco;
}

// ------- METODOS SETERS ----------- //
void Cliente::setEndereco(){
    string x;
    cout << "Endereço do cliente:" << endl;
    getline(cin, x);
    endereco = x;
};