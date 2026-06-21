#include "prestamos.h"
#include "estructuras.h"
#include <iostream>

using namespace std;

// --- WILMER (Integrante 3) - MÓDULO 4: GESTIÓN DE PRÉSTAMOS (COLA FIFO) ---

void encolarSolicitud(NodoPrestamo* &frente, NodoPrestamo* &fin, Prestamo p) {
    // TODO: Wilmer (Integrante 3) debe implementar encolar (push_back) al final de la cola.
    // 1. crear el nuevo nodo
    NodoPrestamo* nuevoNodo = new NodoPrestamo();
    nuevoNodo->dato = p;
    nuevoNodo->siguiente = nullptr;

    // 2. insertar en la cola
    if (frente == nullptr) {
        // si la cola está vacía, el nuevo nodo es tanto el frente como el fin
        frente = nuevoNodo;
        fin = nuevoNodo;    
    } else {
        // si no está vacía, se enlaza al final de la cola y se actualiza el puntero fin
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
}

Prestamo desencolarSolicitud(NodoPrestamo* &frente, NodoPrestamo* &fin) {
    // TODO: Wilmer (Integrante 3) debe implementar desencolar (pop_front) y liberar el nodo.
    Prestamo vacio = {0, "", 0, ""};
    return vacio;
}

void mostrarCola(NodoPrestamo* frente) {
    // TODO: Wilmer (Integrante 3) debe implementar la visualización de la cola.
}
