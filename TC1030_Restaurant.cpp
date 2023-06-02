#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class plato {
protected:
    string nombre;
    string tipo;
    float precio;

public:
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

class bebida : public plato {
private:
    float cuenta_bebida;
    float tamanio;

public:
    bebida() : plato("", 0, "Bebida") {};
    bebida(string nom, float pre) : plato(nom, pre, "Bebida"), cuenta_bebida(pre) {};

    float calcular_cuenta() {
        return cuenta_bebida;
    }

    string to_string();
};

string bebida::to_string() {
    stringstream aux;
    aux << "La bebida es " << nombre << " y su precio es de " << precio << " pesos" "\n";
    return aux.str();
}

class postre : public plato {
private:
    float cuenta_postre;

public:
    postre() : plato("", 0, "Postre") {};
    postre(string nom, float pre) : plato(nom, pre, "Postre"), cuenta_postre(pre) {};

    float calcular_cuenta() {
        return cuenta_postre;
    }

    string to_string();
};

string postre::to_string() {
    stringstream aux;
    aux << "El postre es " << nombre << " y su precio es de " << precio << " pesos" << "\n";
    return aux.str();
}

class plato_principal : public plato {
private:
    string proteina;
    float cuenta_plato;

public:
    plato_principal() : plato("", 0, "Plato principal") {};

    plato_principal(string nom, float pre, string prote) : plato(nom, pre, "Plato principal"), proteina(prote), cuenta_plato(pre) {};

    float calcular_cuenta() {
        return cuenta_plato;
    }

    string to_string();
};

string plato_principal::to_string() {
    stringstream aux;
    aux << "El plato principal es " << nombre << " va acompañado de " << proteina << " y su precio es de " << precio << " pesos" << "\n";
    return aux.str();
}

const int MAX = 1000;

class pedido {
private:
    plato* alimentos[MAX];
    int menu;

public:
    pedido() : menu(0) {};

    void agregabebida(string nom, float pre);
    void agregapostre(string nom, float pre);
    void agregaplatoprin(string nom, float pre, string proteina);
    void creaejemplos();
    float calculartotal();
    void muestramenu();
    int get_Menu (){
        return menu;
    }
};

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

void pedido::muestramenu() {
    for (int i = 0; i < menu; i++)
        cout << "[" << i+1 << "] " << alimentos[i]->to_string();
}

float pedido::calculartotal() {
    float total = 0;
    for (int i = 0; i < menu; i++)
        total += alimentos[i]->calcular_cuenta();
    return total;
}

void pedido::agregabebida(string nombre, float precio) {
    alimentos[menu] = new bebida(nombre, precio);
    menu++;
}

void pedido::agregapostre(string nombre, float precio) {
    alimentos[menu] = new postre(nombre, precio);
    menu++;
}

void pedido::agregaplatoprin(string nombre, float precio, string proteina) {
    alimentos[menu] = new plato_principal(nombre, precio, proteina);
    menu++;
}

int main() {
    pedido Pedido;
    Pedido.creaejemplos();

    cout << "Bienvenidos a este restaurante" << endl;
    int opcion;
    do {
        cout << "\n-- Menú --" << endl;
        Pedido.muestramenu();
        cout << "[0] Salir" << endl;
        cout << "Ingrese el número del plato que desea ordenar (0 para salir): ";
        cin >> opcion;

        if (opcion > 0 && opcion <= Pedido.get_Menu()) {
            cout << "¡Ha ordenado el plato número " << opcion << "!" << endl;
            // Aquí puedes realizar cualquier acción adicional con el plato seleccionado, como agregarlo a la orden o calcular su costo individualmente.
        }
        else if (opcion != 0) {
            cout << "Opción inválida. Por favor, seleccione un número válido del menú." << endl;
        }
    } while (opcion != 0);

    // Calcular el total de la cuenta
    float total = Pedido.calculartotal();
    cout << "Total de la cuenta: " << total << " pesos" << endl;

    return 0;
}

