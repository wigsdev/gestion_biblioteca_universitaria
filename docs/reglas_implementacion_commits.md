# 🏛️ Reglas de Implementación y Guía de Conventional Commits

Este documento, redactado desde la perspectiva de la **Arquitectura de Software**, establece los estándares de calidad de código C++ y las directrices de control de versiones que los integrantes deben cumplir obligatoriamente para este proyecto.

---

## 🛠️ 1. Estándares y Reglas de Codificación en C++

Para asegurar la robustez de un sistema que trabaja directamente sobre memoria dinámica (RAM) sin abstracciones de alto nivel (sin STL), debemos regirnos por las siguientes reglas:

### A. Gestión de Memoria Dinámica Segura (Cero Memory Leaks)
*   **Regla de Emparejamiento**: Todo bloque de memoria solicitado con `new` debe ser liberado explícitamente con su correspondiente `delete` (o `delete[]` para arreglos).
*   **Punteros Huérfanos**: Al realizar un `delete`, la dirección apuntada queda invalidada pero el puntero sigue apuntando a ella (puntero dangling). Es **obligatorio** reasignar el puntero a `nullptr` inmediatamente después de liberarlo:
    ```cpp
    delete nodo;
    nodo = nullptr;
    ```
*   **Verificación Previa**: Antes de acceder a los miembros de cualquier puntero (`nodo->dato`), debes comprobar que no sea nulo:
    ```cpp
    if (nodo != nullptr) {
        // Acceso seguro
    }
    ```

### B. Convención de Nombres (Naming Conventions)
*   **Clases y Estructuras (Structs)**: Uso de **PascalCase** (ej. `NodoLibro`, `Prestamo`).
*   **Funciones y Variables**: Uso de **camelCase** (ej. `registrarLibro`, `catalogoCabeza`, `cantidadDisponible`).
*   **Constantes y Enums**: Uso de **UPPERCASE** con guiones bajos (ej. `REGISTRAR_LIBRO`, `MAX_TITLE_LENGTH`).

### C. Eficiencia en el Paso de Parámetros
*   **Paso por Referencia (`&`)**: Para evitar copias innecesarias de objetos grandes en la pila de llamadas (lo cual degrada el rendimiento), pasa los `std::string` y `structs` grandes por referencia constante si no van a ser modificados:
    ```cpp
    void buscarPorAutor(NodoLibro* cabeza, const std::string& autor);
    ```
*   **Punteros por Referencia (`*&`)**: Si una función necesita modificar el puntero original (por ejemplo, al cambiar la cabeza de una lista en la inserción o eliminación), debes pasar el puntero por referencia:
    ```cpp
    void registrarLibro(NodoLibro* &cabeza, NodoLibro* &cola, Libro nuevo);
    ```

### D. Const-Correctness
*   Marca como `const` cualquier parámetro o variable local que no deba cambiar su valor a lo largo de la ejecución de la función. Esto ayuda al compilador a optimizar el código y previene errores lógicos involuntarios.

---

## 🐙 2. Estándar de Conventional Commits

El historial del repositorio debe contar una historia limpia y comprensible. Adoptamos la especificación internacional de **Conventional Commits**:

### Estructura del Mensaje de Commit:
```text
<tipo>(<módulo/alcance>): <descripción corta en minúsculas y en imperativo>

[cuerpo opcional detallando el porqué del cambio]
```

### Tipos de Commits Permitidos (`<tipo>`):
*   `feat`: Incorporación de una nueva funcionalidad ejecutable (ej. añadir código de ordenamiento).
*   `fix`: Corrección de un error o bug en el código de producción.
*   `docs`: Cambios exclusivos en la documentación o guías (ej. archivos `.md`).
*   `style`: Formateo estético del código (espaciados, tabulaciones, nombres de variables) sin alterar su comportamiento lógico.
*   `refactor`: Modificación del código que no corrige un error ni añade una característica (reorganizar lógica).
*   `perf`: Mejoras de rendimiento o de consumo de memoria RAM.
*   `chore`: Mantenimiento general, cambios en el `Makefile`, `.gitignore`, o tareas de configuración.

