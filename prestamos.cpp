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
    // 1. validar si la cola está vacía
    if (frente == nullptr) {
        return vacio;    
    }
    
    // 2. respaldar el dato del préstamo
    Prestamo prestamoAtendido = frente->dato;

    // 3. guarda la direccion del nodo del frente
    NodoPrestamo* temp = frente;

    // 4. desplazar el frente al siguiente elemento 
    frente = frente->siguiente;

    // 5. controlar si la cola quedó completamente vacía
    if (frente == nullptr) {
        fin = nullptr;    
    }
    
    // 6. liberar la memoria física del nodo viejo (RAM)
    delete temp;

    // 7. retornar el prestamo respaldado
    return prestamoAtendido;
}

void mostrarCola(NodoPrestamo* frente) {
    // TODO: Wilmer (Integrante 3) debe implementar la visualización de la cola.
    // 1. validar si la cola está vacía
    if (frente == nullptr) {
        cout << "La de préstamos está vacía." << endl;
        return;    
    }

    // 2. crear puntero auxiliar
    NodoPrestamo* actual = frente;

    cout << " === SOLICITUDES DE PRÉSTAMO PENDIENTES ===" << endl;

    // 3. Recorrer los nodos
    while (actual != nullptr) {
        // 4. mostrar datos
        cout << "Código préstamo: " << actual->dato.codigoPrestamo << endl;
        cout << "Alumno: " << actual->dato.alumno << endl;
        cout << "Código Libro: " << actual->dato.codigoLibro << endl;
        cout << "Fecha: " << actual->dato.fecha << endl;
        cout << "--------------------------" << endl;

        // 5. avanzar el puntero
        actual = actual->siguiente;        
    }
}
