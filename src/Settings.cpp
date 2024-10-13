//
// Created by User on 13/10/2024.
//
#include "Settings.h"
#include <string>

using namespace std;


// Inicialización de las variables estáticas
string Settings::BASE_PATH = "C:/SNIES_EXTRACTOR/inputs/";
string Settings::PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH + "programas.csv";
string Settings::ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
string Settings::MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
string Settings::INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
string Settings::DELIMITADOR = ";";

string Settings::GRADUADOS_FILE_PATH = BASE_PATH + "graduados";
string Settings::INFORME_FILE_PATH = BASE_PATH + "informe.txt";
string Settings::LOGS_FILE_PATH = "C:/SNIES_EXTRACTOR/logs/log.txt";

// Implementación de los métodos setters
void Settings::setBasePath(const string& newPath) {
    BASE_PATH = newPath;
    // Actualiza las rutas que dependen de BASE_PATH
    PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH + "programas.csv";
    ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
    MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
    INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
    GRADUADOS_FILE_PATH = BASE_PATH + "graduados";
    INFORME_FILE_PATH = BASE_PATH + "informe.txt";
    LOGS_FILE_PATH = BASE_PATH + "logs/log.txt"; // Actualiza la ruta de logs
}

void Settings::setDelimitador(const std::string& newDelimitador) {
    DELIMITADOR = newDelimitador; // Modificar el delimitador
}

int main() {
    // Cambiar la ruta base
    Settings::setBasePath("D:/NUEVA_RUTA/inputs/");

    // Cambiar el delimitador
    Settings::setDelimitador(",");

    // Acceder a las rutas actualizadas
    std::cout << "Nueva ruta de programas: " << Settings::PROGRAMAS_FILTRAR_FILE_PATH << std::endl;

    return 0;
}
