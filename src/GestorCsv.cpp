#include "GestorCsv.h"

// FIXME: LA LECTURA DE ARCHIVOS CON GETLINE FUNCIONA HORRIBLEMENTE, NO TENEMOS IDEA DE POR QUÉ

vector<string> GestorCsv::leerProgramasCsv(string &ruta)
{
    vector<string> codigosSniesRetorno;
    ifstream archivoProgramasCsv(ruta);
    char delimitador = ';';
    if (!(archivoProgramasCsv.is_open()))
    {
        cout << "Archivo " << ruta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string linea, dato;
        getline(archivoProgramasCsv, linea);
        while (getline(archivoProgramasCsv, linea))
        {
            stringstream streamLinea(linea);

            while(getline(streamLinea, dato, delimitador)){
                codigosSniesRetorno.push_back(dato);
            }
            // Manteniemiento: Se puede mejorar la forma de leer los datos de la línea y
            // los nombres de los métodos y variables.
        }
    }
    archivoProgramasCsv.close();
    return codigosSniesRetorno;
}

int GestorCsv::contarColumnas(string &rutaBase, string &ano)
{
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivo(rutaCompleta);
    if (!archivo.is_open())
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
        return 0; // Retorna 0 si el archivo no se pudo abrir
    }

    string fila;
    getline(archivo, fila); // Leer la primera fila (etiquetas)
    archivo.close(); // Cerrar el archivo

    // Usar un stringstream para contar las columnas separadas por ';'
    stringstream streamFila(fila);
    string dato;
    int numColumnas = 0;
    while (getline(streamFila, dato, ';'))
    {
        numColumnas++; // Incrementar el contador por cada columna encontrada
    }

    return numColumnas;
}
vector<vector<string>> GestorCsv::leerArchivoUnificado(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies)
{
    // Obtener el número de columnas automáticamente
    int numColumnas = contarColumnas(rutaBase, ano);
    if (numColumnas == 0)
    {
        // Si no se pudo determinar el número de columnas, retornar matriz vacía
        return vector<vector<string>>();
    }

    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivo(rutaCompleta);

    if (!archivo.is_open())
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
        return matrizResultado;
    }

    string fila, dato;
    vector<string> vectorFila(numColumnas); // Inicializa vectorFila con el número de columnas esperado
    stringstream streamFila;
    int columnaArchivo, columnaVector;
    vector<int>::iterator it;

    // Saltar la primera fila (etiquetas)
    getline(archivo, fila);

    // Leer cada fila del archivo
    while (getline(archivo, fila))
    {
        streamFila = stringstream(fila);
        columnaArchivo = 0;
        columnaVector = 0;

        // Leer las columnas de la fila hasta la columna de interés
        while (getline(streamFila, dato, ';') && columnaArchivo < numColumnas)
        {
            // Si estamos en la columna de códigos SNIES, guardamos el dato en vectorFila
            if (columnaArchivo == colmunaCodigoSnies)
            {
                vectorFila[columnaVector] = dato;
                columnaVector++;
            }
            columnaArchivo++;
        }

        // Verificamos si el código SNIES es válido y pertenece a los códigos de interés
        if (vectorFila[0] != "Sin programa especifico")
        {
            it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[0]));
        }
        else
        {
            it = codigosSnies.end();
        }

        // Si el código SNIES está en el vector de interés, procesamos la fila
        if (it != codigosSnies.end())
        {
            // Completar la lectura de la fila actual
            while (getline(streamFila, dato, ';'))
            {
                if (columnaVector < numColumnas)
                {
                    vectorFila[columnaVector] = dato;
                    columnaVector++;
                }
            }
            matrizResultado.push_back(vectorFila);

            // Leer las 3 filas adicionales relacionadas
            for (int i = 0; i < 3; i++)
            {
                if (getline(archivo, fila))
                {
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;

                    while (getline(streamFila, dato, ';') && columnaArchivo < numColumnas)
                    {
                        if (columnaArchivo == colmunaCodigoSnies)
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
        }
    }

    archivo.close();
    return matrizResultado;
}


// Lee un archivo CSV y devuelve una matriz de strings con los datos especificados por la columna SNIES.
// Parámetros:
// - rutaBase (string) - ruta base del archivo CSV.
// - ano (string) - año del archivo a leer.
// - codigosSnies (vector<int>) - vector con los códigos SNIES de programas de interés.
// - colmunaCodigoSnies (int) - columna del archivo CSV que contiene los códigos SNIES.
// Retorna: una matriz con los datos de programas académicos filtrados.
vector<vector<string>> GestorCsv::leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies)
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivoSegundo(rutaCompleta);
    if (!(archivoSegundo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila(2);
        stringstream streamFila;
        int columnaArchivo;
        int columnaVector;
        vector<int>::iterator it;

        // Nos saltamos las etiquetas para no interferir en el bucle
        getline(archivoSegundo, fila);

        // Leemos las filas
        while (getline(archivoSegundo, fila))
        {
            streamFila = stringstream(fila);
            columnaArchivo = 0;
            columnaVector = 0;
            while ((getline(streamFila, dato, ';')) && (columnaArchivo < (colmunaCodigoSnies + 1)))
            {
                if (columnaArchivo == colmunaCodigoSnies)
                {
                    vectorFila[columnaVector] = dato;
                    columnaVector++;
                }
                columnaArchivo++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[0] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[0]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso cuando SI es parte de los que me interesan
            {
                // Terminar de leer primera fila
                while (getline(streamFila, dato, ';'))
                {
                }
                vectorFila[columnaVector] = dato;
                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < 3; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;
                    while (getline(streamFila, dato, ';'))
                    {
                        if (columnaArchivo == colmunaCodigoSnies)
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    vectorFila[columnaVector] = dato;
                    matrizResultado.push_back(vectorFila);
                }
            }
            else // Caso cuando NO es parte de los que me interesan
            {
                /*// Saltarme las 3 siguientes filas con mismo codigo Snies
                for (int j = 0; j < 3; j++)
                {
                    getline(archivoSegundo, fila);
                }*/
            }
        }
    }

    /*
    Ejemplo de matrizResultado: (No tendría las etiquetas incluidas)
    CodigoSnies;DatoExtradelArchivo
    12;5
    */
    archivoSegundo.close();
    /*// Imprimir matriz resultado para verificaciones
    for (int h = 0; h < matrizResultado.size(); h++)
    {
        for (int k = 0; k < matrizResultado[h].size(); k++)
        {
            cout << matrizResultado[h][k];
            if (k != (matrizResultado[h].size() - 1))
            {
                cout << ";";
            }
        }
        cout << endl;
    }*/
    return matrizResultado;
}

// Crea un archivo CSV con los datos de programas académicos.
// Parámetros:
// - ruta (string) - ruta donde se creará el archivo CSV.
// - mapadeProgramasAcademicos (map<int, ProgramaAcademico*>) - mapa con los programas académicos.
// - etiquetasColumnas (vector<string>) - vector con las etiquetas para las columnas del archivo.
// Retorna: booleano que indica si el archivo se creó con éxito.
bool GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoResultados << etiquetasColumnas[i] << ";";
        }
        archivoResultados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        map<int, ProgramaAcademico *>::iterator it;
        // Leemos todos los programas del mapa para imprimirlos en el archivo
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            // Imprimimos cada uno de los 8 consolidados por programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos toda la información base del programa academico
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << ";";
                archivoResultados << (it->second)->getIesPadre() << ";";
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << ";";
                archivoResultados << (it->second)->getPrincipalOSeccional() << ";";
                archivoResultados << (it->second)->getIdSectorIes() << ";";
                archivoResultados << (it->second)->getSectorIes() << ";";
                archivoResultados << (it->second)->getIdCaracter() << ";";
                archivoResultados << (it->second)->getCaracterIes() << ";";
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << ";";
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << ";";
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << ";";
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << ";";
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << ";";
                archivoResultados << (it->second)->getProgramaAcademico() << ";";
                archivoResultados << (it->second)->getIdNivelAcademico() << ";";
                archivoResultados << (it->second)->getNivelAcademico() << ";";
                archivoResultados << (it->second)->getIdNivelDeFormacion() << ";";
                archivoResultados << (it->second)->getNivelDeFormacion() << ";";
                archivoResultados << (it->second)->getIdMetodologia() << ";";
                archivoResultados << (it->second)->getMetodologia() << ";";
                archivoResultados << (it->second)->getIdArea() << ";";
                archivoResultados << (it->second)->getAreaDeConocimiento() << ";";
                archivoResultados << (it->second)->getIdNucleo() << ";";
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << ";";
                archivoResultados << (it->second)->getIdCineCampoAmplio() << ";";
                archivoResultados << (it->second)->getDescCineCampoAmplio() << ";";
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << ";";
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << ";";
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << ";";
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << ";";
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << ";";
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << ";";
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << ";";
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << ";";

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << ";";
                archivoResultados << consolidadoActual->getSexo() << ";";
                archivoResultados << consolidadoActual->getAno() << ";";
                archivoResultados << consolidadoActual->getSemestre() << ";";
                archivoResultados << consolidadoActual->getAdmitidos() << ";";
                archivoResultados << consolidadoActual->getGraduados() << ";";
                archivoResultados << consolidadoActual->getInscritos() << ";";
                archivoResultados << consolidadoActual->getMatriculados() << ";";
                archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoResultados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

