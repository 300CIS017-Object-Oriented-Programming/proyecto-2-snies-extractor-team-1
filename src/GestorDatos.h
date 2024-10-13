//
// Created by User on 13/10/2024.
//

#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <string>
#include <vector>
#include <map>

using std::string;
using std::map;
using std::vector;


class GestorDatos {
protected:
    // Constructor y Destructor
    GestorDatos();
    ~GestorDatos();

    // Metodo para escribir datos procesados en un archivo
    virtual void exportarDatos(const std::string& filePath) = 0;
};

#endif // GESTOR_DATOS_H