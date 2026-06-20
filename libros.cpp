#include "libros.h"
#include <iostream>

using namespace std;

// --- VÍCTOR (Integrante 2) - MÓDULO 1: GESTIÓN DE LIBROS (LISTA DOBLE) ---

void registrarLibro(NodoLibro* &cabeza, NodoLibro* &cola, Libro nuevo) {
    // TODO: Víctor (Integrante 2) debe implementar la inserción al final de la lista doble.
}

void mostrarCatalogo(NodoLibro* cabeza, bool adelante) {
    // TODO: Víctor (Integrante 2) debe implementar el recorrido de la lista.
    // Si adelante es true, de cabeza a cola; si es false, de cola a cabeza.
}

void eliminarLibro(NodoLibro* &cabeza, NodoLibro* &cola, int codigo) {
    // TODO: Víctor (Integrante 2) debe implementar la eliminación reconectando anterior y siguiente.
}

void modificarLibro(NodoLibro* cabeza, int codigo, Libro modificado) {
    // TODO: Víctor (Integrante 2) debe implementar la localización y modificación de datos.
}
