# 🔗 Diagramas de Nodos del Sistema

Este documento describe la estructura y los enlaces en memoria dinámica (RAM) de las estructuras de datos personalizadas del sistema de biblioteca.

---

## 1. Módulo 1: Lista Doblemente Enlazada (Catálogo de Libros)
Los nodos están conectados bidireccionalmente. Cada nodo posee un puntero al nodo posterior (`siguiente`) y al nodo anterior (`anterior`). La lista cuenta con una `cabeza` y una `cola`.

```mermaid
graph LR
    subgraph Lista Doble
        cabeza["Puntero *cabeza"] -.-> node1[Libro 1]
        node1 <-->|ant / sig| node2[Libro 2]
        node2 <-->|ant / sig| node3["Libro 3 (último)"]
        cola["Puntero *cola"] -.-> node3
        node1 -.-> NULL1[nullptr]
        node3 -.-> NULL2[nullptr]
    end
```

---

## 2. Módulo 4: Cola FIFO (Fila de Solicitudes)
La cola es una estructura lineal en la cual los elementos nuevos ingresan por un extremo (`fin`) y se atienden/retiran por el otro (`frente`).

```mermaid
graph LR
    subgraph Cola FIFO
        frente["Puntero *frente"] -.-> node1["Solicitud A (Primera)"]
        node1 -->|siguiente| node2[Solicitud B]
        node2 -->|siguiente| node3["Solicitud C (Última)"]
        node3 -->|siguiente| NULL[nullptr]
        fin["Puntero *fin"] -.-> node3
    end
```

---

## 3. Módulo 5: Pila LIFO (Historial de Operaciones)
Las operaciones del historial se apilan de manera que la última acción registrada queda al tope. Al realizar un "deshacer" (Undo), la operación del tope (`cima`) es la primera en desapilarse y ejecutarse.

```mermaid
graph TD
    subgraph Pila LIFO
        cima["Puntero *cima"] -.-> node3["Operación 3 (Última)"]
        node3 -->|siguiente| node2[Operación 2]
        node2 -->|siguiente| node1["Operación 1 (Primera)"]
        node1 -->|siguiente| NULL[nullptr]
    end
```
