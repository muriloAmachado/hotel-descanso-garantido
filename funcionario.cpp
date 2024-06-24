#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <fstream>
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
void Funcionario::setCargo(string& x){
    cargo = x;
};

void Funcionario::setSalario(float x){
    salario = x;
};

// ------- ESCREVENDO NO ARQUIVO O NOVO CADASTRO ----------- //

void cadFuncionario(int cod,const char *nome,const char *telefone,const char *cargo, float salario){
    FILE *file = fopen("arquivos/funcionarios.txt", "a");
    if (file == NULL) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Código: %i\nNome: %s\nTelefone: %s\nCargo: %s\nSalario: %.2f\n\n", cod, nome, telefone, cargo, salario);
    
    fclose(file);
};

// ------- VERIFICAR CÓDIGO ----------- //
bool functionaryExists(int cod) {
    FILE *file = fopen("arquivos/funcionarios.txt", "r");
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
void Funcionario::newFuncionario(){

    int cod;
    string name, tel, cargo;
    float salario;

    cout << "Digite o código do funcionário: ";
    cin >> cod;
    cin.ignore(); // Ignorar o '\n' restante no buffer de entrada
    setCodigo(cod);

    cout << "Digite o nome do funcionário: ";
    getline(cin, name);
    setNome(name);

    cout << "Digite o telefone do funcionário: ";
    getline(cin, tel);
    setTelefone(tel);

    cout << "Digite o cargo do funcionário: ";
    getline(cin, cargo);
    setCargo(cargo);

    cout << "Digite o salário do funcionário: ";
    cin >> salario;
    cin.ignore();
    setSalario(salario);

    if(functionaryExists(cod) == true){
        cout << "Já existe um funcionario com este código" << endl;
        newFuncionario();
    }
    else{
        cadFuncionario(cod, name.c_str(), tel.c_str(), cargo.c_str(), salario);
    };
};

// ------- PESQUISAR CLIENTE ---------- //
bool Funcionario::searchExists(Funcionario& funcionarioEncontrado) {
     
     int code;

     cout << "Digite o código do cliente que deseja encontrar: ";
     cin >> code;

    ifstream file("arquivos/funcionarios.txt");
    if (!file.is_open()) {
        cerr << "Não foi possível abrir o arquivo clientes.txt\n";
        return false;
    }

    string line;
    int cod;
    float salario;
    string nome, telefone, cargo;

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
                if (getline(file, line) && line.find("Cargo: ") == 0) {
                    cargo = line.substr(7); // Ignora "Cargo: "
                }
                if (getline(file, line) && line.find("Salario: ") == 0) {
                    sscanf(line.c_str(), "Salario: %f", &salario);
                }

                funcionarioEncontrado.setCodigo(cod);
                funcionarioEncontrado.setNome(nome);
                funcionarioEncontrado.setTelefone(telefone);
                funcionarioEncontrado.setCargo(cargo);
                funcionarioEncontrado.setSalario(salario);

                cout << "Funcionário encontrado:\n";
                cout << "Código: " << funcionarioEncontrado.getCodigo() << "\n";
                cout << "Nome: " << funcionarioEncontrado.getNome() << "\n";
                cout << "Telefone: " << funcionarioEncontrado.getTelefone() << "\n";
                cout << "Cargo: " << funcionarioEncontrado.getCargo() << "\n";
                cout << "Salario: " << funcionarioEncontrado.getSalario() << "\n";

                file.close();
                return true;
            }
        }
    }

    file.close();
    return false; // Cliente não encontrado
}