### Ejemplos Prácticos de Commits en el Proyecto:
```bash
# Integrante 1 (Javier) - Nueva característica
git commit -m "feat(busquedas): implementar busqueda binaria sobre arreglo indexado"

# Integrante 2 (Víctor) - Corrección de bug
git commit -m "fix(libros): corregir reconexion de puntero anterior al borrar la cola de la lista"

# Integrante 3 (Wilmer) - Refactorización de código
git commit -m "refactor(historial): simplificar switch de reversión en el motor undo"

# Cambios generales de documentación
git commit -m "docs(diapositivas): alinear integrantes y algoritmos en la presentacion"
```

---

## 🏛️ 3. Propuesta de Arquitectura: Escalabilidad y Robustez

Como arquitecto de software, identifico los siguientes puntos críticos que debemos añadir para llevar este miniproyecto a un nivel de **grado de producción (industrial)**:

### 1. Sistema de Pruebas Unitarias Integradas (Unit Testing)
*   **Qué falta**: Actualmente dependemos de que el usuario interactúe con la consola para comprobar si los algoritmos funcionan.
*   **Solución**: Crear un módulo `pruebas.cpp` / `pruebas.h` que automatice la inserción, ordenamiento y búsquedas con conjuntos de datos conocidos, comprobando con `assert` que el resultado sea correcto. Se agregaría un target `make test` al `Makefile`.

### 2. Gestión Avanzada y Prevención de Fugas de Memoria (Leaks)
*   **Qué falta**: No tenemos una forma automatizada de verificar si al cerrar el programa quedaron nodos sin liberar.
*   **Solución**:
    *   Implementar un destructor global o función `limpiarMemoria()` que barra todas las listas, colas y pilas liberándolas al salir del programa.
    *   Integrar pruebas de análisis dinámico usando herramientas como **Valgrind** o **AddressSanitizer** (`-fsanitize=address` en las flags de compilación del `Makefile`) para capturar fallos de segmentación y leaks en tiempo de compilación.

### 3. Persistencia de Datos (Serialización de Archivos)
*   **Qué falta**: Al cerrar la aplicación, todo el catálogo y préstamos se pierden al estar únicamente en RAM.
*   **Solución**: Diseñar funciones de persistencia utilizando flujos de archivos (`fstream` de C++) para exportar e importar los datos de libros y préstamos a archivos CSV o binarios (`catalogo.csv` y `prestamos.csv`) al iniciar y cerrar la aplicación.

### 4. Manejo de Excepciones y Validación de Datos Robusta
*   **Qué falta**: Si un usuario ingresa una letra en un campo entero (como en el año o código), el flujo de entrada de consola (`cin`) se corrompe y entra en un bucle infinito.
*   **Solución**: Crear una capa de validación de entradas (`entrada.h`/`entrada.cpp`) con funciones como `leerEntero()` y `leerCadena()` que manejen errores de conversión (`cin.fail()`) y limpien el búfer adecuadamente.

---

## 📋 4. Lista de Comandos de Git Más Frecuentes

Para facilitar el trabajo diario del equipo, a continuación se presenta la lista de referencia rápida con los comandos de Git más utilizados:

### A. Clonación e Inicio
```bash
# Clonar el repositorio oficial
git clone https://github.com/wigsdev/gestion_biblioteca_universitaria.git

# Entrar al directorio
cd gestion_biblioteca_universitaria
```

### B. Gestión de Ramas y Sincronización
```bash
# Cambiar a la rama principal
git checkout main

# Descargar las últimas actualizaciones del servidor
git pull

# Crear y cambiarse a una nueva rama de trabajo
git checkout -b feature/nombre-mi-modulo
```

### C. Registro y Publicación de Cambios
```bash
# Verificar archivos modificados o nuevos
git status

# Preparar un archivo específico para confirmación
git add <nombre_archivo>

# Confirmar cambios usando la estructura de Conventional Commits
git commit -m "<tipo>(<alcance>): <descripcion_corta>"

# Subir la rama a GitHub por primera vez
git push -u origin feature/nombre-mi-modulo

# Subir cambios posteriores en la misma rama
git push
```

### D. Actualizar y Sincronizar tu Rama Secundaria
```bash
# Descargar y fusionar los cambios de tu misma rama desde GitHub (si otros la editaron o trabajas desde otra PC)
git pull origin feature/nombre-mi-modulo
```

### E. Integración de main en tu Rama (Evitar desactualización)
```bash
# 1. Ve a la rama principal y descarga lo último del equipo
git checkout main
git pull

# 2. Regresa a tu rama secundaria e infórmala con los cambios de main
git checkout feature/nombre-mi-modulo
git merge main
```
