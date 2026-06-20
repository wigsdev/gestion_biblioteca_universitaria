# 📊 Diagramas de Flujo del Sistema

Este documento contiene los diagramas de flujo que describen de forma lógica el funcionamiento de las operaciones avanzadas del sistema de biblioteca.

---

## 1. Algoritmo de Deshacer (Undo) - Módulo 5 (Wilmer)
Describe cómo el sistema evalúa la pila de historial de operaciones para revertir el último cambio de forma segura.

```mermaid
flowchart TD
    Start([Inicio: deshacerUltimaOperacion]) --> Check{"¿cima == nullptr?"}
    Check -- Sí --> Msg["Mostrar: No hay operaciones a deshacer"]
    Msg --> End([Fin])
    
    Check -- No --> Fetch["Obtener 'ultima' = cima->dato"]
    Fetch --> Eval{"Evaluar ultima.tipo"}
    
    Eval -- REGISTRAR_LIBRO --> UndoReg["Eliminar libro insertado de la lista doble"]
    Eval -- ELIMINAR_LIBRO --> UndoDel["Restaurar libro (libroOriginal) en lista doble"]
    Eval -- MODIFICAR_LIBRO --> UndoMod["Restaurar datos originales en lista doble"]
    Eval -- REALIZAR_PRESTAMO --> UndoPres["Incrementar stock de libro prestado"]
    Eval -- DEVOLVER_PRESTAMO --> UndoDev["Decrementar stock de libro devuelto"]
    
    UndoReg --> Pop["Desapilar: popOperacion(cima)"]
    UndoDel --> Pop
    UndoMod --> Pop
    UndoPres --> Pop
    UndoDev --> Pop
    
    Pop --> Success["Mostrar: Operación deshecha con éxito"]
    Success --> End
```

---

## 2. Inserción al Final en Lista Doblemente Enlazada - Módulo 1 (Víctor)
Describe el algoritmo para insertar un libro al final del catálogo y enlazar correctamente los punteros dobles.

```mermaid
flowchart TD
    Start([Inicio: registrarLibro]) --> NewNode["Crear nuevoNodo en memoria RAM
Asignar nuevoNodo->dato = nuevo
nuevoNodo->siguiente = nullptr"]
    
    NewNode --> Check{"¿cabeza == nullptr?"}
    Check -- Sí --> Empty["cabeza = nuevoNodo
cola = nuevoNodo
nuevoNodo->anterior = nullptr"]
    
    Check -- No --> Connect["cola->siguiente = nuevoNodo
nuevoNodo->anterior = cola
cola = nuevoNodo"]
    
    Empty --> End([Fin])
    Connect --> End
```
