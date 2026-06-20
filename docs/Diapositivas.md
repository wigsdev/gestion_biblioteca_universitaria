# 🖥️ Presentación del Proyecto: Sistema de Gestión de Biblioteca Universitaria

---

## 🎴 DIAPOSITIVA 1: Portada e Integrantes
```text
┌──────────────────────────────────────────────────────────┐
│      SISTEMA DE GESTIÓN DE BIBLIOTECA UNIVERSITARIA      │
│  Estructuras de Datos y Algoritmos Avanzados en C++      │
├──────────────────────────────────────────────────────────┤
│  Autores y Asignación de Módulos (Alternancia de Roles): │
│  • Víctor         - Módulos 1, 6 y Quick Sort               │
│  • Javier Flores  - Módulos 2, Burbuja, Selección, Merge    │
│  • Wilmer (Líder) - Módulos 4, 5 e Inserción                │
└──────────────────────────────────────────────────────────┘
```

---

## 🎴 DIAPOSITIVA 2: Planteamiento del Problema
*   **Desafío**: Administrar de manera eficiente el flujo logístico de una biblioteca universitaria (registro de libros, préstamos FIFO, historial de auditoría y la posibilidad de deshacer operaciones).
*   **Restricciones (Rúbrica)**:
    *   ❌ Prohibido el uso de colecciones estándar (sin `vector`, `list`, `stack`, `queue`).
    *   ⚙️ Todo debe construirse desde cero utilizando memoria dinámica y punteros.
    *   📦 Modularización estricta (`.h` y `.cpp`).

---

## 🎴 DIAPOSITIVA 3: Arquitectura y Dependencias
*   **Núcleo de Datos**: `estructuras.h` define los structs comunes (`Libro`, `Prestamo`, `Operacion`).
*   **Distribución Modular**:
    *   `libros.h` / `.cpp`
    *   `busquedas.h` / `.cpp`
    *   `ordenamientos.h` / `.cpp`
    *   `prestamos.h` / `.cpp`
    *   `historial.h` / `.cpp`
    *   `recursividad.h` / `.cpp`
*   **Compilación**: Automatizada mediante `Makefile` (compilación incremental con `g++`).

---

## 🎴 DIAPOSITIVA 4: Módulo 1: Gestión de Libros
*   **Responsable**: Víctor
*   **Estructura**: Lista Doblemente Enlazada (`anterior` y `siguiente`).
*   **Razón de Selección**: Permite recorrer de forma eficiente el catálogo de libros en ambas direcciones (adelante y atrás).
*   **Datos Almacenados**: Código, Título, Autor, Año, Cantidad disponible.
*   **Operaciones**: Registrar libro, Modificar libro, Eliminar libro, Mostrar catálogo (bidireccional).

---

## 🎴 DIAPOSITIVA 5: Módulo 2: Búsquedas
*   **Responsable**: Javier Flores
*   **Búsqueda Secuencial ($O(N)$)**:
    *   **Buscar por Título**: Búsqueda secuencial case-insensitive sobre la lista doble.
    *   **Buscar por Autor**: Búsqueda secuencial case-insensitive sobre la lista doble.
*   **Búsqueda Binaria ($O(\log N)$)**:
    *   **Buscar por Código**: Búsqueda binaria.
    *   *Mecánica*: Vuelca temporalmente las referencias de la lista doble a un arreglo dinámico para permitir accesos aleatorios y divisiones logarítmicas de intervalos.

---

## 🎴 DIAPOSITIVA 6: Módulo 3: Ordenamiento
*   **Responsables**: Javier Flores, Víctor, Wilmer
*   Se implementan 5 algoritmos aplicados a diferentes criterios de orden:
    *   **Burbuja (Javier)**: Ordena **Por título** (alfabético ascendente, $O(N^2)$).
    *   **Selección (Javier)**: Ordena **Por autor** (alfabético ascendente, $O(N^2)$).
    *   **Merge Sort (Javier)**: Ordena **Por cantidad disponible** (descendente, $O(N \log N)$).
    *   **Quick Sort (Víctor)**: Ordena **Por código** (ascendente, $O(N \log N)$).
    *   **Inserción (Wilmer)**: Ordena **Por año** (ascendente, $O(N^2)$).

---

## 🎴 DIAPOSITIVA 7: Módulo 4: Gestión de Préstamos
*   **Responsable**: Wilmer (Líder)
*   **Estructura**: Cola FIFO (First-In, First-Out) implementada con punteros `frente` y `fin`.
*   **Operaciones del Módulo**:
    *   **Encolar solicitud**: Registra al alumno y el libro que solicita.
    *   **Atender solicitud**: Procesa el préstamo, descuenta la cantidad disponible en el catálogo y libera la solicitud atendida.
    *   **Mostrar cola**: Visualiza la fila de solicitudes pendientes.

---

## 🎴 DIAPOSITIVA 8: Módulo 5: Historial de Operaciones
*   **Responsable**: Wilmer (Líder)
*   **Estructura**: Pila LIFO (Last-In, First-Out) dinámica.
*   **Guardar / Información**: Registro histórico de cada acción (altas, bajas, préstamos y modificaciones).
*   **Lógica de Deshacer (Undo)**:
    *   Se consulta la cima (top) de la pila y se ejecuta el reverso de la operación:
        *   `REGISTRAR_LIBRO` $\rightarrow$ Elimina el libro registrado.
        *   `ELIMINAR_LIBRO` $\rightarrow$ Restaura el libro guardado en la copia de respaldo.
        *   `MODIFICAR_LIBRO` $\rightarrow$ Restaura el estado anterior del libro.
        *   `REALIZAR_PRESTAMO` $\rightarrow$ Cancela el préstamo (aumenta el stock).

---

## 🎴 DIAPOSITIVA 9: Módulo 6: Recursividad
*   **Responsable**: Víctor
*   Operaciones de consulta y reportes resueltas de forma 100% recursiva:
    *   **Mostrar catálogo recursivamente**: Imprime el libro actual y se autoinvoca con `nodo->siguiente`. Caso base: `nodo == nullptr`.
    *   **Contar libros recursivamente**: Retorna `1 + contarLibrosRecursivo(nodo->siguiente)`. Caso base: `nodo == nullptr` retorna 0.
    *   **Buscar libro recursivamente**: Caso base exitoso si `nodo->dato.codigo == codigo`; caso base de término si `nodo == nullptr`.

---

## 🎴 DIAPOSITIVA 10: Conclusiones
*   La separación de cabeceras e implementaciones (.h/.cpp) previene colisiones de símbolos y facilita la compilación limpia.
*   La alternancia de roles permitió a todos los integrantes programar nuevas estructuras de datos y algoritmos.
*   La pila LIFO con almacenamiento de estados permite implementar el sistema "Undo" de forma muy natural en C++.
*   **Demostración Práctica en Consola (Demo en Vivo)**.
