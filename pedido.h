/*
 *
 * Proyecto Restaurante
 * Arturo Lopez Garcia
 * A01276405
 * 25/05/2023
 * version : 1
 * Esta clase defina objeto de tipo plato que contiene las clases heredadas
 * postre, bebida y plato principal.
 */


#ifndef pedido_h
#define pedido_h

#include <iostream>
#include <string>
#include <sstream>
using namespace std; 

#include "Plato.h"

const int MAX = 100;


class pedido {

    private: 

   plato * alimentos [MAX];

   float cuenta;  

   int menu;

   public : 
    
    pedido (): menu (0) {}; 

    void agregabebida (string nom, float pre,float  mil);
    void agregapostre (string nom, float pre,int cal);
    void agregaplatoprin (string nom, float pre, string proteina ) ; 
    void creaejemplos (); 
    float calculartotal (); 
    string muestramenu(string alimentos); 
    void imprime ();



};




void pedido::creaejemplos () {

    alimentos [1] = new bebida ("Agua natural", 12 , 600);
    alimentos [2] = new bebida ("limonada", 50 , 350);

    

}





    



#endif 