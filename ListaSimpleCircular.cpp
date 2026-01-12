#include <iostream>
using namespace std;
#include "ListaSimpleCircular.h"

ListaSimpleCircular::ListaSimpleCircular() : head(nullptr), back(nullptr) {}

ListaSimpleCircular::~ListaSimpleCircular() {
    clear();
}


void ListaSimpleCircular::insertarFinal(int valor) {
    nodoSimple* nuevo = new nodoSimple(valor);

    if (back == nullptr) {
        head = back = nuevo;
        nuevo->sig = nuevo;
        return;
    }

    back->sig = nuevo;
    nuevo->sig = head;
    back = nuevo;
}

nodoSimple* ListaSimpleCircular::buscar(int valor) const {
    if (head == nullptr) return nullptr;

    nodoSimple* aux = head;
    do {
        if (aux->dato == valor) return aux;
        aux = aux->sig;
    } while (aux != head);

    return nullptr;
}

bool ListaSimpleCircular::eliminar(int valor) {
    if (head == nullptr) return false;

    // Caso: un solo nodo
    if (head == back && head->dato == valor) {
        delete head;
        head = back = nullptr;
        return true;
    }

    // Caso: borrar head
    if (head->dato == valor) {
        nodoSimple* borrar = head;
        head = head->sig;
        back->sig = head;
        delete borrar;
        return true;
    }

    // Buscar en el resto
    nodoSimple* ant = head;
    nodoSimple* act = head->sig;

    while (act != head) {
        if (act->dato == valor) {
            ant->sig = act->sig;

            if (act == back) back = ant;

            delete act;
            return true;
        }
        ant = act;
        act = act->sig;
    }

    return false; // no encontrado
}

void ListaSimpleCircular::imprimir() const {
    if (head == nullptr) {
        cout << "Lista circular vacia.\n";
        return;
    }

    cout << "Circular: ";
    nodoSimple* aux = head;
    do {
        cout << aux->dato;
        aux = aux->sig;
        if (aux != head) cout << " -> ";
    } while (aux != head);

    cout << " -> (vuelve al inicio)\n";
}

void ListaSimpleCircular::clear() {
    if (head == nullptr) return;

    // borrar todos menos head
    nodoSimple* actual = head->sig;
    while (actual != head) {
        nodoSimple* borrar = actual;
        actual = actual->sig;
        delete borrar;
    }

    // borrar head
    delete head;
    head = back = nullptr;
}
