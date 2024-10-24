//
// Created by User on 13/10/2024.
//
#ifndef GESTOR_JSON_H
#define GESTOR_JSON_H

#include "Constantes.h"
#include <string>
#include <vector>
#include <map>

using std::string;
using std::map;
using std::vector;


class GestorJson {
public:
    void exportarDatos(const std::string& filePath, const std::vector<std::map<std::string, std::string>>& datos);
};

#endif // GESTOR_JSON_H
