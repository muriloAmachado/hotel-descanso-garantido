#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include "cliente.h"


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

    Cliente a;
    a.setCodigo();
    a.setNome();
    a.setTelefone();
    a.setEndereco();
    printf("Codigo: %i\nNome: %s\nTelefone: %s\nEndereço: %s\n", a.getCodigo(), a.getNome().c_str(), a.getTelefone().c_str(),  a.getEndereco().c_str());

    return 0;
}