#pragma once

class nodoSimple {
    public:
    int dato;
    nodoSimple* sig;

    nodoSimple(int valor) {
        dato = valor;
        sig = nullptr;
    }
};
