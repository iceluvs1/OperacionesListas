#pragma once

class nodoDoble {
public:
    int dato;
    nodoDoble* sig;
    nodoDoble* back;

    nodoDoble(int valor){
        dato = valor;
        sig = nullptr;
        back = nullptr;
    }
};