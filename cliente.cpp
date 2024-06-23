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
void Cliente::setEndereco(string& end){
    endereco = end;
};

// ------- ESCREVENDO NO ARQUIVO O NOVO CADASTRO ----------- //

void cadClient(int cod,const char *nome,const char *telefone,const char *endereco){
    FILE *file = fopen("arquivos/clientes.txt", "a");
    if (file == NULL) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Código: %i\nNome: %s\nTelefone: %s\nEndereço: %s\n\n", cod, nome, telefone, endereco);
    
    fclose(file);
};

// ------- CHAMADA DE MÉTODOS PARA GRAVAR OS DADOS DO NOVO CLIENTE ---------- //
void Cliente::newClient(){

    int cod;
    string name, tel, end;

    cout << "Digite o código do cliente: ";
    cin >> cod;
    cin.ignore(); // Ignorar o '\n' restante no buffer de entrada
    setCodigo(cod);

    cout << "Digite o nome do cliente: ";
    getline(cin, name);
    setNome(name);

    cout << "Digite o telefone do cliente: ";
    getline(cin, tel);
    setTelefone(tel);

    cout << "Digite o endereço do cliente: ";
    getline(cin, end);
    setEndereco(end);

    cadClient(cod, name.c_str(), tel.c_str(), end.c_str());
};