// Crea un archivo CSV con los programas académicos buscados.
// Parámetros:
// - ruta (string) - ruta donde se creará el archivo CSV.
// - programasBuscados (list<ProgramaAcademico*>) - lista con los programas buscados.
// - etiquetasColumnas (vector<string>) - vector con las etiquetas para las columnas del archivo.
// Retorna: booleano que indica si el archivo se creó con éxito.
bool GestorCsv::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.csv";
    ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open())
    {

        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoBuscados << etiquetasColumnas[i] << ";";
        }
        archivoBuscados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        list<ProgramaAcademico *>::iterator it;
        // Leemos todos los programas de la lista de los programas buscados para imprimirlos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++)
        {
            // Imprimimos los 8 consolidados del programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos la informacion base del programa
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << ";";
                archivoBuscados << (*it)->getIesPadre() << ";";
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << ";";
                archivoBuscados << (*it)->getPrincipalOSeccional() << ";";
                archivoBuscados << (*it)->getIdSectorIes() << ";";
                archivoBuscados << (*it)->getSectorIes() << ";";
                archivoBuscados << (*it)->getIdCaracter() << ";";
                archivoBuscados << (*it)->getCaracterIes() << ";";
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << ";";
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << ";";
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << ";";
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << ";";
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << ";";
                archivoBuscados << (*it)->getProgramaAcademico() << ";";
                archivoBuscados << (*it)->getIdNivelAcademico() << ";";
                archivoBuscados << (*it)->getNivelAcademico() << ";";
                archivoBuscados << (*it)->getIdNivelDeFormacion() << ";";
                archivoBuscados << (*it)->getNivelDeFormacion() << ";";
                archivoBuscados << (*it)->getIdMetodologia() << ";";
                archivoBuscados << (*it)->getMetodologia() << ";";
                archivoBuscados << (*it)->getIdArea() << ";";
                archivoBuscados << (*it)->getAreaDeConocimiento() << ";";
                archivoBuscados << (*it)->getIdNucleo() << ";";
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << ";";
                archivoBuscados << (*it)->getIdCineCampoAmplio() << ";";
                archivoBuscados << (*it)->getDescCineCampoAmplio() << ";";
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << ";";
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << ";";
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << ";";
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << ";";
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << ";";
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << ";";
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << ";";
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << ";";

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << ";";
                archivoBuscados << consolidadoActual->getSexo() << ";";
                archivoBuscados << consolidadoActual->getAno() << ";";
                archivoBuscados << consolidadoActual->getSemestre() << ";";
                archivoBuscados << consolidadoActual->getAdmitidos() << ";";
                archivoBuscados << consolidadoActual->getGraduados() << ";";
                archivoBuscados << consolidadoActual->getInscritos() << ";";
                archivoBuscados << consolidadoActual->getMatriculados() << ";";
                archivoBuscados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoBuscados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

// Crea un archivo CSV con una matriz de datos proporcionada.
// Parámetros:
// - ruta (string) - ruta donde se creará el archivo CSV.
// - datosAImprimir (vector<vector<string>>) - matriz de datos a imprimir en el archivo.
// Retorna: booleano que indica si el archivo se creó con éxito.
bool GestorCsv::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    // Este bool nos ayudará a saber si se creo el archivo exitosamente
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.csv";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Imprimimos la matriz de datos que queremos imprimir
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            // Imprimimos cada fila
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                // Imprimimos cada dato separado por ';'
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << ";";
                }
            }
            // Saltamos de linea al terminar una fila
            archivoExtra << endl;
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}
