#include "SNIESController.h"

using namespace std;

SNIESController::SNIESController(){};
SNIESController::SNIESController(string &nuevaRutaProgramasCSV, string &nuevaRutaAdmitidos, string &nuevaRutaGraduados, string &nuevaRutaInscritos, string &nuevaRutaMatriculadosc, string &nuevaRutaMatriculadosPrimerSemestre, string &nuevaRutaOutput)
{
    // Inicialización de rutas de archivos
    rutaProgramasCSV = nuevaRutaProgramasCSV;
    rutaAdmitidos = nuevaRutaAdmitidos;
    rutaGraduados = nuevaRutaGraduados;
    rutaInscritos = nuevaRutaInscritos;
    rutaMatriculados = nuevaRutaMatriculadosc;
    rutaMatriculadosPrimerSemestre = nuevaRutaMatriculadosPrimerSemestre;
    rutaOutput = nuevaRutaOutput;
}

// Destructor de SNIESController
SNIESController::~SNIESController()
{
    for (auto &pair : programasAcademicos)
    {
        delete pair.second;
    }
}

// Método para procesar los datos CSV
void SNIESController::procesarDatosCsv(string &ano1, string &ano2)
{
    vector<int> codigosSnies;
    vector<vector<string>> programasAcademicosVector;
    int columna;

    // Lectura de los códigos SNIES
    vector<string> codigosSniesStr = gestorCsvObj.leerProgramasCsv(rutaProgramasCSV);
    codigosSnies.clear();

    for (const auto &codigo : codigosSniesStr)
    {
        try
        {
            codigosSnies.push_back(stoi(codigo));
        }
        catch (const std::invalid_argument &e)
        {
            cerr << "Error de conversión: '" << codigo << "' no es un número válido." << endl;
        }
    }

    // Leer datos del primer anio
    programasAcademicosVector = gestorCsvObj.leerArchivoUnificado(rutaAdmitidos, ano1, codigosSnies, 13);
    etiquetasColumnas = programasAcademicosVector[0];

    for (int i = 1; i < programasAcademicosVector.size(); i += 4)
    {
        ProgramaAcademico *programaAcademico = new ProgramaAcademico();
        programaAcademico->setCodigoDeLaInstitucion(stoi(programasAcademicosVector[i][0]));
        programaAcademico->setIesPadre(stoi(programasAcademicosVector[i][1]));
        programaAcademico->setInstitucionDeEducacionSuperiorIes(programasAcademicosVector[i][2]);
        programaAcademico->setPrincipalOSeccional(programasAcademicosVector[i][3]);
        programaAcademico->setIdSectorIes(stoi(programasAcademicosVector[i][4]));
        programaAcademico->setSectorIes(programasAcademicosVector[i][5]);
        programaAcademico->setIdCaracter(stoi(programasAcademicosVector[i][6]));
        programaAcademico->setCaracterIes(programasAcademicosVector[i][7]);
        programaAcademico->setCodigoDelDepartamentoIes(stoi(programasAcademicosVector[i][8]));
        programaAcademico->setDepartamentoDeDomicilioDeLaIes(programasAcademicosVector[i][9]);
        programaAcademico->setCodigoDelMunicipioIes(stoi(programasAcademicosVector[i][10]));
        programaAcademico->setMunicipioDeDomicilioDeLaIes(programasAcademicosVector[i][11]);
        programaAcademico->setCodigoSniesDelPrograma(stoi(programasAcademicosVector[i][12]));
        programaAcademico->setProgramaAcademico(programasAcademicosVector[i][13]);
        programaAcademico->setIdNivelAcademico(stoi(programasAcademicosVector[i][14]));
        programaAcademico->setNivelAcademico(programasAcademicosVector[i][15]);
        programaAcademico->setIdNivelDeFormacion(stoi(programasAcademicosVector[i][16]));
        programaAcademico->setNivelDeFormacion(programasAcademicosVector[i][17]);
        programaAcademico->setIdMetodologia(stoi(programasAcademicosVector[i][18]));
        programaAcademico->setMetodologia(programasAcademicosVector[i][19]);
        programaAcademico->setIdArea(stoi(programasAcademicosVector[i][20]));
        programaAcademico->setAreaDeConocimiento(programasAcademicosVector[i][21]);
        programaAcademico->setIdNucleo(stoi(programasAcademicosVector[i][22]));
        programaAcademico->setNucleoBasicoDelConocimientoNbc(programasAcademicosVector[i][23]);
        programaAcademico->setIdCineCampoAmplio(stoi(programasAcademicosVector[i][24]));
        programaAcademico->setDescCineCampoAmplio(programasAcademicosVector[i][25]);
        programaAcademico->setIdCineCampoEspecifico(stoi(programasAcademicosVector[i][26]));
        programaAcademico->setDescCineCampoEspecifico(programasAcademicosVector[i][27]);
        programaAcademico->setIdCineCodigoDetallado(stoi(programasAcademicosVector[i][28]));
        programaAcademico->setDescCineCodigoDetallado(programasAcademicosVector[i][29]);
        programaAcademico->setCodigoDelDepartamentoPrograma(stoi(programasAcademicosVector[i][30]));
        programaAcademico->setDepartamentoDeOfertaDelPrograma(programasAcademicosVector[i][31]);
        programaAcademico->setCodigoDelMunicipioPrograma(stoi(programasAcademicosVector[i][32]));
        programaAcademico->setMunicipioDeOfertaDelPrograma(programasAcademicosVector[i][33]);

        Consolidado *consolidado[4];
        for (int m = 0; m < 4; ++m)
        {
            consolidado[m] = new Consolidado();
            consolidado[m]->setIdSexo(stoi(programasAcademicosVector[i + m][34]));
            consolidado[m]->setSexo(programasAcademicosVector[i + m][35]);
            consolidado[m]->setAno(stoi(programasAcademicosVector[i + m][36]));
            consolidado[m]->setSemestre(stoi(programasAcademicosVector[i + m][37]));
            consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[i + m][38]));
            programaAcademico->setConsolidado(consolidado[m], m);
        }

        programasAcademicos.emplace(programaAcademico->getCodigoSniesDelPrograma(), programaAcademico);
    }

    // Leer datos del segundo anio
    programasAcademicosVector = gestorCsvObj.leerArchivoUnificado(rutaAdmitidos, ano2, codigosSnies, 13);

    for (int j = 0; j < programasAcademicosVector.size(); j += 4)
    {
        auto it = programasAcademicos.find(stoi(programasAcademicosVector[j][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            Consolidado *consolidado[4];
            for (int m = 0; m < 4; ++m)
            {
                consolidado[m] = new Consolidado();
                consolidado[m]->setIdSexo(stoi(programasAcademicosVector[j + m][1]));
                consolidado[m]->setSexo(programasAcademicosVector[j + m][2]);
                consolidado[m]->setAno(stoi(programasAcademicosVector[j + m][3]));
                consolidado[m]->setSemestre(stoi(programasAcademicosVector[j + m][4]));
                consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[j + m][5]));
                programa->setConsolidado(consolidado[m], m + 4);
            }
        }
    }

    // Continuacion de la lectura
    programasAcademicosVector = gestorCsvObj.leerArchivoUnificado(rutaGraduados, ano1, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        auto it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setGraduados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    // Implementación para otros archivos
    programasAcademicosVector = gestorCsvObj.leerArchivoUnificado(rutaInscritos, ano1, codigosSnies, 12);
    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        auto it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setInscritos(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    bool archivoCreado = gestorCsvObj.crearArchivo(rutaOutput, programasAcademicos, etiquetasColumnas);
}

void SNIESController::buscarProgramas(bool flag, string &palabraClave, int idComparacion)
{
    list<ProgramaAcademico *> listaProgramas;
    for (auto it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        ProgramaAcademico *programa = it->second;
        string nombre = programa->getProgramaAcademico();
        int id = programa->getIdNivelDeFormacion();
        if (nombre.find(palabraClave) != string::npos && id == idComparacion)
        {
            listaProgramas.push_back(programa);
            cout << programa->getCodigoSniesDelPrograma() << ";" << programa->getProgramaAcademico() << ";" << programa->getCodigoDeLaInstitucion() << ";" << programa->getInstitucionDeEducacionSuperiorIes() << ";" << programa->getMetodologia() << endl;
        }
    }

    if (flag)
    {
        bool creado = gestorCsvObj.crearArchivoBuscados(rutaOutput, listaProgramas, etiquetasColumnas);
    }
}

// Método para cargar datos
void SNIESController::cargarDatos(string &rutaProgramas, string &ano1, string &ano2) {
    // Leer los códigos SNIES como vector de strings
    vector<string> codigosSniesStr = gestorCsvObj.leerProgramasCsv(rutaProgramas);
    vector<int> codigosSnies; // Vector para almacenar los códigos SNIES convertidos a enteros

    // Convertir cada string del vector de códigos a enteros
    for (const auto &codigoStr : codigosSniesStr) {
        try {
            int codigo = std::stoi(codigoStr); // Convertir el string a entero
            codigosSnies.push_back(codigo); // Agregar al vector de enteros
        } catch (const std::invalid_argument &e) {
            std::cerr << "Error de conversión: '" << codigoStr << "' no es un número válido." << std::endl;
        }
    }

    // Lectura de datos del primer anio usando leerArchivoUnificado
    vector<vector<string>> programasData = gestorCsvObj.leerArchivoUnificado(rutaProgramas, ano1, codigosSnies, 13);

    // Identificar posiciones de las columnas a partir de la primera fila, el encabezado
    map<string, int> columnas;
    if (!programasData.empty()) {
        vector<string> encabezado = programasData[0];
        for (int i = 0; i < encabezado.size(); ++i) {
            if (encabezado[i] == "idSexo") columnas["idSexo"] = i;
            else if (encabezado[i] == "sexo") columnas["sexo"] = i;
            else if (encabezado[i] == "ano") columnas["ano"] = i;
            else if (encabezado[i] == "semestre") columnas["semestre"] = i;
            else if (encabezado[i] == "inscritos") columnas["inscritos"] = i;
            else if (encabezado[i] == "admitidos") columnas["admitidos"] = i;
            else if (encabezado[i] == "primeraMatricula") columnas["primeraMatricula"] = i;
            else if (encabezado[i] == "totalMatriculados") columnas["totalMatriculados"] = i;
            else if (encabezado[i] == "graduados") columnas["graduados"] = i;
        }
        // Eliminar la fila de encabezado antes de procesar los datos
        programasData.erase(programasData.begin());
    }

    // Procesar los datos y crear los objetos ProgramaAcademico y Consolidado
    for (const auto &fila : programasData) {
        if (!fila.empty()) {
            int codigoPrograma = std::stoi(fila[0]);
            if (programasAcademicos.find(codigoPrograma) == programasAcademicos.end()) {
                ProgramaAcademico* nuevoPrograma = new ProgramaAcademico();
                nuevoPrograma->setCodigoSniesDelPrograma(codigoPrograma);
                programasAcademicos[codigoPrograma] = nuevoPrograma;
            }

            // Crear un objeto Consolidado directamente usando el constructor
            try {
                int idSexo = std::stoi(fila[columnas["idSexo"]]);
                string sexo = fila[columnas["sexo"]];
                int ano = std::stoi(fila[columnas["ano"]]);
                int semestre = std::stoi(fila[columnas["semestre"]]);
                int inscritos = std::stoi(fila[columnas["inscritos"]]);
                int admitidos = std::stoi(fila[columnas["admitidos"]]);
                int primeraMatricula = std::stoi(fila[columnas["primeraMatricula"]]);
                int totalMatriculados = std::stoi(fila[columnas["totalMatriculados"]]);
                int graduados = std::stoi(fila[columnas["graduados"]]);

                // Crear el Consolidado y asociarlo con el ProgramaAcademico que le corresponde
                Consolidado* nuevoConsolidado = new Consolidado(idSexo, sexo, ano, semestre, inscritos, admitidos, 
                                                                primeraMatricula, totalMatriculados, graduados);

                programasAcademicos[codigoPrograma]->setConsolidado(nuevoConsolidado, 0);
            } catch (const std::exception& e) {
                std::cerr << "Error al crear Consolidado: " << e.what() << std::endl;
            }
        }
    }

    // Lectura de datos del segundo año usando leerArchivoUnificado
    programasData = gestorCsvObj.leerArchivoUnificado(rutaProgramas, ano2, codigosSnies, 13);

    // Procesar los datos del segundo año y crear los objetos Consolidado correspondientes
    for (const auto &fila : programasData) {
        if (!fila.empty()) {
            int codigoPrograma = std::stoi(fila[0]); // Obtener el código del programa
            if (programasAcademicos.find(codigoPrograma) != programasAcademicos.end()) {
                // Crear un objeto Consolidado directamente usando el constructor
                try {
                    int idSexo = std::stoi(fila[columnas["idSexo"]]);
                    string sexo = fila[columnas["sexo"]];
                    int ano = std::stoi(fila[columnas["ano"]]);
                    int semestre = std::stoi(fila[columnas["semestre"]]);
                    int inscritos = std::stoi(fila[columnas["inscritos"]]);
                    int admitidos = std::stoi(fila[columnas["admitidos"]]);
                    int primeraMatricula = std::stoi(fila[columnas["primeraMatricula"]]);
                    int totalMatriculados = std::stoi(fila[columnas["totalMatriculados"]]);
                    int graduados = std::stoi(fila[columnas["graduados"]]);

                    // Crear el Consolidado y asociarlo con el ProgramaAcademico correspondiente
                    Consolidado* nuevoConsolidado = new Consolidado(idSexo, sexo, ano, semestre, inscritos, admitidos, 
                                                                    primeraMatricula, totalMatriculados, graduados);

                    programasAcademicos[codigoPrograma]->setConsolidado(nuevoConsolidado, 1);
                } catch (const std::exception& e) {
                    std::cerr << "Error al crear Consolidado: " << e.what() << std::endl;
                }
            }
        }
    }
}

// Método para calcular otros datos
void SNIESController::calcularDatosExtra(bool flag)
{
    vector<vector<string>> matrizFinal;
    vector<vector<string>> matrizEtiquetas1;
    vector<vector<string>> matrizEtiquetas2;
    vector<vector<string>> matrizEtiquetas3;
    vector<string> etiquetas1 = {"Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual) Primer año", 
                                 "Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual)"};
    matrizEtiquetas1.push_back(etiquetas1);
    vector<string> etiquetas2 = {"Codigo Snies", "Nombre del Programa", "Nombre del Institucion", 
                                 "Diferencial porcentual anual de NEOS"};
    matrizEtiquetas2.push_back(etiquetas2);
    vector<string> etiquetas3 = {"Codigo Snies", " Nombre del Programa sin NEOS en los ultimos 3 semestres"};
    matrizEtiquetas3.push_back(etiquetas3);
    vector<string> datosEtiquetas1;
    vector<string> datosEtiquetas2;
    int sumaPrimerAno = 0;
    int sumaSegundoAno = 0;

    for (auto it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        int neosPrimerAno = 0;
        int neosSegundoAno = 0;
        int diferenciaNeos = 0;
        ProgramaAcademico *programa = it->second;
        int idMetodologiaBuscada = programa->getIdMetodologia();
        if (idMetodologiaBuscada == 1 || idMetodologiaBuscada == 3)
        {
            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i);
                int matriculados = consolidado->getMatriculados();
                sumaPrimerAno += matriculados;
            }

            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i + 4);
                int matriculados = consolidado->getMatriculados();
                sumaSegundoAno += matriculados;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosPrimerAno += numNeos;
        }

        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i + 4);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosSegundoAno += numNeos;
        }

        if (neosPrimerAno != 0)
        {
            diferenciaNeos = ((neosSegundoAno - neosPrimerAno) * 100) / neosPrimerAno;
        }
        else
        {
            diferenciaNeos = 0;
        }
        datosEtiquetas2 = {to_string(programa->getCodigoSniesDelPrograma()), 
                           programa->getProgramaAcademico(), 
                           programa->getInstitucionDeEducacionSuperiorIes(), 
                           to_string(diferenciaNeos)};
        matrizEtiquetas2.push_back(datosEtiquetas2);
    }

    etiquetas1 = {to_string(sumaPrimerAno), to_string(sumaSegundoAno)};
    matrizEtiquetas1.push_back(etiquetas1);
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas1.begin(), matrizEtiquetas1.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas2.begin(), matrizEtiquetas2.end());

    for (const auto &fila : matrizFinal)
    {
        for (size_t i = 0; i < fila.size(); ++i)
        {
            std::cout << fila[i];
            if (i < fila.size() - 1)
            {
                std::cout << ";";
            }
        }
        std::cout << std::endl;
    }

    if (flag)
    {
        bool creado = gestorCsvObj.crearArchivoExtra(rutaOutput, matrizFinal);
    }
}




