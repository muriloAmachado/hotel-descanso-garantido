#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include "estadia.h"

using namespace std;

std::tm stringToTm(const string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return tm;
}

bool isDateConflict(const std::tm& start1, const std::tm& end1, const std::tm& start2, const std::tm& end2) {
    std::time_t timeStart1 = mktime(const_cast<std::tm*>(&start1));
    std::time_t timeEnd1 = mktime(const_cast<std::tm*>(&end1));
    std::time_t timeStart2 = mktime(const_cast<std::tm*>(&start2));
    std::time_t timeEnd2 = mktime(const_cast<std::tm*>(&end2));

    return !(timeEnd1 < timeStart2 || timeStart1 > timeEnd2);
}

bool estadiaDisponivel(int numeroQuarto, const string& dataEntrada, const string& dataSaida) {
    ifstream file("arquivos/estadias.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    string line;
    int existingQuarto;
    string existingDataEntrada, existingDataSaida;
    std::tm tmDataEntrada = stringToTm(dataEntrada);
    std::tm tmDataSaida = stringToTm(dataSaida);

    while (getline(file, line)) {
        if (sscanf(line.c_str(), "Número do Quarto: %d", &existingQuarto) == 1) {
            getline(file, line);
            existingDataEntrada = line.substr(17);
            getline(file, line);
            existingDataSaida = line.substr(14);

            if (existingQuarto == numeroQuarto && isDateConflict(tmDataEntrada, tmDataSaida, stringToTm(existingDataEntrada), stringToTm(existingDataSaida))) {
                return false;
            }
        }
    }
    return true;
}

void atualizarContadorId(int novoId) {
    fstream file("arquivos/estadias.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo para leitura\n";
        exit(EXIT_FAILURE);
    }

    string linha;
    vector<string> linhas;

    getline(file, linha);
    linhas.push_back(to_string(novoId)); 
    
    while (getline(file, linha)) {
        linhas.push_back(linha);
    }
    file.close();

    file.open("arquivos/estadias.txt", ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita\n";
        exit(EXIT_FAILURE);
    }

    for (const auto& l : linhas) {
        file << l << "\n";
    }
}

void cadEstadia(int idCliente, int numeroQuarto, const string& dataEntrada, const string& dataSaida, int diarias) {
    ifstream file("arquivos/estadias.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    int idAtual;
    file >> idAtual;
    file.close();

    int novoId = idAtual + 1;

    ofstream appendFile("arquivos/estadias.txt", ios::app);
    if (!appendFile.is_open()) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    appendFile << "\nID Estadia: " << novoId << "\nID Cliente: " << idCliente << "\nNúmero do Quarto: " << numeroQuarto << "\nData de Entrada: " << dataEntrada << "\nData de Saída: " << dataSaida << "\nDiárias: " << diarias << "\n";
    appendFile.close();

    atualizarContadorId(novoId);
}