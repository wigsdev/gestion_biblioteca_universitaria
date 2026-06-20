#include "prestamos.h"
#include <iostream>

using namespace std;

// --- WILMER (Integrante 3) - MÓDULO 4: GESTIÓN DE PRÉSTAMOS (COLA FIFO) ---

void encolarSolicitud(NodoPrestamo* &frente, NodoPrestamo* &fin, Prestamo p) {
    // TODO: Wilmer (Integrante 3) debe implementar encolar (push_back) al final de la cola.
}

Prestamo desencolarSolicitud(NodoPrestamo* &frente, NodoPrestamo* &fin) {
    // TODO: Wilmer (Integrante 3) debe implementar desencolar (pop_front) y liberar el nodo.
    Prestamo vacio = {0, "", 0, ""};
    return vacio;
}

void mostrarCola(NodoPrestamo* frente) {
    // TODO: Wilmer (Integrante 3) debe implementar la visualización de la cola.
}
