#include "busquedas.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Función auxiliar de normalización
string aMinusculas(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// --- JAVIER (Integrante 1) - MÓDULO 2: BÚSQUEDAS ---

NodoLibro* buscarPorTitulo(NodoLibro* cabeza, string titulo) {
    // TODO: Javier (Integrante 1) debe implementar la búsqueda secuencial insensible a mayúsculas.
    return nullptr;
}

NodoLibro* buscarPorAutor(NodoLibro* cabeza, string autor) {
    // TODO: Javier (Integrante 1) debe implementar la búsqueda secuencial por autor.
    return nullptr;
}

NodoLibro* buscarPorCodigoBinaria(NodoLibro* cabeza, int codigo) {
    // TODO: Javier (Integrante 1) debe implementar la búsqueda binaria.
    // Recuerda volcar primero las referencias de la lista doble a un arreglo temporal indexado.
    return nullptr;
}
