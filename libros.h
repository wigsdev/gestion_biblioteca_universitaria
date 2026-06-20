#ifndef LIBROS_H
#define LIBROS_H

#include "estructuras.h"

// --- VÍCTOR (Integrante 2) - MÓDULO 1: GESTIÓN DE LIBROS (LISTA DOBLE) ---
void registrarLibro(NodoLibro* &cabeza, NodoLibro* &cola, Libro nuevo);
void mostrarCatalogo(NodoLibro* cabeza, bool adelante = true);
void eliminarLibro(NodoLibro* &cabeza, NodoLibro* &cola, int codigo);
void modificarLibro(NodoLibro* cabeza, int codigo, Libro modificado);

#endif
