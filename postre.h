

/*
  Nombre del archivo: postre.h
  Descripción: Este archivo contiene la definición de la clase postre.
  Autor: Arturo Lopez García
*/
/*
Esta es otra clase derivada de plato llamada postre. 
Al igual que la clase bebida, hereda las características de la clase base y agrega un miembro llamado cuenta_postre.
También implementa los métodos virtuales calcular_cuenta() y to_string().
*/
#ifndef POSTRE_H
#define POSTRE_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Plato.h"

class postre : public plato {
 /*
 Esta clase representa una postre en un menú.
*/
private:
    float cuenta_postre;

public:

 /*
  Constructor de la clase postre y  Parámetros
    
  */
    postre() : plato("", 0, "Postre"), cuenta_postre(0) {};
    postre(string nom, float pre) : plato(nom, pre, "Postre"), cuenta_postre(pre) {};


    float calcular_cuenta() {
        return cuenta_postre;
    }

    string to_string() {
        stringstream aux;
        aux << "El postre es " << nombre << " y su precio es de " << precio << " pesos" << "\n";
        return aux.str();
    }
};
#endif 