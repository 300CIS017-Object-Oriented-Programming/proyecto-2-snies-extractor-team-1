#ifndef VIEW_H
#define VIEW_H

#include "SNIESController.h"
#include "Constantes.h"

using namespace std;

class View {
private:
    SNIESController controlador;
    bool isConvetibleToInt(const string &);

public:
    View();
    ~View();
    bool mostrarPantallaBienvenido();
    void mostrarDatosExtra();
    void buscarPorPalabraClaveYFormacion(); // Mover a la sección pública
    void salir();
    void mostrarMenu(); 
};

#endif


