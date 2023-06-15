
/*
  Nombre del archivo: Plato.h
  Descripción: Este archivo contiene la definición de la clase Plato.
  Autor: Arturo Lopez García
*/


#ifndef PLATO_H
#define PLATO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class plato {

/*
Descripción: Esta clase representa un plato de comida en un menú.
*/

protected:
    string nombre;
    string tipo;
    float precio;

public:

  /*
    Descripción: Constructor de la clase Plato.
    Parámetros:
      - nombre: El nombre del plato.
      - precio: El precio del plato.
  */
 
    plato() : nombre(""), precio(0), tipo("") {};
    plato(string nom, float pre, string tip) : nombre(nom), precio(pre), tipo(tip) {};

    string get_nombre() { 
        return nombre;
    }
    float get_precio() {
        return precio;
    }
    string get_tipo() {
        return tipo;
    }

    virtual float calcular_cuenta() = 0;
    virtual string to_string() = 0;
};


#endif