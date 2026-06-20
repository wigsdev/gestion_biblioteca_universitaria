#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

#include "estructuras.h"
#include <string>

// --- JAVIER (Integrante 1) - MÓDULO 2: BÚSQUEDAS (SECUENCIAL Y BINARIA) ---
NodoLibro* buscarPorTitulo(NodoLibro* cabeza, std::string titulo);
NodoLibro* buscarPorAutor(NodoLibro* cabeza, std::string autor);
NodoLibro* buscarPorCodigoBinaria(NodoLibro* cabeza, int codigo);

// Función auxiliar de normalización
std::string aMinusculas(std::string str);

#endif
