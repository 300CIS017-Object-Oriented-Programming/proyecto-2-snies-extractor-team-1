#include "Consolidado.h"

// Constructor por defecto: no realiza ninguna inicialización especial.
Consolidado::Consolidado() = default;

// Constructor con parámetros: inicializa los atributos de la clase con los valores proporcionados.
// Parámetros:
// - idSexo: Identificador del sexo.
// - sexo: Descripción del sexo.
// - ano: Año del consolidado.
// - semestre: Semestre del consolidado.
// - inscritos: Número de inscritos en el semestre.
// - admitidos: Número de admitidos en el semestre.
// - primeraMatricula: Número de estudiantes con primera matrícula.
// - totalMatriculados: Número total de matriculados en el primer semestre.
// - graduados: Número de estudiantes graduados.
Consolidado::Consolidado(int idSexo, string sexo, int ano, int semestre, int inscritos, int admitidos, 
                         int primeraMatricula, int totalMatriculados, int graduados)
    : idSexo(idSexo), sexo(sexo), ano(ano), semestre(semestre), inscritos(inscritos), admitidos(admitidos), 
      matriculados(primeraMatricula), totalMatriculadosPrimerSemestre(totalMatriculados), graduados(graduados) {}

// Constante para representar el factor de porcentaje en los cálculos de tasas.
const float PORCENTAJE = 100.0;

// Getters y Setters: métodos para acceder y modificar los atributos privados de la clase.
int Consolidado::getIdSexo() { return idSexo; }
void Consolidado::setIdSexo(int idSexo) { this->idSexo = idSexo; }

string Consolidado::getSexo() { return sexo; }
void Consolidado::setSexo(string &sexo) { this->sexo = sexo; }

int Consolidado::getAno() { return ano; }
void Consolidado::setAno(int ano) { this->ano = ano; }

int Consolidado::getSemestre() { return semestre; }
void Consolidado::setSemestre(int semestre) { this->semestre = semestre; }

int Consolidado::getInscritos() { return inscritos; }
void Consolidado::setInscritos(int inscritos) { this->inscritos = inscritos; }

int Consolidado::getAdmitidos() { return admitidos; }
void Consolidado::setAdmitidos(int admitidos) { this->admitidos = admitidos; }

int Consolidado::getMatriculados() { return matriculados; }
void Consolidado::setMatriculados(int matriculados) { this->matriculados = matriculados; }

int Consolidado::getMatriculadosPrimerSemestre() { return totalMatriculadosPrimerSemestre; }
void Consolidado::setMatriculadosPrimerSemestre(int totalMatriculadosPrimerSemestre) {
    this->totalMatriculadosPrimerSemestre = totalMatriculadosPrimerSemestre;
}

int Consolidado::getGraduados() { return graduados; }
void Consolidado::setGraduados(int graduados) { this->graduados = graduados; }

// Calcula la tasa de admitidos como un porcentaje del total de inscritos.
// Retorna: tasa de admitidos (%), o 0 si no hay inscritos.
float Consolidado::obtenerTasaAdmitidos() {
    // Verifica si el número de inscritos es mayor que cero para evitar división por cero.
    if (inscritos > 0) {
        return (static_cast<float>(admitidos) / inscritos) * PORCENTAJE;
    }
    // Retorna 0 si no hay inscritos.
    return 0;
}

// Calcula la tasa de graduados como un porcentaje del total de matriculados en el primer semestre.
// Retorna: tasa de graduados (%), o 0 si no hay matriculados en el primer semestre.
float Consolidado::obtenerTasaGraduados() {
    // Verifica si el número de matriculados en el primer semestre es mayor que cero.
    if (totalMatriculadosPrimerSemestre > 0) {
        return (static_cast<float>(graduados) / totalMatriculadosPrimerSemestre) * PORCENTAJE;
    }
    // Retorna 0 si no hay matriculados en el primer semestre.
    return 0;
}
