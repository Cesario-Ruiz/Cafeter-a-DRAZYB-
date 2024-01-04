/*
    --------------------------------------------------------------------------------------------------------
                                        Cabecera: cambioDeColor.h
    --------------------------------------------------------------------------------------------------------
    Esta cabecera emplea los códigos de escape ANSI para cambiar el color de los textos.
    -> Los cambios aplicados en los textos son meramente estéticos.
*/

// Texto regular
#define NEGRO "\e[0;30m"
#define ROJO "\e[0;31m"
#define VERDE "\e[0;32m"
#define AMARILLO "\e[0;33m"
#define AZUL "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CIAN "\e[0;36m"
#define BLANCO "\e[0;37m"

// Texto en negritas
#define NEGRITA_NEGRO "\e[1;30m"
#define NEGRITA_ROJO "\e[1;31m"
#define NEGRITA_VERDE "\e[1;32m"
#define NEGRITA_AMARILLO "\e[1;33m"
#define NEGRITA_AZUL "\e[1;34m"
#define NEGRITA_MAGENTA "\e[1;35m"
#define NEGRITA_CIAN "\e[1;36m"
#define NEGRITA_BLANCO "\e[1;37m"

// Texto subrayado
#define SUBRAYADO_NEGRO "\e[4;30m"
#define SUBRAYADO_ROJO "\e[4;31m"
#define SUBRAYADO_VERDE "\e[4;32m"
#define SUBRAYADO_AMARILLO "\e[4;33m"
#define SUBRAYADO_AZUL "\e[4;34m"
#define SUBRAYADO_MAGENTA "\e[4;35m"
#define SUBRAYADO_CIAN "\e[4;36m"
#define SUBRAYADO_BLANCO "\e[4;37m"

// Fondo del texto
#define FONDO_NEGRO "\e[40m"
#define FONDO_ROJO "\e[41m"
#define FONDO_VERDE "\e[42m"
#define FONDO_AMARILLO "\e[43m"
#define FONDO_AZUL "\e[44m"
#define FONDO_MAGENTA "\e[45m"
#define FONDO_CIAN "\e[46m"
#define FONDO_BLANCO "\e[47m"

// Reinicia los colores
#define COLOR_RESET "\e[0m"