#pragma once
#include "nodoSimple.h"

class ListaSimpleCircular {
public:
    nodoSimple* head;
    nodoSimple* back;

    ListaSimpleCircular();

    void insertarFinal(int valor);
    nodoSimple* buscar(int valor) const;
    bool eliminar(int valor);
    void imprimir() const;
    void clear();

    ~ListaSimpleCircular();

};
