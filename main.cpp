#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include "cliente.h"
#include "funcionario.h"
#include "quartos.h"
#include "estadia.h"

void menu(int x);
void menuCliente();
void menuFuncionario();
void menuQuartos();
void menuEstadia();

int main() {
    int option;
        cout << "----------------------" << endl;
        cout << "---------MENU---------" << endl;
        cout << "----------------------" << endl;

        cout << "1 - Clientes" << endl;
        cout << "2 - Funcionarios" << endl;
        cout << "3 - Quartos" << endl;
        cout << "4 - Estadias" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha a opcao: ";
        cin >> option;
    menu(option);

    return 0;
}

void menu(int x){

        switch (x)
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
    cout << "3 - Pesquisar estadias do cliente" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opcao: ";
    cin >> optionMenuCliente;

    switch (optionMenuCliente){
    case 1:
        cliente.newClient();
        break;

    case 2:
        cliente.searchExists(cliente);
        break;
    case 3:
        cliente.estadiasDoCliente();
        break;
    case 9:
        return;
        break;
    }
}

void menuFuncionario (){
    Funcionario funcionario;

    int optionMenuFuncionario;

    cout << "1 - Cadastrar novo funcionario" << endl;
    cout << "2 - Pesquisar funcionario" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opcao: ";

    cin >> optionMenuFuncionario;

    switch (optionMenuFuncionario)
    {
    case 1:
        funcionario.newFuncionario(); 
        break;
    case 2:
        funcionario.searchExists(funcionario);
        break;
    case 9:
        return; 
        break;
    }
}

void menuQuartos (){
    Quarto quarto;

    int optionMenuQuartos;

    cout << "1 - Cadastrar novo quarto" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opcão: ";

    cin >> optionMenuQuartos;

    switch (optionMenuQuartos)
    {
    case 1:
        quarto.newQuarto(); 
        break;
    case 9:
        return; 
        break;
    }
}

void menuEstadia (){
    Estadia estadia;

    int optionMenuEstadia;

    cout << "1 - Cadastrar nova estadia" << endl;
    cout << "2 - Baixa em uma estadia" << endl;
    cout << "9 - Voltar" << endl;

    cout << "Escolha a opcao: ";

    cin >> optionMenuEstadia;

    switch (optionMenuEstadia)
    {
    case 1:
        estadia.newEstadia(); 
        break;
    case 2:
        cout << "Digite o ID da estadia: ";
        int idEstadia;
        cin >> idEstadia;
        estadia.checkout(idEstadia); 
        break;
    case 9:
        return; 
        break;
    }
}