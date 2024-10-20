#ifndef SNIESCONTROLLER_H
#define SNIESCONTROLLER_H

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include "GestorCsv.h"
#include "ProgramaAcademico.h"


using std::string;
using std::map;
using std::list;
using std::vector;

class SNIESController {
private:
    GestorCsv gestorCsvObj;             
    string rutaProgramasCSV;            
    string rutaAdmitidos;               
    string rutaGraduados;               
    string rutaInscritos;               
    string rutaMatriculados;            
    string rutaMatriculadosPrimerSemestre; 
    string rutaOutput;                  

    map<int, ProgramaAcademico*> programasAcademicos; 
    vector<string> etiquetasColumnas;   

public:
    SNIESController(string &nuevaRutaProgramasCSV, string &nuevaRutaAdmitidos, string &nuevaRutaGraduados, 
                    string &nuevaRutaInscritos, string &nuevaRutaMatriculadosc, 
                    string &nuevaRutaMatriculadosPrimerSemestre, string &nuevaRutaOutput);

    ~SNIESController();

    void procesarDatosCsv(string &ano1, string &ano2);

    void buscarProgramas(bool flag, string &palabraClave, int idComparacion);

    void calcularDatosExtra(bool flag);

    void cargarDatos(const string& rutaProgramas, const string& ano1, const string& ano2);

    float calcularTasaGraduados(int codigoPrograma);

    void mostrarConsolidado(int codigoPrograma);
};

#endif // SNIESCONTROLLER_H
