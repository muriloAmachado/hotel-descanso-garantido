#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "quartos.h"

using namespace std;

Quarto::Quarto(){};

//-----------get----------//
int Quarto::getNumQuarto(){
    return numQuarto;
}
int Quarto::getHospedes(){
    return hospedes;
}
float Quarto::getDiaria(){
    return diaria;
}
bool Quarto::getStatus(){
    return status;
}
//-----------set----------//
void Quarto::setNumQuarto(int numero){
    numQuarto = numero;
}
void Quarto::setHospedes(int capacidade){
    hospedes = capacidade;
}
void Quarto::setDiaria(float valorDiaria){
    diaria = valorDiaria;
}
void Quarto::setStatus(bool x){
    status = x;
}
//--------------gravar arquivo quarto---------//
void cadQuarto(int numero, int capacidade, float valorDiaria, bool x){
    string statusQuarto;
    FILE *file = fopen("arquivos/quartos.txt", "a");
    if (file == NULL) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }
    if (x == true){
        statusQuarto = "Disponivel";
    } else {
        statusQuarto = "Ocupado";
    }
    fprintf(file, "Número: %i\nHóspedes: %i\nDiária: %.2f\nStatus: %s\n", numero, capacidade, valorDiaria, statusQuarto.c_str());
    
    fclose(file);
};
//---------verifica se o quarto ja existe--------//
bool numQuartoExiste(int numero) {
    FILE *file = fopen("arquivos/quartos.txt", "r");
    if (file == NULL) {
        return false;
    }
    int existingNum;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "Número: %d", &existingNum) == 1) {
            if (existingNum == numero) {
                fclose(file);
                return true;
            }
        }
    }
    fclose(file);
    return false;
}
//-------gravar dados quarto---------//
void Quarto::newQuarto(){

    int numero, capacidade;
    float valorDiaria;
    bool status = true;

    cout << "Digite o numero do quarto: ";
    cin >> numero;
    cin.ignore();
    setNumQuarto(numero);

    cout << "Digite a capacidade do quarto: ";
    cin >> capacidade;
    cin.ignore();
    setHospedes(capacidade);

    cout << "Digite o valor da diaria: ";
    cin >> valorDiaria;
    cin.ignore();
    setDiaria(valorDiaria);

    setStatus(status);

    if(numQuartoExiste(numero) == true){
        cout << "Já existe um quarto com esse numero" << endl;
        newQuarto();
    } else { 
        cadQuarto(numero, capacidade, valorDiaria, status);
    }
}
