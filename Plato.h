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

#ifndef plato_h
#define plato_h


#include <string>
#include <sstream>
using namespace std; 

//Creacion de la calse 

class plato {

   protected: // atributos

   string nombre ; 
   float precio ;

   public: // metodos

   plato ():nombre(""), precio(0){}; //Constructor default
   plato (string nom, float pre):
    nombre(nom), precio (pre){}; 


string get_nombre () { 
    return nombre;
}
float get_precio () { 
    return precio;
}

 
   virtual float calcular_precio () = 0; //Metodo abstracto
   virtual string to_string () = 0; 
   void imprime();
   

};



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Decaramos objeto bebida que hereda de plato


class bebida: public plato {

    private : //Variables de instancia del objeto

    float mili; 

    public : 

    bebida (): plato ("", 0){};  //Constructor
    bebida (string nom, float pre, float mil): plato (nombre, precio),
    mili(mil){}; 
    
    
    string get_nombre () { 
       return nombre;
}
    float get_precio () { 
        return precio;

 
}
    float calcular_precio (){
        return mili;
    }

    string to_string();
    void imprime();

};

    


string bebida :: to_string (){
    stringstream aux ; 
    aux << "La bebida es " << nombre << "contiene " << mili<< "mililitros y su precio es de " << precio << "pesos" "\n"; 
    return aux.str ();

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Declaracion de la clase postre  


class postre : public plato { 

    private : 

    int calorias ; 

    public : 

    postre  ();
    postre (string nom, float pre, int cal);

        string to_string();

};

string postre :: to_string (){
    stringstream aux ; 
    aux << "El postre es " << nombre << "y su precio es de" <<precio<< "\n";
    return aux.str ();


}

class plato_principal :public plato{
    private : 

    string proteina; 

    public : 

    plato_principal () ; 
    plato_principal (string nom, float pre, string prote);

        string to_string();

};

string plato_principal :: to_string (){ 
    stringstream aux ; 
    aux << "EL plato principal es" << nombre << "va acompañado de " << proteina << "Y su precio es de" << precio<< "\n";
    return aux.str (); 
}




#endif