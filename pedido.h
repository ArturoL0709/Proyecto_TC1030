
/*
  Nombre del archivo: pedido.h
  Descripción: Este archivo contiene la definición de la clase Plato.
  Autor: Arturo Lopez García
*/



#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Plato.h"
#include "bebida.h"
#include "postre.h"
#include "plato_principal.h"



const int MAX = 1000; // Arreglo de punteros a objetos de tipo "plato"

class pedido {
private:
    plato* alimentos[MAX];
    int menu;// Variable que indica la cantidad de elementos en el arreglo

public:
    pedido() : menu(0) {};// Constructor de la clase pedido


    void agregabebida(string nom, float pre);// Agrega una bebida al pedido
    void agregapostre(string nom, float pre);// Agrega un postre al pedido
    void agregaplatoprin(string nom, float pre, string proteina); // Agrega un plato principal al pedido
    void creaejemplos();// Crea ejemplos de bebidas, postres y platos principales
    float calculartotal();// Calcula el total del pedido
    void muestramenu();// Muestra el menú del restaurante
    void realizarpedido();// Realiza el pedido
    void agregarplato(int opcion);// Agrega un plato  al pedido a partir de una opción seleccionada
    int get_Menu() {
        return menu;
    }
};
/*
Este método de la clase pedido crea ejemplos de bebidas, 
postres y platos principales. Inicializa el arreglo alimentos con objetos predefinidos.

*/
void pedido::creaejemplos() {
    alimentos[0] = new bebida("Agua natural", 12.0);
    menu++;
    alimentos[1] = new bebida("Limonada", 50);
    menu++;
    alimentos[2] = new postre("Cheese cake", 75);
    menu++;
    alimentos[3] = new postre("Bisquet", 50);
    menu++;
    alimentos[4] = new plato_principal("Chilaquiles", 200, "Arrachera");
    menu++;
    alimentos[5] = new plato_principal("Wrap", 150, "Jamon de pavo");
    menu++;
}


/*
Este método muestra el menú del restaurante.
Recorre el arreglo alimentos y muestra la descripción de cada plato utilizando el método to_string() de cada objeto.

*/

void pedido::muestramenu() {
    for (int i = 0; i < menu; i++)
        cout << "[" << i+1 << "] " << alimentos[i]->to_string();
}


/*
Este método calcula el total del pedido sumando el precio de cada plato en el arreglo alimentos.
*/
float pedido::calculartotal() {
    float total = 0;
    for (int i = 0; i < menu; i++)
        total += alimentos[i]->calcular_cuenta();
    return total;
}
/*
Este método agrega una bebida al arreglo alimentos con el nombre y precio especificados.
*/
void pedido::agregabebida(string nombre, float precio) {
    alimentos[menu] = new bebida(nombre, precio);
    menu++;
}
/*
Este método agrega un postre al arreglo alimentos con el nombre y precio especificados.
*/
void pedido::agregapostre(string nombre, float precio) {
    alimentos[menu] = new postre(nombre, precio);
    menu++;
}
/*
Este método agrega un plato principal al arreglo alimentos con el nombre, precio y proteína especificados.
*/
void pedido::agregaplatoprin(string nombre, float precio, string proteina) {
    alimentos[menu] = new plato_principal(nombre, precio, proteina);
    menu++;
}
/*
Este método agrega un plato  al pedido a partir de una opción seleccionada.
Si la opción es válida y diferente de cero, obtiene el nombre y precio del plato correspondiente a la opción seleccionada

*/
void pedido::agregarplato(int opcion) {
    if (opcion > 0 && opcion <= menu) {
        if (opcion != 0) {
            string nombre = alimentos[opcion - 1]->get_nombre();
            float precio = alimentos[opcion - 1]->get_precio();
            agregaplatoprin(nombre, precio, "Sin proteina");
            cout << "Plato agregado exitosamente." << endl;
        }
    }
    else if (opcion != 0) {
        cout << "Opcion invalida. Por favor, seleccione un numero valido del menu." << endl;
    }
}
/*
Este método realiza el pedido del cliente.
Muestra el menú de pedido y permite al cliente seleccionar los platos que desea ordenar.
Calcula el total del pedido y lo muestra al finalizar.
*/
void pedido::realizarpedido() {
    int opcion;
    float total_pedido = 0;
    do {
        cout << "\n-- Menu de Pedido --" << endl;
        muestramenu();
        cout << "[0] Salir" << endl;
        cout << "Ingrese el numero del plato que desea ordenar (0 para salir): ";
        cin >> opcion;

        agregarplato(opcion);
        total_pedido = calculartotal();  // Calcular el total del pedido

    } while (opcion != 0);

    cout << "Total del pedido: " << total_pedido << " pesos" << endl;
}

#endif