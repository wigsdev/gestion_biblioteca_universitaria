#ifndef PRESTAMOS_H
#define PRESTAMOS_H

#include "estructuras.h"

// --- WILMER (Integrante 3) - MÓDULO 4: GESTIÓN DE PRÉSTAMOS (COLA FIFO) ---
void encolarSolicitud(NodoPrestamo* &frente, NodoPrestamo* &fin, Prestamo p);
Prestamo desencolarSolicitud(NodoPrestamo* &frente, NodoPrestamo* &fin);
void mostrarCola(NodoPrestamo* frente);

#endif
