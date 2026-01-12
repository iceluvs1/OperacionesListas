cmake_minimum_required(VERSION 4.1)
project(OperacionesListas)

set(CMAKE_CXX_STANDARD 20)

add_executable(OperacionesListas main.cpp
        nodoSimple.h
        nodoDoble.h
        ListaSimple.h
        ListaSimple.cpp
        ListaDoble.h
        ListaDoble.cpp
        ListaSimpleCircular.h
        ListaSimpleCircular.cpp
        ListaDobleCircular.cpp
        ListaDobleCircular.h)
