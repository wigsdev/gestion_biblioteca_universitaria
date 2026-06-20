#include <iostream>
#include <string>
#include "estructuras.h"
#include "libros.h"
#include "busquedas.h"
#include "ordenamientos.h"
#include "prestamos.h"
#include "historial.h"
#include "recursividad.h"

using namespace std;

// Punteros globales para controlar las estructuras
NodoLibro* catalogoCabeza = nullptr; // Módulo 1 (Lista Doble) - Víctor
NodoLibro* catalogoCola = nullptr;   // Módulo 1 (Lista Doble) - Víctor

NodoPrestamo* prestamosFrente = nullptr; // Módulo 4 (Cola) - Wilmer
NodoPrestamo* prestamosFin = nullptr;    // Módulo 4 (Cola) - Wilmer

NodoOperacion* historialCima = nullptr;  // Módulo 5 (Pila) - Wilmer

// ==============================================================================
// MENÚS Y SUBMENÚS
// ==============================================================================
void menuPrincipal() {
    cout << "\n==========================================" << endl;
    cout << "  SISTEMA DE BIBLIOTECA UNIVERSITARIA C++  " << endl;
    cout << "==========================================" << endl;
    cout << "1. Gestión de Libros (Lista Doble)" << endl;
    cout << "2. Búsquedas en Catálogo" << endl;
    cout << "3. Ordenar Catálogo" << endl;
    cout << "4. Gestión de Préstamos (Cola FIFO)" << endl;
    cout << "5. Historial de Operaciones (Pila y Deshacer)" << endl;
    cout << "6. Reportes y Consultas Recursivas" << endl;
    cout << "7. Salir del Sistema" << endl;
    cout << "Selecciona una opción: ";
}

