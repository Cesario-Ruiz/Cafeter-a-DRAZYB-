/*
    --------------------------------------------------------------------------------------------------------
                                                Cabecera: acomodo.h
    --------------------------------------------------------------------------------------------------------
    Cabecera que contiene la funcion gotoxy() -> Simulando las librerias <windows.h>/<conio.h>
    Es utilizada para poner el cursor en un punto especifico de la pantalla.
     -> Las variables x & y reprenstan las coordenadas de la consola/terminal
*/
#include <stdio.h>

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}