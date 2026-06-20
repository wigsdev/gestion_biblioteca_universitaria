#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "estructuras.h"

// --- WILMER (Integrante 3) - MÓDULO 5: HISTORIAL DE OPERACIONES (PILA LIFO Y UNDO) ---
void pushOperacion(NodoOperacion* &cima, Operacion op);
void popOperacion(NodoOperacion* &cima);
Operacion topOperacion(NodoOperacion* cima);
void mostrarHistorial(NodoOperacion* cima);

// Algoritmo de deshacer (Undo)
void deshacerUltimaOperacion(NodoOperacion* &cima, NodoLibro* &cabezaLibro, NodoLibro* &colaLibro);

#endif
