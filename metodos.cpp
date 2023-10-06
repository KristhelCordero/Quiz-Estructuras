#include "Estructuras.h"

void ListaSimple::insertar (Hijo * hijo)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         ultimoNodo = primerNodo = new NodoHijo(hijo);
     }
     else
     {
         NodoHijo *nuevo = new NodoHijo(hijo);
         nuevo->siguiente = primerNodo;
         primerNodo = nuevo; 
     }
}

void ListaSimple::imprimir(void){
     NodoHijo *tmp = primerNodo;
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL){
           tmp->hijo->imprimir();
           tmp = tmp->siguiente;
     }
     cout << endl;
}

double ListaSimple::cantidadHijosPractican(string hobby){
    NodoHijo * tmp= primerNodo;
    double contador;
    while (tmp != NULL){
        if (tmp->hijo->hobbies->exists(hobby))
            contador++;
        tmp = tmp->siguiente;
    }
    return contador;
}

double ListaSimple::cantidadVecesPorSemana(string hobby){
    NodoHijo * tmp= primerNodo;
    double sumaVecesPracticadoPorSemana;
    while (tmp != NULL){
        sumaVecesPracticadoPorSemana+=tmp->hijo->hobbies->cantidadDeVecesPracticado(hobby);
        tmp = tmp->siguiente;
    }
    return sumaVecesPracticadoPorSemana;
}

double ListaDoble::promedioFrecuenciaDeHobby(string hobby){
    Nodo * tmp= primerNodo;
    double cantidadHijosPractican;
    double sumaVecesPracticado;
    while (tmp != NULL){
        cantidadHijosPractican+=tmp->cliente->hijos->cantidadHijosPractican(hobby);
        cout<<cantidadHijosPractican<<endl;
        sumaVecesPracticado+=tmp->cliente->hijos->cantidadVecesPorSemana(hobby);
        cout<<sumaVecesPracticado<<endl;
        tmp = tmp->siguiente;
    }
    cout << "--------------------------------------------------"<<endl;
    if (cantidadHijosPractican==0)
        return 0;
    else
        return sumaVecesPracticado/cantidadHijosPractican;
}

void ListaSimpleHobbies::actualizarFrecuenciaHobby(string hobby, int frecuencia){
    NodoHobby *tmp = primerNodo;
    bool actualizado=false;
    Hobby * nuevoHobby;
	while (tmp != NULL){
		if (tmp->hobby->nombre == hobby){
            actualizado=true;
            tmp->hobby->cantidad+=frecuencia;
        } 
 		tmp = tmp->siguiente;
	}
    if (!actualizado){
        nuevoHobby=new Hobby(hobby, frecuencia);
        insertar(nuevoHobby);
    }
}

void ListaSimple::actualizarFrecuenciaHoobiesHijos(string nombre, string hobby, int frecuencia){
    NodoHijo * tmp= primerNodo;
    while (tmp != NULL){
        if (tmp->hijo->nombre==nombre){
            tmp->hijo->hobbies->actualizarFrecuenciaHobby(hobby, frecuencia);
        }
        tmp = tmp->siguiente;
    }
}

void ListaDoble::actualizarFrecuencia(string nombre, string hobby, int frecuencia){
    Nodo * tmp= primerNodo;
    while (tmp != NULL){
        tmp->cliente->hijos->actualizarFrecuenciaHoobiesHijos(nombre, hobby, frecuencia);
        tmp = tmp->siguiente;
    }
}


