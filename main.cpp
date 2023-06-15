
/*
  Nombre del archivo: main.cpp
  Descripción: Este archivo contiene el main.
  Autor: Arturo Lopez García
*/
/*

La función principal main() del programa. Crea un objeto de la clase pedido llamado Pedido e invoca al método creaejemplos()
para inicializar el menú con ejemplos predefinidos.Luego, muestra el menú principal del restaurante y permite al usuario seleccionar opciones
para agregar bebidas, postres, platos principales, mostrar el menú o realizar un pedido.
El bucle se repite hasta que el usuario seleccione la opción "0" para salir.


*/



#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "bebida.h"
#include "pedido.h"
#include "plato_principal.h"
#include "postre.h"
#include "Plato.h"

int main() {
    
    pedido Pedido;
    Pedido.creaejemplos();

    cout << "Bienvenidos a este restaurante" << endl;
    int opcion;
    do {//Despliega un menu de opciones
        cout << "\n-- Menu --" << endl;
        cout << "[1] Agregar una bebida" << endl;
        cout << "[2] Agregar un postre" << endl;
        cout << "[3] Agregar un plato principal" << endl;
        cout << "[4] Mostrar el menú del restaurante" << endl;
        cout << "[5] Realizar pedido" << endl;
        cout << "[0] Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                float precio;
                cout << "Ingrese el nombre de la bebida: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el precio de la bebida: ";//Agrega bebida al Menu del restaurante
                cin >> precio;
                Pedido.agregabebida(nombre,precio );
                break;
            }
            case 2: {
                string nombre;
                float precio;
                cout << "Ingrese el nombre del postre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el precio del postre: ";
                cin >> precio;
                Pedido.agregapostre(nombre, precio); //Agrega postre al Menu del restaurante
                break;
            }
            case 3: {
                string nombre;
                float precio;
                string proteina;
                cout << "Ingrese el nombre del plato principal: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el precio del plato principal: ";
                cin >> precio;
                cout << "Ingrese la proteina del plato principal: ";
                cin.ignore();
                getline(cin, proteina);
                Pedido.agregaplatoprin(nombre, precio, proteina);//Agrega un plato principal al Menu del restaurante
                break;
            }
            case 4:
                Pedido.muestramenu();//Muestra el menu del restaurante
                break;
            case 5:
                Pedido.realizarpedido();//Inicia la funcion para realizar un pedido
                break;
            case 0:
                cout << "Gracias por visitarnos. Hasta luego" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione un número valido del menu." << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}