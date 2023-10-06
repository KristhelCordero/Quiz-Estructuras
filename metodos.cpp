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
    if (primerNodo==NULL)
        return 0;
    double cantidadHijosPractican;
    double sumaVecesPracticado;
    while (tmp != NULL){
        cantidadHijosPractican+=tmp->cliente->hijos->cantidadHijosPractican(hobby);
        sumaVecesPracticado+=tmp->cliente->hijos->cantidadVecesPorSemana(hobby);
        tmp = tmp->siguiente;
    }
    if (cantidadHijosPractican==0)
        return 0;
    else
        return sumaVecesPracticado/cantidadHijosPractican;
}


