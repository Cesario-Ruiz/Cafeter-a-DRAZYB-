/*
    Cabezera empleada para limpiar la pantalla en la consola, sin importar si se ejecuta bajo msDOS o Unix.
    #ifdef -> Es un comando del "Pre-procesador" que incluye o excluye partes del codigo fuente que se entrega finalmente al compilador
    -> Si se esta ejecutando en windows, #indef incluira la librería <windows.h>
*/

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

void limpiarPantalla(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
