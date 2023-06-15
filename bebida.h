/*
  Nombre del archivo: bebida.h
  Descripción: Este archivo contiene la definición de la clase bebida.
  Autor: Arturo Lopez García
*/





#ifndef BEBIDA_H
#define BEBIDA_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Plato.h"



class bebida : public plato {
/*
 Esta clase representa una bebida en un menú.
*/

private:
    float cuenta_bebida;
    float tamanio;

public:
 /*
  Constructor de la clase Bebida y  Parámetros
    
  */
  bebida() : plato("", 0, "Bebida"), cuenta_bebida(0) {};
  bebida(string nom, float pre) : plato(nom, pre, "Bebida"), cuenta_bebida(pre) {};


    float calcular_cuenta() {
        return cuenta_bebida;
    }

    string to_string() {
        stringstream aux;
        aux << "La bebida es " << nombre << " y su precio es de " << precio << " pesos" << "\n";
        return aux.str();
    }
};
#endif