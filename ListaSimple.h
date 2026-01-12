#pragma once
#include "nodoSimple.h"

class ListaSimple {
public:
    nodoSimple* head;
    ListaSimple();

    void insertarFinal(int valor);
    nodoSimple* buscar(int valor) const;
    bool eliminar(int valor);
    void imprimir() const;
    void clear();

    ~ListaSimple();
};