void submenuLibros() {
    cout << "\n------------------------------------------" << endl;
    cout << "           GESTIÓN DE LIBROS" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Registrar nuevo libro" << endl;
    cout << "2. Modificar libro (por Código)" << endl;
    cout << "3. Eliminar libro (por Código)" << endl;
    cout << "4. Mostrar catálogo (Adelante)" << endl;
    cout << "5. Mostrar catálogo (Atrás)" << endl;
    cout << "6. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuBusquedas() {
    cout << "\n------------------------------------------" << endl;
    cout << "         BÚSQUEDAS EN EL CATÁLOGO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Buscar por Título (Secuencial)" << endl;
    cout << "2. Buscar por Autor (Secuencial)" << endl;
    cout << "3. Buscar por Código (Binaria)" << endl;
    cout << "4. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuOrdenamientos() {
    cout << "\n------------------------------------------" << endl;
    cout << "            ORDENAR CATÁLOGO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Ordenar por Título (Burbuja)" << endl;
    cout << "2. Ordenar por Autor (Selección)" << endl;
    cout << "3. Ordenar por Año (Inserción)" << endl;
    cout << "4. Ordenar por Código (Quick Sort)" << endl;
    cout << "5. Ordenar por Cantidad Disponible (Merge Sort)" << endl;
    cout << "6. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuPrestamos() {
    cout << "\n------------------------------------------" << endl;
    cout << "           GESTIÓN DE PRÉSTAMOS" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Encolar solicitud de préstamo" << endl;
    cout << "2. Atender solicitud (Desencolar)" << endl;
    cout << "3. Mostrar cola de solicitudes" << endl;
    cout << "4. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuHistorial() {
    cout << "\n------------------------------------------" << endl;
    cout << "          HISTORIAL DE OPERACIONES" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Ver historial completo (Pila)" << endl;
    cout << "2. Deshacer última operación (Undo)" << endl;
    cout << "3. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

void submenuReportes() {
    cout << "\n------------------------------------------" << endl;
    cout << "        REPORTES Y ESTADÍSTICAS RECURSIVAS" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Mostrar catálogo recursivamente" << endl;
    cout << "2. Contar cantidad total de libros recursivamente" << endl;
    cout << "3. Buscar libro por código recursivamente" << endl;
    cout << "4. Volver al menú principal" << endl;
    cout << "Selecciona una opción: ";
}

// ==============================================================================
// FUNCIÓN PRINCIPAL
// ==============================================================================
int main() {
    int opcionPrincipal;

    do {
        menuPrincipal();
        if (!(cin >> opcionPrincipal)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (opcionPrincipal) {
            case 1: { // GESTIÓN DE LIBROS (Integrante 2 - Víctor)
                int op;
                do {
                    submenuLibros();
                    cin >> op;
                    switch (op) {
                        case 1: {
                            Libro nuevo;
                            cout << "Ingrese Código del Libro: "; cin >> nuevo.codigo;
                            cout << "Ingrese Título: "; cin.ignore(); getline(cin, nuevo.titulo);
                            cout << "Ingrese Autor: "; getline(cin, nuevo.autor);
                            cout << "Ingrese Año: "; cin >> nuevo.anio;
                            cout << "Ingrese Cantidad Disponible: "; cin >> nuevo.cantidadDisponible;
                            
                            // LLAMADA INTEGRANTE 2:
                            registrarLibro(catalogoCabeza, catalogoCola, nuevo);
                            
                            // Módulo 5 (Wilmer): Registrar operación en pila
                            Operacion opReg;
                            opReg.tipo = REGISTRAR_LIBRO;
                            opReg.libroOriginal = nuevo;
                            opReg.descripcion = "Registro de libro: " + nuevo.titulo;
                            pushOperacion(historialCima, opReg);
                            break;
                        }
                        case 2: {
                            int cod;
                            cout << "Ingrese el código del libro a modificar: "; cin >> cod;
                            // Buscar primero el libro actual
                            NodoLibro* encontrado = buscarLibroRecursivo(catalogoCabeza, cod);
                            if (encontrado != nullptr) {
                                Libro mod;
                                mod.codigo = cod;
                                cout << "Ingrese nuevo Título: "; cin.ignore(); getline(cin, mod.titulo);
                                cout << "Ingrese nuevo Autor: "; getline(cin, mod.autor);
                                cout << "Ingrese nuevo Año: "; cin >> mod.anio;
                                cout << "Ingrese nueva Cantidad: "; cin >> mod.cantidadDisponible;

                                // Módulo 5 (Wilmer): Guardar respaldo antes de modificar
                                Operacion opMod;
                                opMod.tipo = MODIFICAR_LIBRO;
                                opMod.libroOriginal = encontrado->dato; // Guardamos el estado anterior
                                opMod.descripcion = "Modificación de libro: " + encontrado->dato.titulo;
                                pushOperacion(historialCima, opMod);

                                // LLAMADA INTEGRANTE 2:
                                modificarLibro(catalogoCabeza, cod, mod);
                            } else {
                                cout << ">> [ERROR] Libro no encontrado." << endl;
                            }
                            break;
                        }
                        case 3: {
                            int cod;
                            cout << "Ingrese el código del libro a eliminar: "; cin >> cod;
                            NodoLibro* encontrado = buscarLibroRecursivo(catalogoCabeza, cod);
                            if (encontrado != nullptr) {
                                // Módulo 5 (Wilmer): Guardar copia de respaldo para deshacer (Undo)
                                Operacion opDel;
                                opDel.tipo = ELIMINAR_LIBRO;
                                opDel.libroOriginal = encontrado->dato;
                                opDel.descripcion = "Eliminación de libro: " + encontrado->dato.titulo;
                                pushOperacion(historialCima, opDel);

                                // LLAMADA INTEGRANTE 2:
                                eliminarLibro(catalogoCabeza, catalogoCola, cod);
                                cout << ">> Libro eliminado exitosamente." << endl;
                            } else {
                                cout << ">> [ERROR] Libro no encontrado." << endl;
                            }
                            break;
                        }
                        case 4:
                            mostrarCatalogo(catalogoCabeza, true);
                            break;
                        case 5:
                            mostrarCatalogo(catalogoCabeza, false);
                            break;
                    }
                } while (op != 6);
                break;
            }
            case 2: { // BÚSQUEDAS (Integrante 1 - Javier)
                int op;
                do {
                    submenuBusquedas();
                    cin >> op;
                    switch (op) {
                        case 1: {
                            string tit;
                            cout << "Ingrese Título a buscar: "; cin.ignore(); getline(cin, tit);
                            NodoLibro* res = buscarPorTitulo(catalogoCabeza, tit);
                            if (res != nullptr) {
                                cout << "\nLibro encontrado:" << endl;
                                cout << "Código: " << res->dato.codigo << " | Título: " << res->dato.titulo 
                                     << " | Autor: " << res->dato.autor << " | Año: " << res->dato.anio 
                                     << " | Cantidad: " << res->dato.cantidadDisponible << endl;
                            } else {
                                cout << ">> Libro no encontrado." << endl;
                            }
                            break;
                        }
                        case 2: {
                            string aut;
                            cout << "Ingrese Autor a buscar: "; cin.ignore(); getline(cin, aut);
                            NodoLibro* res = buscarPorAutor(catalogoCabeza, aut);
                            if (res != nullptr) {
                                cout << "\nLibro encontrado:" << endl;
                                cout << "Código: " << res->dato.codigo << " | Título: " << res->dato.titulo 
                                     << " | Autor: " << res->dato.autor << " | Año: " << res->dato.anio 
                                     << " | Cantidad: " << res->dato.cantidadDisponible << endl;
                            } else {
                                cout << ">> Libro no encontrado." << endl;
                            }
                            break;
                        }
                        case 3: {
                            int cod;
                            cout << "Ingrese Código a buscar: "; cin >> cod;
                            // Nota: Exige ordenar el catálogo por Código antes de buscar
                            NodoLibro* res = buscarPorCodigoBinaria(catalogoCabeza, cod);
                            if (res != nullptr) {
                                cout << "\nLibro encontrado (Búsqueda Binaria):" << endl;
                                cout << "Código: " << res->dato.codigo << " | Título: " << res->dato.titulo 
                                     << " | Autor: " << res->dato.autor << " | Año: " << res->dato.anio 
                                     << " | Cantidad: " << res->dato.cantidadDisponible << endl;
                            } else {
                                cout << ">> Libro no encontrado. Verifique que el catálogo esté ordenado por Código." << endl;
                            }
                            break;
                        }
                    }
                } while (op != 4);
                break;
            }
            case 3: { // ORDENAR CATÁLOGO (Todos los Integrantes)
                int op;
                do {
                    submenuOrdenamientos();
                    cin >> op;
                    switch (op) {
                        case 1:
                            ordenarPorTituloBurbuja(catalogoCabeza);
                            cout << ">> Catálogo ordenado por Título (Burbuja)." << endl;
                            break;
                        case 2:
                            ordenarPorAutorSeleccion(catalogoCabeza);
                            cout << ">> Catálogo ordenado por Autor (Selección)." << endl;
                            break;
                        case 3:
                            ordenarPorAnioInsercion(catalogoCabeza);
                            cout << ">> Catálogo ordenado por Año (Inserción)." << endl;
                            break;
                        case 4:
                            ordenarPorCodigoQuickSort(catalogoCabeza, catalogoCola);
                            cout << ">> Catálogo ordenado por Código (Quick Sort)." << endl;
                            break;
                        case 5:
                            ordenarPorCantidadMergeSort(catalogoCabeza, catalogoCola);
                            cout << ">> Catálogo ordenado por Cantidad Disponible (Merge Sort)." << endl;
                            break;
                    }
                } while (op != 6);
                break;
            }
            case 4: { // GESTIÓN DE PRÉSTAMOS (Integrante 3 - Wilmer)
                int op;
                do {
                    submenuPrestamos();
                    cin >> op;
                    switch (op) {
                        case 1: {
                            Prestamo p;
                            cout << "Ingrese Código de Préstamo: "; cin >> p.codigoPrestamo;
                            cout << "Ingrese Nombre del Alumno: "; cin.ignore(); getline(cin, p.alumno);
                            cout << "Ingrese Código del Libro solicitado: "; cin >> p.codigoLibro;
                            cout << "Ingrese Fecha (DD/MM/AAAA): "; cin.ignore(); getline(cin, p.fecha);

                            encolarSolicitud(prestamosFrente, prestamosFin, p);
                            cout << ">> Solicitud de préstamo encolada exitosamente." << endl;
                            break;
                        }
                        case 2: {
                            if (prestamosFrente == nullptr) {
                                cout << ">> No hay solicitudes de préstamo en lista de espera." << endl;
                            } else {
                                // Procesar la solicitud desencolando
                                Prestamo atendido = desencolarSolicitud(prestamosFrente, prestamosFin);
                                NodoLibro* lib = buscarLibroRecursivo(catalogoCabeza, atendido.codigoLibro);
                                if (lib != nullptr && lib->dato.cantidadDisponible > 0) {
                                    lib->dato.cantidadDisponible--;
                                    
                                    // Guardar en historial
                                    Operacion opPres;
                                    opPres.tipo = REALIZAR_PRESTAMO;
                                    opPres.prestamoOriginal = atendido;
                                    opPres.descripcion = "Préstamo concedido de: " + lib->dato.titulo + " a " + atendido.alumno;
                                    pushOperacion(historialCima, opPres);
                                    
                                    cout << ">> Préstamo de \"" << lib->dato.titulo << "\" entregado a " << atendido.alumno << endl;
                                } else {
                                    cout << ">> [ERROR] El libro no existe o no tiene stock disponible." << endl;
                                }
                            }
                            break;
                        }
                        case 3:
                            mostrarCola(prestamosFrente);
                            break;
                    }
                } while (op != 4);
                break;
            }
            case 5: { // HISTORIAL Y DESHACER (Integrante 3 - Wilmer)
                int op;
                do {
                    submenuHistorial();
                    cin >> op;
                    switch (op) {
                        case 1:
                            mostrarHistorial(historialCima);
                            break;
                        case 2:
                            deshacerUltimaOperacion(historialCima, catalogoCabeza, catalogoCola);
                            break;
                    }
                } while (op != 3);
                break;
            }
            case 6: { // REPORTES RECURSIVOS (Integrante 2 - Víctor)
                int op;
                do {
                    submenuReportes();
                    cin >> op;
                    switch (op) {
                        case 1:
                            cout << "\n--- Catálogo de Libros (Recursivo) ---" << endl;
                            mostrarRecursivo(catalogoCabeza);
                            break;
                        case 2: {
                            int total = contarLibrosRecursivo(catalogoCabeza);
                            cout << ">> Total de libros registrados recursivamente: " << total << endl;
                            break;
                        }
                        case 3: {
                            int cod;
                            cout << "Ingrese código de libro a buscar recursivamente: "; cin >> cod;
                            NodoLibro* res = buscarLibroRecursivo(catalogoCabeza, cod);
                            if (res != nullptr) {
                                cout << "\nLibro encontrado recursivamente:" << endl;
                                cout << "Código: " << res->dato.codigo << " | Título: " << res->dato.titulo 
                                     << " | Autor: " << res->dato.autor << endl;
                            } else {
                                cout << ">> Libro no encontrado recursivamente." << endl;
                            }
                            break;
                        }
                    }
                } while (op != 4);
                break;
            }
            case 7:
                cout << "\nSaliendo del sistema..." << endl;
                break;
            default:
                cout << "\nOpción inválida." << endl;
        }
    } while (opcionPrincipal != 7);

    return 0;
}
