#include "historial.h"
#include "libros.h"
#include <iostream>

using namespace std;

// --- WILMER (Integrante 3) - MÓDULO 5: HISTORIAL DE OPERACIONES ---

void pushOperacion(NodoOperacion* &cima, Operacion op) {
    // TODO: Wilmer (Integrante 3) debe implementar push en la pila.
}

void popOperacion(NodoOperacion* &cima) {
    // TODO: Wilmer (Integrante 3) debe implementar pop en la pila.
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
