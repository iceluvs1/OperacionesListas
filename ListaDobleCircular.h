#pragma once
#include "nodoDoble.h"

class ListaDobleCircular {
public:
    nodoDoble* head;
    nodoDoble* back;

    ListaDobleCircular();

    void insertarFinal(int valor);
    nodoDoble* buscar(int valor) const;
    bool eliminar(int valor);
    void imprimir() const;
    void clear();

    ~ListaDobleCircular();
};
