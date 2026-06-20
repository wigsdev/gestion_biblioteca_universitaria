# ==============================================================================
#      MAKEFILE - SISTEMA DE GESTIÓN DE BIBLIOTECA UNIVERSITARIA
# ==============================================================================

CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = biblioteca

SRCS = main.cpp libros.cpp busquedas.cpp ordenamientos.cpp prestamos.cpp historial.cpp recursividad.cpp
HEADERS = estructuras.h libros.h busquedas.h ordenamientos.h prestamos.h historial.h recursividad.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
ifeq ($(OS),Windows_NT)
	-del /Q /F $(TARGET) $(TARGET).exe 2>nul
else
	-rm -f $(TARGET) $(TARGET).exe
endif
