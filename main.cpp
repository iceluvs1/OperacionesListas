#include <iostream>
using namespace std;
#include "ListaSimple.h"
#include "ListaDoble.h"
#include "ListaSimpleCircular.h"
#include "ListaDobleCircular.h"

int main() {
    int tipo;
    cout << "Tipo de lista:\n1) Simple\n2) Doble\n3) Simple Circular\n4) Doble Circular\nOpcion: ";
    cin >> tipo;

    if (tipo == 1) {
        ListaSimple lista;
        int op = 0;

        while (op != 6) {
            cout << "\n--- MENU LISTA SIMPLE ---\n"
                 << "1) Insertar al final\n"
                 << "2) Buscar\n"
                 << "3) Eliminar\n"
                 << "4) Imprimir\n"
                 << "5) Limpiar\n"
                 << "6) Salir\n"
                 << "Opcion: ";
            cin >> op;

            int valor;
            switch (op) {
                case 1: cout << "Valor: "; cin >> valor; lista.insertarFinal(valor); break;
                case 2: cout << "Valor a buscar: "; cin >> valor;
                    if (lista.buscar(valor)) {
                        cout << "Encontrado.\n";
                    } else {
                        cout << "No encontrado.\n";
                    }
                    break;
                case 3: cout << "Valor a eliminar: "; cin >> valor;
                    if (lista.eliminar(valor)) {
                        cout << "Eliminado.\n";
                    } else {
                        cout << "No existe.\n";
                    }
                    break;
                case 4: lista.imprimir(); break;
                case 5: lista.clear(); cout << "Lista limpiada.\n"; break;
                case 6: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida.\n";
            }
        }
    }
    else if (tipo == 2) {
        ListaDoble lista;
        int op = 0;

        while (op != 6) {
            cout << "\n--- MENU LISTA DOBLE ---\n"
                 << "1) Insertar al final\n"
                 << "2) Buscar\n"
                 << "3) Eliminar\n"
                 << "4) Imprimir\n"
                 << "5) Limpiar\n"
                 << "6) Salir\n"
                 << "Opcion: ";
            cin >> op;

            int valor;
            switch (op) {
                case 1: cout << "Valor: "; cin >> valor; lista.insertarFinal(valor); break;
                case 2: cout << "Valor a buscar: "; cin >> valor;
                    if (lista.buscar(valor)) {
                        cout << "Encontrado.\n";
                    } else {
                        cout << "No encontrado.\n";
                    }
                    break;
                case 3: cout << "Valor a eliminar: "; cin >> valor;
                    if (lista.eliminar(valor)) {
                        cout << "Eliminado.\n";
                    } else {
                        cout << "No existe.\n";
                    }
                    break;
                case 4: lista.imprimir(); break;
                case 5: lista.clear(); cout << "Lista limpiada.\n"; break;
                case 6: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida.\n";
            }
        }
    }
    else if (tipo == 3) {
        ListaSimpleCircular lista;
        int op = 0;

        while (op != 6) {
            cout << "\n--- MENU LISTA SIMPLE CIRCULAR ---\n"
                 << "1) Insertar al final\n"
                 << "2) Buscar\n"
                 << "3) Eliminar\n"
                 << "4) Imprimir\n"
                 << "5) Limpiar\n"
                 << "6) Salir\n"
                 << "Opcion: ";
            cin >> op;

            int valor;
            switch (op) {
                case 1:
                    cout << "Valor: ";
                    cin >> valor;
                    lista.insertarFinal(valor);
                    break;

                case 2:
                    cout << "Valor a buscar: ";
                    cin >> valor;
                    if (lista.buscar(valor)) cout << "Encontrado.\n";
                    else cout << "No encontrado.\n";
                    break;

                case 3:
                    cout << "Valor a eliminar: ";
                    cin >> valor;
                    if (lista.eliminar(valor)) cout << "Eliminado.\n";
                    else cout << "No existe.\n";
                    break;

                case 4:
                    lista.imprimir();
                    break;

                case 5:
                    lista.clear();
                    cout << "Lista limpiada.\n";
                    break;

                case 6:
                    cout << "Saliendo...\n";
                    break;

                default:
                    cout << "Opcion invalida.\n";
            }
        }
    }
    else if (tipo == 4) {
        ListaDobleCircular lista;
        int op = 0;

        while (op != 6) {
            cout << "\n--- MENU LISTA DOBLE CIRCULAR ---\n"
                 << "1) Insertar al final\n"
                 << "2) Buscar\n"
                 << "3) Eliminar\n"
                 << "4) Imprimir\n"
                 << "5) Limpiar\n"
                 << "6) Salir\n"
                 << "Opcion: ";
            cin >> op;

            int valor;
            switch (op) {
                case 1: cout << "Valor: "; cin >> valor; lista.insertarFinal(valor); break;
                case 2: cout << "Valor a buscar: "; cin >> valor;
                    if (lista.buscar(valor)) cout << "Encontrado.\n";
                    else cout << "No encontrado.\n";
                    break;
                case 3: cout << "Valor a eliminar: "; cin >> valor;
                    if (lista.eliminar(valor)) cout << "Eliminado.\n";
                    else cout << "No existe.\n";
                    break;
                case 4: lista.imprimir(); break;
                case 5: lista.clear(); cout << "Lista limpiada.\n"; break;
                case 6: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida.\n";
            }
        }
    }
    else {
        cout << "Opcion invalida.\n";
    }

    return 0;
}
