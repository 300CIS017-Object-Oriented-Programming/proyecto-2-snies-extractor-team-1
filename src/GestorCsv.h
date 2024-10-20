#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "programaAcademico.h"
#include <list>

// Recomendación Linter: Se debe evitar el uso de using namespace en archivos de cabecera
using std::string;
using std::vector;
using std::map;
using std::list;
using std::stringstream;

class GestorCsv {
public:
    GestorCsv() = default;
    vector<int> leerProgramasCsv(string &ruta);
    // Mantenimiento: Se puede mejorar la firma y nombre de los metodos para que sea más descriptiva
    vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas);
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir);
};

#endif