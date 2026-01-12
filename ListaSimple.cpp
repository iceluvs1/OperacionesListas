#include <iostream>
using namespace std;
#include "ListaSimple.h"

ListaSimple::ListaSimple() : head(nullptr) {}

ListaSimple::~ListaSimple() {
    clear();
}


void ListaSimple::insertarFinal(int valor) {
    nodoSimple* nuevo = new nodoSimple(valor);

    if (head == nullptr) {
        head = nuevo;
        return;
    }

    nodoSimple* aux = head;
    while (aux->sig != nullptr) aux = aux->sig;
    aux->sig = nuevo;
}

nodoSimple* ListaSimple::buscar(int valor) const {
    nodoSimple* aux = head;
    while (aux != nullptr) {
        if (aux->dato == valor) return aux;
        aux = aux->sig;
    }
    return nullptr;
}

bool ListaSimple::eliminar(int valor) {
    if (head == nullptr) return false;

    if (head->dato == valor) {
        nodoSimple* borrar = head;
        head = head->sig;
        delete borrar;
        return true;
    }

    nodoSimple* ant = head;
    nodoSimple* act = head->sig;

    while (act != nullptr) {
        if (act->dato == valor) {
            ant->sig = act->sig;
            delete act;
            return true;
        }
        ant = act;
        act = act->sig;
    }

    return false;
}

void ListaSimple::imprimir() const {
    if (head == nullptr) {
        cout << "Lista simple vacia.\n";
        return;
    }

    cout << "Simple: ";
    nodoSimple* aux = head;
    while (aux != nullptr) {
        cout << aux->dato;
        if (aux->sig != nullptr) cout << " -> ";
        aux = aux->sig;
    }
    cout << "\n";
}

void ListaSimple::clear() {
    while (head != nullptr) {
        nodoSimple* borrar = head;
        head = head->sig;
        delete borrar;
    }
}
