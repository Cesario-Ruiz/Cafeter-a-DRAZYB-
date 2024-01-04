/*
    Encabezado que contiene la funcion gotoxy() -> Simulando las librerias <windows.h>/<conio.h>
*/
#include <stdio.h>

void gotoxy(int x, int y)   // Las variables x & y reprenstan las coordenadas de la consola/terminal
{                                           
    printf("%c[%d;%df", 0x1B, y, x);        
}