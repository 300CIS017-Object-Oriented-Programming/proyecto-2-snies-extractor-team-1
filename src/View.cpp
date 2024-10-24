#include "View.h"

// Constructor de View
View::View()
{
    // Inicialización de rutas de archivos
    string ruta1 = "C:/SNIES_EXTRACTOR/inputs/programas.csv";
    string ruta2 = "C:/SNIES_EXTRACTOR/inputs/admitidos";
    string ruta3 = "C:/SNIES_EXTRACTOR/inputs/graduados";
    string ruta4 = "C:/SNIES_EXTRACTOR/inputs/inscritos";
    string ruta5 = "C:/SNIES_EXTRACTOR/inputs/matriculados";
    string ruta6 = "C:/SNIES_EXTRACTOR/inputs/matriculadosPrimerSemestre";
    string ruta7 = "C:/SNIES_EXTRACTOR/outputs/";
    controlador = SNIESController(ruta1, ruta2, ruta3, ruta4, ruta5, ruta6, ruta7);
}

// Destructor de View
View::~View()
{
    // El controlador se limpiará automáticamente al salir del ámbito
}

// Mostrar pantalla de bienvenida
bool View::mostrarPantallaBienvenido()
{
    bool parametrizacionBool = false;

    cout << "Bienvenido al SNIES-Extractor!" << endl;
    cout << "=========================================" << endl;
    cout << "Recuerde que para el correcto funcionamiento del programa tuvo que haber parametrizado" << endl;
    cout << "antes la carpeta SNIES_EXTRACTOR en el disco duro C:, con sus respectivas carpetas inputs y outputs" << endl;
    cout << "y todos los archivos CSV del SNIES." << endl;
    cout << "Si ya hizo esto, escriba 'Y', de lo contrario 'N', y Enter: " << endl;
    char userAnswer = 'Y';
    userAnswer = static_cast<char>(tolower(userAnswer));

    if (userAnswer == 'y')
    {
        parametrizacionBool = true;

        string userText;
        cout << "A continuacion se procesaran los datos de los programas academicos seleccionados en /programas.csv..." << endl;
        string anio1("abc");
        string ano2("abc");
        string anoAux;
        int i = 0;

        // Bucle para leer un valor válido del año1
        while (!(isConvetibleToInt(anio1)))
        {
            if (i == 1)
            {
                cout << "El valor ingresado fue invalido!" << endl;
                cout << "Por favor ingrese un valor valido la proxima vez" << endl;
                cout << "Presione 'OK' y Enter para continuar: " << endl;
                cin >> userText;
                cout << endl;
            }
            cout << "Escriba el primer ano de busqueda: " << endl;
            cin >> anio1;
            cout << endl;
            i = 1;
        }

        i = 0;
        // Bucle para leer un valor válido del año2
        while (!(isConvetibleToInt(ano2)))
        {
            if (i == 1)
            {
                cout << "El valor ingresado fue invalido!" << endl;
                cout << "Por favor ingrese un valor valido la proxima vez" << endl;
                cout << "Presione 'OK' y Enter para continuar: " << endl;
                cin >> userText;
                cout << endl;
            }
            cout << "Escriba el segundo ano de busqueda: " << endl;
            cin >> ano2;
            cout << endl;
            i = 1;
        }

        // Organizar los años
        if (stoi(ano2) < stoi(anio1))
        {
            anoAux = anio1;
            anio1 = ano2;
            ano2 = anoAux;
        }

        cout << "Procesando datos ..." << endl;
        controlador.procesarDatosCsv(anio1, ano2);
        cout << "Datos procesados con exito!" << endl;
    }

    return parametrizacionBool;
}

// Función para mostrar datos extra
void View::mostrarDatosExtra()
{
    char opcionYN;
    cout << "A continuacion vamos a mostrar datos relevantes de los programas academicos seleccionados" << "\n"
         << endl;
    cout << "Desea convertir los datos a un archivo CSV?(Y/N): " << endl;
    cin >> opcionYN;
    opcionYN = tolower(opcionYN);
    cout << "\n";

    if (opcionYN == 'y')
    {
        controlador.calcularDatosExtra(true);
    }
    else
    {
        controlador.calcularDatosExtra(false);
    }
}

// Función para buscar por palabra clave y formación académica
void View::buscarPorPalabraClaveYFormacion()
{
    char opcionYN = 'y', opcionCSV;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (opcionYN == 'y')
    {
        cout << "Desea hacer una busqueda por palabra clave del nombre del programa(Y/N): " << endl;
        cin >> opcionYN;
        cout << "\n";
        opcionYN = tolower(opcionYN);

        if (opcionYN == 'y')
        {
            cout << "Deseas convertir los datos del programa academico a un CSV?(Y/N): " << endl;
            cin >> opcionCSV;
            cout << "\n";
            opcionCSV = tolower(opcionCSV);

            convertirCSV = (opcionCSV == 'y');

            cout << "Escriba la palabra clave para buscar los programas por nombre:" << endl;
            cin >> palabraClave;
            cout << endl;

            cout << "Seleccione un nivel de formacion para filtrar: \n 1->Especializacion Universitaria\n 2->Maestria\n"
                 << " 3->Doctorado\n 4->Formacion Tecnica Profesional\n 5->Tecnologico\n 6->Universitario\n"
                 << " 7->Especializacion Tecnico Profesional\n 8->Especializacion Tecnologica\n"
                 << " 10->Especializacion Medico Quirurgica\n " << endl;
            cin >> idFormacionAcademica;
            cout << "\n";

            while ((idFormacionAcademica > 10) || (idFormacionAcademica == 9) || (idFormacionAcademica < 1))
            {
                cout << "Seleccione una opcion entre 1-10 excluyendo el 9\n" << endl;
                cin >> idFormacionAcademica;
            }

            controlador.buscarProgramas(convertirCSV, palabraClave, idFormacionAcademica);
        }
    }
}

// Función para salir del programa
void View::salir()
{
    char confirmExit;
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados." << endl;
    cout << "¿Está seguro de que desea salir? (Y/N): ";
    cin >> confirmExit;
    confirmExit = tolower(confirmExit);

    if (confirmExit == 'y') {
        cout << "Programa cerrado con éxito!" << endl;
    } else {
        cout << "El cierre del programa ha sido cancelado." << endl;
    }
}

// Función para verificar si un string se puede convertir a int
bool View::isConvetibleToInt(const string &str)
{
    try
    {
        std::size_t pos;
        int num = std::stoi(str, &pos);

        // Verificamos si se ha convertido toda la cadena
        return pos == str.length();
    }
    catch (const std::invalid_argument &)
    {
        return false;
    }
    catch (const std::out_of_range &)
    {
        return false;
    }
}
