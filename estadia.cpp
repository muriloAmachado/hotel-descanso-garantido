#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include "estadia.h"

using namespace std;

const int monthDaysArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Estadia::Estadia(){};

string Estadia::getDataEntrada() {
    return dataEntrada;
}

string Estadia::getDataSaida() {
    return dataSaida;
}

int Estadia::getDiarias() {
    return diarias;
}

int Estadia::getIdCliente() {
    return idCliente;
}

int Estadia::getNumeroQuarto() {
    return numeroQuarto;
}

void Estadia::setDataEntrada(string& x) {
    dataEntrada = x;
}

void Estadia::setDataSaida(string& x) {
    dataSaida = x;
}

void Estadia::setDiarias(int x) {
    diarias = x;
}

void Estadia::setIdClient(int x) {
    idCliente = x;
}

void Estadia::setNumeroQuarto(int x) {
    numeroQuarto = x;
}

tm stringToTm(const string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> get_time(&tm, "%Y-%m-%d");
    return tm;
}

int yearsIntoDays(int years) {
    return years * 365;
}

int monthsIntoDays(int months) {
    return months * monthDaysArray[months - 1];
}

int dateIntoDays(string date) {
    // date format is "DD-MM-YYYY"
    int days = stoi(date.substr(0, 2));
    int months = stoi(date.substr(3, 2));
    int years = stoi(date.substr(6, 4));
    return days + monthsIntoDays(months) + yearsIntoDays(years);
}

bool availableDate(int numeroQuarto) {
    ifstream file("arquivos/estadias.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    string line;
    int existingQuarto;
    string existingDataEntrada, existingDataSaida;
    while (getline(file, line)) {
        if (sscanf(line.c_str(), "Número do Quarto: %d", &existingQuarto) == 1) {
            getline(file, line);
            existingDataEntrada = line.substr(17);
            getline(file, line);
            existingDataSaida = line.substr(14);

            if (existingQuarto == numeroQuarto && dateIntoDays(existingDataSaida) > dateIntoDays(existingDataEntrada)) {
                return false;
            }
        }
    }
    return true;
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

int acharQuarto(int numHospedes, string dataEntrada, string dataSaida) {
    ifstream file("arquivos/quartos.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    string line;
    int numeroQuarto, capacidade;
    while (getline(file, line)) {
        if (sscanf(line.c_str(), "Número: %d", &numeroQuarto) == 1) {
            getline(file, line);
            capacidade = line.find("Hóspedes: ") == 0 ? stoi(line.substr(10)) : 0;
            // printf("Capacidade: %d\n", capacidade);
            // printf("numHostedes: %d\n", numHospedes);
            // printf("estadiaDisponivel: %d\n", estadiaDisponivel(numeroQuarto, dataEntrada, dataSaida));
            if (capacidade >= numHospedes && estadiaDisponivel(numeroQuarto, dataEntrada, dataSaida)) {
                return numeroQuarto;
            }
        }
    }
    return -1;
}

void Estadia::newEstadia() {
    int numHospedes;
    cout << "Data de Entrada: ";
    cin >> dataEntrada;
    cout << "Data de Saída: ";
    cin >> dataSaida;
    cout << "Quantidade de Hóspedes: ";
    cin >> numHospedes;
    cout << "ID Cliente: ";
    cin >> idCliente;
    const int diarias = dateIntoDays(dataSaida) - dateIntoDays(dataEntrada);
    int quartoEncontrado = acharQuarto(numHospedes, dataEntrada, dataSaida);
    if(quartoEncontrado == 1) {
        cout << "Não há quartos disponíveis para a quantidade de hóspedes\n";
        return;
    }
    cadEstadia(idCliente, quartoEncontrado, dataEntrada, dataSaida, diarias);
    cout << "Você foi alocado em um quarto \n";

}

float valorDiaria(int idQuarto) {
    ifstream file("arquivos/quartos.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    printf("idQuarto: %d\n", idQuarto);

    string line;
    int numeroQuarto;
    float valorDiaria;
    while (getline(file, line)) {
        if (sscanf(line.c_str(), "Número: %d", &numeroQuarto) == 1) {
            getline(file, line);
            getline(file, line);
            valorDiaria = line.find("Diária: ") == 0 ? stof(line.substr(8)) : 0;
            if (numeroQuarto == idQuarto) {
                return valorDiaria;
            }
        }
    }
    return -1;
}

void pontosFidelidade(int idCliente, int diarias) {
    std::ifstream file("arquivos/clientes.txt");
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> lines;
    std::string line;
    bool modifyNextLine = false;
    int lineCount = 0;
    while (getline(file, line)) {
        int idClienteEncontrado;
        if (sscanf(line.c_str(), "Código: %d", &idClienteEncontrado) == 1) {
            if (idCliente == idClienteEncontrado) {
                modifyNextLine = true;
                lineCount = 0;
            }
        }
        if (modifyNextLine) {
            lineCount++;
            if (lineCount == 5) {
                int pontos = stoi(line.substr(8)) + diarias * 10;
                line = "Pontos: " + std::to_string(pontos);
                modifyNextLine = false;
            }
        }
        lines.push_back(line);
    }
    file.close();

    std::ofstream outFile("arquivos/clientes.txt");
    for (const auto& modifiedLine : lines) {
        outFile << modifiedLine << "\n";
    }
    outFile.close();
}

void Estadia::checkout(int idEstadia) {
    ifstream file("arquivos/estadias.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo\n";
        exit(EXIT_FAILURE);
    }

    string line;
    int idEstadiaEncontrada;
    int idCliente;
    int diarias;
    float conta;
    int idQuarto;
    while (getline(file, line)) {
        if (sscanf(line.c_str(), "ID Estadia: %d", &idEstadiaEncontrada) == 1) {
            getline(file, line);
            if (idEstadia == idEstadiaEncontrada) {
                idCliente = line.find("ID Cliente: ") == 0 ? stoi(line.substr(12)) : 0;
                getline(file, line);
                idQuarto = line.find("Número do Quarto: ") == 0 ? stoi(line.substr(18)) : 0;
                getline(file, line);
                getline(file, line);
                getline(file, line);
                diarias = line.find("Diárias: ") == 0 ? stoi(line.substr(9)) : 0;

                conta = diarias * valorDiaria(idQuarto);
                cout << "Valor a ser pago: R$" << conta << "\n";
                pontosFidelidade(idCliente, diarias);
                return;
            }
        }
    }
    cout << "Estadia não encontrada\n";
}