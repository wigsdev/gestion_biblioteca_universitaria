#include "historial.h"
#include "estructuras.h"
#include "libros.h"
#include <iostream>

using namespace std;

// --- WILMER (Integrante 3) - MÓDULO 5: HISTORIAL DE OPERACIONES ---

void pushOperacion(NodoOperacion* &cima, Operacion op) {
    // TODO: Wilmer (Integrante 3) debe implementar push en la pila.
    // 1. crear el nuevo nodo de memoria
    NodoOperacion* nuevoNodo = new NodoOperacion;

    // 2. inicializar el campo dato con la operacion
    nuevoNodo->dato = op;

    // 3. conectar el nuevo nodo con lo que ya estaba en la cima
    nuevoNodo->siguiente = cima;

    // 4. mover la cima al nuevo nodo
    cima = nuevoNodo;
}

void popOperacion(NodoOperacion* &cima) {
    // TODO: Wilmer (Integrante 3) debe implementar pop en la pila.
    // 1. validar si la pila está vacía
    if (cima == nullptr) {
        return;    
    }

    // 2. guardar la dirección del nodo del tope
    NodoOperacion* temp = cima;

    // 3. desplazar la cima al siguiente nodo 
    cima = cima->siguiente;

    // 4. liberar la memoria RAM del nodo desapilado
    delete temp;
}

Operacion topOperacion(NodoOperacion* cima) {
    // TODO: Wilmer (Integrante 3) debe implementar top en la pila.
    Operacion vacia = {REGISTRAR_LIBRO, {0, "", "", 0, 0}, {0, "", 0, ""}, "Vacía"};
    return vacia;
}

void mostrarHistorial(NodoOperacion* cima) {
    // TODO: Wilmer (Integrante 3) debe implementar mostrar la pila LIFO.
}

// Algoritmo de deshacer (Undo)
void deshacerUltimaOperacion(NodoOperacion* &cima, NodoLibro* &cabezaLibro, NodoLibro* &colaLibro) {
    // TODO: Wilmer (Integrante 3) debe implementar la lógica de Deshacer (Undo).
    // 1. Obtener cima.
    // 2. Dependiendo de op.tipo, revertir la acción (restaurar/eliminar/modificar/cambiar stock).
    // 3. Ejecutar popOperacion.
}
