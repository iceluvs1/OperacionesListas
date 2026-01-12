#include <iostream>
using namespace std;

#include "ListaDobleCircular.h"

ListaDobleCircular::ListaDobleCircular() : head(nullptr), back(nullptr) {}

ListaDobleCircular::~ListaDobleCircular() {
    clear();
}

void ListaDobleCircular::insertarFinal(int valor) {
    nodoDoble* nuevo = new nodoDoble(valor);

    // Caso: lista vacía
    if (head == nullptr) {
        head = back = nuevo;
        nuevo->sig = nuevo;
        nuevo->back = nuevo;
        return;
    }

    // Conectar nuevo al final (back es el último)
    nuevo->sig = head;      // nuevo apunta al inicio
    nuevo->back = back;     // nuevo apunta hacia atrás al antiguo último

    back->sig = nuevo;      // antiguo último apunta al nuevo
    head->back = nuevo;     // head apunta hacia atrás al nuevo último

    back = nuevo;           // actualizar back
}

nodoDoble* ListaDobleCircular::buscar(int valor) const {
    if (head == nullptr) return nullptr;

    nodoDoble* aux = head;
    do {
        if (aux->dato == valor) return aux;
        aux = aux->sig;
    } while (aux != head);

    return nullptr;
}

bool ListaDobleCircular::eliminar(int valor) {
    if (head == nullptr) return false;

    // Caso: un solo nodo
    if (head == back && head->dato == valor) {
        delete head;
        head = back = nullptr;
        return true;
    }

    // Caso: borrar head
    if (head->dato == valor) {
        nodoDoble* borrar = head;
        head = head->sig;

        head->back = back;
        back->sig = head;

        delete borrar;
        return true;
    }

    // Caso: borrar back (último)
    if (back->dato == valor) {
        nodoDoble* borrar = back;
        back = back->back;

        back->sig = head;
        head->back = back;

        delete borrar;
        return true;
    }

    // Caso: borrar al medio
    nodoDoble* actual = head->sig;
    while (actual != head) {
        if (actual->dato == valor) {
            actual->back->sig = actual->sig;
            actual->sig->back = actual->back;
            delete actual;
            return true;
        }
        actual = actual->sig;
    }

    return false;
}

void ListaDobleCircular::imprimir() const {
    if (head == nullptr) {
        cout << "Lista doble circular vacia.\n";
        return;
    }

    cout << "Doble circular: ";
    nodoDoble* aux = head;

    do {
        cout << aux->dato;
        aux = aux->sig;
        if (aux != head) cout << " <-> ";
    } while (aux != head);

    cout << " <-> (vuelve al inicio)\n";
}

void ListaDobleCircular::clear() {
    if (head == nullptr) return;

    // borrar todos menos head recorriendo en círculo
    nodoDoble* actual = head->sig;
    while (actual != head) {
        nodoDoble* borrar = actual;
        actual = actual->sig;
        delete borrar;
    }

    delete head;
    head = back = nullptr;
}