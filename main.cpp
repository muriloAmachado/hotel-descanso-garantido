#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include "cliente.h"
#include "funcionario.h"

void menu();
void menuCliente();
void menuFuncionario();
void menuQuartos();
void menuEstadia();
// void escreverFuncionario(const char *nome, const char *cargo, float salario) {
    
//     FILE *file = fopen("arquivos/funcionarios.txt", "a");
//     if (file == NULL) {
//         perror("Erro ao abrir o arquivo");
//         exit(EXIT_FAILURE);
//     }

//     fprintf(file, "Nome: %s\nCargo: %s\nSalário: %.2f\n\n", nome, cargo, salario);

//     fclose(file);
// }

// escreverFuncionario("João Silva", "Desenvolvedor", 3500.50);
// escreverFuncionario("Maria Souza", "Gerente", 5500.00);

int main() {

    menu();

}
void menu(){

    int option;
        cout << "----------------------" << endl;
        cout << "---------MENU---------" << endl;
        cout << "----------------------" << endl;

        cout << "1 - Clientes" << endl;
        cout << "2 - Funcionários" << endl;
        cout << "3 - Quartos" << endl;
        cout << "4 - Estadias" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha a opção: ";
        cin >> option;

        switch (option)
        {
        case 1:
            menuCliente();
            break;
        case 2:
            menuFuncionario();
            break;
        case 3:
            menuQuartos();
            break;
        case 4:
            menuEstadia();
            break;
        case 0:
            break;
        }
}

void menuCliente (){
    Cliente cliente;

    int optionMenuCliente;

    cout << "1 - Cadastrar novo cliente" << endl;
    cout << "2 - Pesquisar cliente" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opção: ";
    cin >> optionMenuCliente;

    switch (optionMenuCliente)
    {
    case 1:
        cliente.newClient();
        break;
    case 2:
        cout << "2kkkk" << endl; 
        break;
    case 9:
        return menu(); 
        break;
    }
}

void menuFuncionario (){
    Funcionario funcionario;

    int optionMenuFuncionario;

    cout << "1 - Cadastrar novo funcionario" << endl;
    cout << "2 - Pesquisar funcionario" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opção: ";

    cin >> optionMenuFuncionario;

    switch (optionMenuFuncionario)
    {
    case 1:
        funcionario.newFuncionario(); 
        break;
    case 2:
        cout << "2kkkk" << endl; 
        break;
    case 9:
        return menu(); 
        break;
    }
}

void menuQuartos (){
    int optionMenuQuartos;

    cout << "1 - Cadastrar novo quarto" << endl;
    cout << "2 - Pesquisar quarto" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opção: ";

    cin >> optionMenuQuartos;

    switch (optionMenuQuartos)
    {
    case 1:
        cout << "kkkk" << endl; 
        break;
    case 2:
        cout << "2kkkk" << endl; 
        break;
    case 9:
        return menu(); 
        break;
    }
}

void menuEstadia (){
    int optionMenuEstadia;

    cout << "1 - Cadastrar nova estadia" << endl;
    cout << "2 - Baixa em uma estadia" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opção: ";

    cin >> optionMenuEstadia;

    switch (optionMenuEstadia)
    {
    case 1:
        cout << "kkkk" << endl; 
        break;
    case 2:
        cout << "2kkkk" << endl; 
        break;
    case 9:
        return menu(); 
        break;
    }
}

