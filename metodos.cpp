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

void ListaSimple::imprimir(void)
{
     NodoHijo *tmp = primerNodo;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           tmp->hijo->imprimir();
           tmp = tmp->siguiente;
     }
     cout << endl;
}

double ListaDoble::PromedioFrecuenciaDeHobby(string hobby){
    
}
