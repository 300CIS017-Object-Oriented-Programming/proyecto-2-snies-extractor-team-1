#ifndef VIEW_H
#define VIEW_H

#include "SNIESController.h"

using std::string;

class View
{
private:
    SNIESController controlador;
    bool isConvetibleToInt(const string &);
    bool mostrarPantallaBienvenido();
    void mostrarDatosExtra();
    void buscarPorPalabraClaveYFormacion();
    void salir();
public:
    View() = default;
    ~View();
    void mostrarMenu();
};

#endif