#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

void escreverFuncionario(const char *nome, const char *cargo, float salario) {
    
    FILE *file = fopen("arquivos/funcionarios.txt", "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Nome: %s\nCargo: %s\nSalário: %.2f\n\n", nome, cargo, salario);

    fclose(file);
}

int main() {

    papapa();
    
    escreverFuncionario("João Silva", "Desenvolvedor", 3500.50);
    escreverFuncionario("Maria Souza", "Gerente", 5500.00);

    printf("Funcionários escritos no arquivo com sucesso!\n");

    return 0;
}