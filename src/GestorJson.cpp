//
// Created by User on 13/10/2024.
//

#include "GestorJson.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::map;
using std::vector;

// Método para exportar datos a un archivo JSON.
// Parámetros:
// - filePath (const string&) - ruta del archivo donde se guardará el JSON.
// - datos (const vector<map<string, string>>&) - vector de mapas que contiene los datos a exportar.
void GestorJson::exportarDatos(const string& filePath, const vector<std::map<string, string>>& datos) {
    try {
        // Intentar abrir el archivo para escritura.
        std::ofstream file(filePath);
        
        // Verificar si el archivo se abrió correctamente.
        if (!file.is_open()) {
            // Lanzar excepción si el archivo no se puede abrir.
            throw std::ios_base::failure("No se pudo abrir el archivo JSON para exportar: " + filePath);
        }

        // Iniciar el array de objetos JSON.
        file << "[\n";

        // Procesar cada entrada en el vector de datos.
        for (size_t i = 0; i < datos.size(); ++i) {
            file << "  {\n";
            
            // Obtener la entrada actual.
            const auto& entry = datos[i];
            size_t entryCount = 0;  // Contador para separar elementos con comas.

            // Iterar sobre el mapa de la entrada actual.
            for (const auto& [key, value] : entry) {
                // Escribir la clave y el valor en formato JSON.
                file << "    \"" << key << "\": \"" << value << "\"";
                
                // Agregar coma si no es el último elemento de la entrada.
                if (++entryCount < entry.size()) {
                    file << ",";
                }
                file << "\n";
            }

            file << "  }";
            // Agregar coma si no es la última entrada del vector.
            if (i < datos.size() - 1) {
                file << ",";
            }
            file << "\n";
        }

        // Cerrar el array de JSON.
        file << "]\n";

        // Cerrar el archivo.
        file.close();
        std::cout << "Exportación a JSON exitosa: " << filePath << std::endl;
    }
    // Capturar errores específicos relacionados con archivos.
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error de archivo: " << e.what() << std::endl;
    }
    // Capturar cualquier otra excepción estándar.
    catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }
    // Capturar errores desconocidos.
    catch (...) {
        std::cerr << "Ocurrió un error desconocido durante la exportación a JSON." << std::endl;
    }
}
