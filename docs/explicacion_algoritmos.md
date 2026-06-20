# ⚙️ Explicación de Algoritmos y Recursión

Este documento contiene un desglose conceptual de los algoritmos y la recursividad que deben implementar los integrantes para cumplir con las especificaciones del catálogo.

---

## 1. Algoritmos de Ordenamiento ($O(N^2)$ y $O(N \log N)$)

### A. Burbuja (Bubble Sort) - Javier
Compara pares de nodos contiguos e intercambia sus datos de tipo `Libro` si el título del primero es alfabéticamente mayor que el del segundo. Repite pasadas completas hasta que una pasada entera no registre ningún intercambio (`intercambiado == false`).

### B. Selección (Selection Sort) - Javier
Busca el nodo con el autor menor alfabéticamente en la sublista no ordenada y lo intercambia con el nodo al principio de dicha sublista.

### C. Inserción (Insertion Sort) - Wilmer
Toma el elemento actual del catálogo y lo inserta en su posición correspondiente comparándolo con la sección de libros ya ordenada anteriormente.

### D. Quick Sort - Víctor
*   **Complejidad**: $O(N \log N)$ promedio.
*   **Mecánica**: Divide el catálogo en base a un pivote (usualmente el elemento medio). Elementos menores al pivote se mueven a la izquierda, mayores a la derecha. Luego, se realiza la llamada recursiva para ambas subdivisiones.
*   *Nota*: Para optimizar su implementación sobre listas enlazadas, se recomienda copiar los datos al arreglo temporal, ordenar el arreglo con QuickSort clásico y reescribir de regreso los datos en la lista doble.

### E. Merge Sort - Javier
*   **Complejidad**: $O(N \log N)$ garantizado.
*   **Mecánica**: Divide recursivamente el catálogo en dos subcatálogos hasta que tengan tamaño 1, y luego los fusiona en orden descendente (por cantidad disponible).

---

## 2. Recursividad en la Lista Doblemente Enlazada (Módulo 6) - Víctor

Al ser una estructura lineal doblemente enlazada, la recursividad tiene un diseño sencillo. El control de detención (caso base) se gestiona comprobando si el puntero al nodo actual llega a `nullptr`.

1.  **Mostrar Catálogo Recursivamente**:
    *   **Acción**: Imprime el libro del nodo actual.
    *   **Llamada**: Llama a sí mismo con `nodo->siguiente`.
    *   **Caso Base**: `nodo == nullptr` (retorna).
2.  **Contar Libros Recursivamente**:
    *   **Llamada**: Retorna `1 + contarLibrosRecursivo(nodo->siguiente)`.
    *   **Caso Base**: `nodo == nullptr` (retorna `0`).
3.  **Buscar Libro Recursivamente**:
    *   **Caso de Éxito**: Si `nodo->dato.codigo == codigo`, retorna `nodo`.
    *   **Caso Base de Fin**: Si `nodo == nullptr`, retorna `nullptr`.
    *   **Llamada**: Retorna `buscarLibroRecursivo(nodo->siguiente, codigo)`.
