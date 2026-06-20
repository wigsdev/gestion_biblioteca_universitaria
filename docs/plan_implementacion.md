# 📚 Plan de Implementación - Sistema de Gestión de Biblioteca Universitaria

Este documento define la arquitectura, diseño de datos y distribución de tareas del **Sistema de Gestión de Biblioteca Universitaria** en C++. La asignación de módulos se ha realizado bajo una **estrategia de alternancia de roles** para evitar repetir los temas trabajados por cada integrante en el proyecto anterior.

---

## 🏗️ Estructura del Proyecto

El código fuente se organizará de forma modular para evitar conflictos de merge en Git:

```
📂 gestion_biblioteca_universitaria/
├── 📂 docs/                      # Documentación técnica y guías del equipo
├── 📄 .gitignore                 # Exclusiones de Git
├── 📄 Makefile                   # Automatización de la compilación
├── 📄 estructuras.h              # Definiciones comunes de structs y nodos
├── 📄 libros.h / libros.cpp      # Módulo 1 (Lista Doblemente Enlazada) - Víctor
├── 📄 busquedas.h / busquedas.cpp # Módulo 2 (Búsquedas Secuencial/Binaria) - Javier
├── 📄 ordenamientos.h / ...      # Módulo 3 (Ordenamientos) - Todos (Javier/Víctor/Wilmer)
├── 📄 prestamos.h / ...          # Módulo 4 (Cola de Préstamos) - Wilmer
├── 📄 historial.h / ...          # Módulo 5 (Pila de Historial y Deshacer) - Wilmer
├── 📄 recursividad.h / ...       # Módulo 6 (Recursividad) - Víctor
└── 📄 main.cpp                   # Menú principal interactivo
```

---

## 🗂️ Distribución y Asignación de Tareas

A continuación se presenta la tabla resumen de la carga de trabajo y el detalle de las funciones asignadas a cada desarrollador.

### 📊 Tabla Resumen de Carga de Trabajo

| Integrante | Módulos Asignados | Estructuras de Datos / Algoritmos | Archivos Asociados | Complejidad |
| :--- | :--- | :--- | :--- | :--- |
| **Javier** (Int. 1) | M2: Búsquedas<br>M3: Ordenamientos (Parte A) | - Búsqueda Secuencial (Título/Autor)<br>- Búsqueda Binaria (Código)<br>- Burbuja (Título)<br>- Selección (Autor)<br>- Merge Sort (Cantidad) | `busquedas.h`/`.cpp`<br>`ordenamientos.h`/`.cpp` | **Medio** |
| **Víctor** (Int. 2) | M1: Gestión de Libros<br>M6: Recursividad<br>M3: Ordenamientos (Parte B) | - Lista Doblemente Enlazada (CRUD)<br>- Mostrar, contar y buscar recursivo<br>- Quick Sort (Código) | `libros.h`/`.cpp`<br>`recursividad.h`/`.cpp`<br>`ordenamientos.h`/`.cpp` | **Alto** |
| **Wilmer** (Int. 3 - Líder) | M4: Cola de Préstamos<br>M5: Historial y Undo<br>M3: Ordenamientos (Parte C) | - Cola FIFO (Solicitudes)<br>- Pila LIFO (Historial)<br>- Algoritmo de Deshacer (Undo)<br>- Inserción (Año) | `prestamos.h`/`.cpp`<br>`historial.h`/`.cpp`<br>`ordenamientos.h`/`.cpp` | **Alto** |

---

### Detalle de Funciones por Integrante

### 🧑‍💻 Integrante 1: Javier
*   **Módulo 2: Búsquedas**:
    *   Búsqueda secuencial por **Título** (insensible a mayúsculas/minúsculas).
    *   Búsqueda secuencial por **Autor** (insensible a mayúsculas/minúsculas).
    *   Búsqueda binaria por **Código** (sobre catálogo previamente ordenado).
*   **Módulo 3 (Parte A): Ordenamientos**:
    *   **Burbuja (Bubble Sort)**: Ordenar por **Título** (ascendente, alfabético).
    *   **Selección (Selection Sort)**: Ordenar por **Autor** (ascendente, alfabético).
    *   **Merge Sort**: Ordenar por **Cantidad disponible** (descendente, alfabético).
*   **Archivos asignados**: `busquedas.h`, `busquedas.cpp`, y funciones en `ordenamientos.h`/`ordenamientos.cpp`.

---

### 🧑‍💻 Integrante 2: Víctor
*   **Módulo 1: Gestión de Libros**:
    *   Implementación de **Lista Doblemente Enlazada** (`anterior` y `siguiente`).
    *   Funciones: Registrar libro (inserción), Modificar libro (localizar y editar), Eliminar libro (liberar memoria y re-enlazar punteros), Mostrar catálogo (recorrido bidireccional).
*   **Módulo 6: Recursividad**:
    *   Mostrar catálogo recursivamente.
    *   Contar cantidad total de libros recursivamente.
    *   Buscar libro recursivamente por código.
*   **Módulo 3 (Parte B): Ordenamientos**:
    *   **Quick Sort**: Ordenar por **Código** (ascendente).
*   **Archivos asignados**: `libros.h`, `libros.cpp`, `recursividad.h`, `recursividad.cpp`, y funciones en `ordenamientos.h`/`ordenamientos.cpp`.

---

### 🧑‍💻 Integrante 3: Wilmer (Líder)
*   **Módulo 4: Gestión de Préstamos**:
    *   Implementación de **Cola FIFO** para fila de solicitudes de libros.
    *   Funciones: Encolar solicitud, Atender solicitud (desencolar y reducir cantidad de libros), Mostrar cola de solicitudes.
*   **Módulo 5: Historial de Operaciones**:
    *   Implementación de **Pila LIFO** dinámica.
    *   Funciones: Registrar acción (push), Desapilar (pop), Consultar última (top).
    *   **Lógica de Deshacer (Undo)**: Revertir la última acción realizada (si se registró un libro, eliminarlo; si se eliminó, restaurarlo; si se realizó un préstamo, devolver el libro y reencolar).
*   **Módulo 3 (Parte C): Ordenamientos**:
    *   **Inserción (Insertion Sort)**: Ordenar por **Año** (ascendente).
*   **Archivos asignados**: `prestamos.h`, `prestamos.cpp`, `historial.h`, `historial.cpp`, y funciones en `ordenamientos.h`/`ordenamientos.cpp`.

---

## 📦 Definición de Datos Comunes (`estructuras.h`)

Todos los módulos dependerán de un único archivo de estructuras para evitar referencias circulares. Las estructuras detalladas están disponibles en el archivo [estructuras.h](../estructuras.h).

---

## 🛠️ Plan de Compilación (Makefile)

El compilador GCC enlazará todos los módulos resultantes mediante el siguiente script incremental (disponible en [Makefile](../Makefile)):

```makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = biblioteca

SRCS = main.cpp libros.cpp busquedas.cpp ordenamientos.cpp prestamos.cpp historial.cpp recursividad.cpp
HEADERS = estructuras.h libros.h busquedas.h ordenamientos.h prestamos.h historial.h recursividad.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe
```
