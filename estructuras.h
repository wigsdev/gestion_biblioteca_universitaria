#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>

// Datos del libro
struct Libro {
    int codigo;
    std::string titulo;
    std::string autor;
    int anio;
    int cantidadDisponible;
};

// Nodo de la Lista Doblemente Enlazada (Víctor)
struct NodoLibro {
    Libro dato;
    NodoLibro* siguiente;
    NodoLibro* anterior;
};

// Datos del préstamo
struct Prestamo {
    int codigoPrestamo;
    std::string alumno;
    int codigoLibro;
    std::string fecha;
};

// Nodo de la Cola FIFO (Wilmer)
struct NodoPrestamo {
    Prestamo dato;
    NodoPrestamo* siguiente;
};

// Historial para operaciones (Pila)
enum TipoOperacion {
    REGISTRAR_LIBRO,
    ELIMINAR_LIBRO,
    MODIFICAR_LIBRO,
    REALIZAR_PRESTAMO,
    DEVOLVER_PRESTAMO
};

struct Operacion {
    TipoOperacion tipo;
    Libro libroOriginal;        // Datos de respaldo por si hay que deshacer
    Prestamo prestamoOriginal;  // Datos de respaldo por si hay que deshacer
    std::string descripcion;
};

// Nodo de la Pila LIFO (Wilmer)
struct NodoOperacion {
    Operacion dato;
    NodoOperacion* siguiente;
};

#endif
