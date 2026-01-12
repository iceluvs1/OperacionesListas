#pragma once
#include "nodoDoble.h"

class ListaDoble {
public:
    nodoDoble* head;
    nodoDoble* back;

    ListaDoble();

    void insertarFinal(int valor);
    nodoDoble* buscar(int valor) const;
    bool eliminar(int valor);
    void imprimir() const;
    void clear();

    ~ListaDoble();

};
