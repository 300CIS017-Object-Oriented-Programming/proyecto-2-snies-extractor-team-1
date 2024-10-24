#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "programaAcademico.h"
#include <list>
#include "Constantes.h"

// Recomendación Linter: Se debe evitar el uso de using namespace en archivos de cabecera
using namespace std;

class GestorCsv {
public:
    GestorCsv() = default;
    vector<string> leerProgramasCsv(string &ruta);
    // Mantenimiento: Se puede mejorar la firma y nombre de los metodos para que sea más descriptiva
    vector<vector<string>> leerArchivoUnificado(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    int contarColumnas(string &rutaBase, string &ano);
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas);
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir);
    
};

#endif