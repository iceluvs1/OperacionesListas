#include <iostream>
using namespace std;
#include "ListaDoble.h"

ListaDoble::ListaDoble() : head(nullptr), back(nullptr) {}

ListaDoble::~ListaDoble() {
    clear();
}


void ListaDoble::insertarFinal(int valor) {
    nodoDoble* nuevo = new nodoDoble(valor);

    if (back == nullptr) {
        head = back = nuevo;
        return;
    }

    back->sig = nuevo;
    nuevo->back = back;
    back = nuevo;
}

nodoDoble* ListaDoble::buscar(int valor) const {
    nodoDoble* aux = head;
    while (aux != nullptr) {
        if (aux->dato == valor) return aux;
        aux = aux->sig;
    }
    return nullptr;
}

bool ListaDoble::eliminar(int valor) {
    nodoDoble* actual = head;

    while (actual != nullptr && actual->dato != valor) {
        actual = actual->sig;
    }

    if (actual == nullptr) return false; // no encontrado

    // Caso: borrar head
    if (actual == head) {
        head = head->sig;
        if (head != nullptr) head->back = nullptr;
        else back = nullptr; // quedó vacía
        delete actual;
        return true;
    }

    // Caso: borrar back
    if (actual == back) {
        back = back->back;
        back->sig = nullptr;
        delete actual;
        return true;
    }

    // Caso: borrar al medio
    actual->back->sig = actual->sig;
    actual->sig->back = actual->back;
    delete actual;
    return true;
}

void ListaDoble::imprimir() const {
    if (head == nullptr) {
        cout << "Lista doble vacia.\n";
        return;
    }

    cout << "Doble: ";
    nodoDoble* aux = head;
    while (aux != nullptr) {
        cout << aux->dato;
        if (aux->sig != nullptr) cout << " <-> ";
        aux = aux->sig;
    }
    cout << "\n";
}


void ListaDoble::clear() {
    nodoDoble* actual = head;
    while (actual != nullptr) {
        nodoDoble* borrar = actual;
        actual = actual->sig;
        delete borrar;
    }
    head = back = nullptr;
}
