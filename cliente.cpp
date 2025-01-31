#include <iostream>
#include <string>
#include <fstream>
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

int Cliente::getPontos(){
    return pontos;
}

// ------- METODOS SETERS ----------- //
void Cliente::setEndereco(string& end){
    endereco = end;
};

void Cliente::setPoints(int x){
    pontos = x;
};

// ------- ESCREVENDO NO ARQUIVO O NOVO CADASTRO ----------- //

void cadClient(int cod,const char *nome,const char *telefone,const char *endereco, int pontos){
    FILE *file = fopen("arquivos/clientes.txt", "a");
    if (file == NULL) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Código: %i\nNome: %s\nTelefone: %s\nEndereço: %s\nPontos: %d\n\n", cod, nome, telefone, endereco, pontos);
    
    fclose(file);
};

// ------- VERIFICAR CÓDIGO ----------- //
bool clientExists(int cod) {
    FILE *file = fopen("arquivos/clientes.txt", "r");
    if (file == NULL) {
        return false;
    }
    int existingCod;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "Código: %d", &existingCod) == 1) {
            if (existingCod == cod) {
                fclose(file);
                return true;
            }
        }
    }
    fclose(file);
    return false;
}

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

    if(clientExists(cod) == true){
        cout << "Já existe um cliente com este código" << endl;
        newClient();
    }
    else{
        cadClient(cod, name.c_str(), tel.c_str(), end.c_str(), 0);
    };
};

// ------- PESQUISAR CLIENTE ---------- //
bool Cliente::searchExists(Cliente& clienteEncontrado) {
     
     int code;

     cout << "Digite o código do cliente que deseja encontrar: ";
     cin >> code;

    ifstream file("arquivos/clientes.txt");
    if (!file.is_open()) {
        cerr << "Não foi possível abrir o arquivo clientes.txt\n";
        return false;
    }

    string line;
    int cod;
    string nome, telefone, endereco;

    while (getline(file, line)) {
        if (line.find("Código: ") == 0) {
            sscanf(line.c_str(), "Código: %d", &cod);
            if (cod == code) {
                if (getline(file, line) && line.find("Nome: ") == 0) {
                    nome = line.substr(6); // Ignora "Nome: "
                }
                if (getline(file, line) && line.find("Telefone: ") == 0) {
                    telefone = line.substr(10); // Ignora "Telefone: " 
                }
                if (getline(file, line) && line.find("Endereço: ") == 0) {
                    endereco = line.substr(10); // Ignora "Endereço: "
                }
                if (getline(file, line) && line.find("Pontos: ") == 0) {
                    clienteEncontrado.setPoints(stoi(line.substr(8))); // Ignora "Pontos: "
                }

                clienteEncontrado.setCodigo(cod);
                clienteEncontrado.setNome(nome);
                clienteEncontrado.setTelefone(telefone);
                clienteEncontrado.setEndereco(endereco);
                clienteEncontrado.setPoints(0);

                cout << "Cliente encontrado:\n";
                cout << "Código: " << clienteEncontrado.getCodigo() << "\n";
                cout << "Nome: " << clienteEncontrado.getNome() << "\n";
                cout << "Telefone: " << clienteEncontrado.getTelefone() << "\n";
                cout << "Endereço: " << clienteEncontrado.getEndereco() << "\n";
                cout << "Pontos: " << clienteEncontrado.getPontos() << "\n";

                file.close();
                return true;
            }
        }
    }

    file.close();
    return false; // Cliente não encontrado
}
// Pesquisar Estadias do Cliente

void Cliente::estadiasDoCliente() {
    int code;

    cout << "Digite o código do cliente que deseja encontrar: ";
    cin >> code;

    ifstream file("arquivos/estadias.txt");
    if (!file.is_open()) {
        cerr << "Não foi possível abrir o arquivo estadias.txt\n";
        return;
    }

    string line;
    int codCliente, codQuarto, diarias;
    string dataEntrada, dataSaida;

    while (getline(file, line)) {
        if (line.find("ID Cliente: ") == 0) {
            sscanf(line.c_str(), "ID Cliente: %d", &codCliente);
            if (codCliente == code) {
                if (getline(file, line) && line.find("Número do Quarto: ") == 0) {
                    sscanf(line.c_str(), "Número do Quarto: %d", &codQuarto);
                }
                if (getline(file, line) && line.find("Data de Entrada: ") == 0) {
                    dataEntrada = line.substr(17); // Ignora "Data de Entrada: "
                }
                if (getline(file, line) && line.find("Data de Saída: ") == 0) {
                    dataSaida = line.substr(15); // Ignora "Data de Saída: "
                }
                if (getline(file, line) && line.find("Diárias: ") == 0) {
                    sscanf(line.c_str(), "Diárias: %d", &diarias);
                }

                cout << "Estadia encontrada:\n";
                cout << "ID Cliente: " << codCliente << "\n";
                cout << "Número do Quarto: " << codQuarto << "\n";
                cout << "Data de Entrada: " << dataEntrada << "\n";
                cout << "Data de Saída: " << dataSaida << "\n";
                cout << "Diárias: " << diarias << "\n\n";
            }
        }
    }

    file.close();
}