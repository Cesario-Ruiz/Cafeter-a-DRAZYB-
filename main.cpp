/*
	< Proyecto Cafetería - 03/01/2024
	Integrantes del equipo DRAZYB:
		* Borges Valdés José Antonio.
		* Espinoza Calles Uzziel.
		* Martínez Carreola Daniel Alejandro.
		* Ruíz De La Cruz César.

	CAFETERÍA: Mostrar los diferentes especialidades,
	poder generar una comanda  por mesa (máx 5 mesas). agregar un producto a la orden ya pedida.
	Poder revisar las ventas Totales, por Mesa, por producto y venta total en general >
*/

// Librerias a utilizar.
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

// Cabeceras a Utilizar
#include "funciones.h"
#include "cambioDeColor.h"
#include "acomodo.h"
#include "limpiarLaPantalla.h"

// Especialidades de  la Caféteria.
struct Especialidad
{
	string nombre;
	int precio;
};

struct Pedido
{
	string nombre;
	int precio;
	int cantidad;
	int total_producto;
};

vector<Especialidad> especialidades;

// Vectores para almacenar las ventas por mesa.
vector<vector<Pedido>> mesa1;
vector<vector<Pedido>> mesa2;
vector<vector<Pedido>> mesa3;
vector<vector<Pedido>> mesa4;
vector<vector<Pedido>> mesa5;

// Función Principal.
int main()
{
	setlocale(LC_CTYPE, "");
	insertarEspecialidades();
	menuPrincipal();
	return 0;
}

/*
 *	Definicion de las funciones.
 */

// Función para agregar productos a la orden/comanda.
void insertarEspecialidades()
{
	Especialidad especialidad1 = {"Americano grande", 100};
	Especialidad especialidad2 = {"Americano chico", 85};

	Especialidad especialidad3 = {"Latte grande", 95};
	Especialidad especialidad4 = {"Latte chico", 72};

	Especialidad especialidad5 = {"Cappuccino grande", 120};
	Especialidad especialidad6 = {"Cappuccino chico", 96};

	Especialidad especialidad7 = {"Mocca grande", 89};
	Especialidad especialidad8 = {"Mocca chico", 70};

	Especialidad especialidad9 = {"Frappe oreo grande", 92};
	Especialidad especialidad10 = {"Frappe oreo chico", 74};

	Especialidad especialidad11 = {"Expresso grande", 99};
	Especialidad especialidad12 = {"Expresso chico", 78};

	especialidades.push_back(especialidad1);
	especialidades.push_back(especialidad2);
	especialidades.push_back(especialidad3);
	especialidades.push_back(especialidad4);
	especialidades.push_back(especialidad5);
	especialidades.push_back(especialidad6);
	especialidades.push_back(especialidad7);
	especialidades.push_back(especialidad8);
	especialidades.push_back(especialidad9);
	especialidades.push_back(especialidad10);
	especialidades.push_back(especialidad11);
	especialidades.push_back(especialidad12);
}

// Funcion para mostrar el ménu de especialidades.
void mostrarProductos()
{

	for (int i = 0; i < especialidades.size(); i++)
	{
		Especialidad especialidad = especialidades[i];
		cout << (i + 1) << ": " << especialidad.nombre << VERDE " - $" COLOR_RESET << especialidad.precio << endl;
	}
}

// Validar que la entrada sea un numero.
bool esNumero(string cadena)
{
	for (int i = 0; i < cadena.size(); i++)
	{
		if (isdigit(cadena[i]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void mostrarEspecialidades()
{
	// opci�n 1
	string opc = "1";
	while (opc != "0")
	{
		gotoxy(60, 3);
		cout << "Especialidades" << endl;
		gotoxy(30, 4);
		cout << VERDE "============================================================================\n" COLOR_RESET << endl;
		mostrarProductos();
		cout << FONDO_ROJO "0.- Regresar..." COLOR_RESET << endl;
		cout << "¿Qué desea hacer?...";
		getline(cin, opc);
		limpiarPantalla();
		if (opc == "0")
		{
			break;
		}
		else
		{
			gotoxy(49, 15);
			cout << "Upss..¡Esa no es una opción correcta!" << endl;
			cin.get();
			limpiarPantalla();
		}
	}
}

void generarOrdenMesa(short mesa)
{
	string cantidad_a_escoger = "0"; // Cantidad de productos que se seleccionaran del menu
	cout << "Menú de Especialidades para la mesa " << mesa << endl;
	mostrarProductos();
	// Validacion del numero de productos a comprar
	while (!esNumero(cantidad_a_escoger) || stoi(cantidad_a_escoger) < 1)
	{
		cout << "Cuantos productos del menú desea escoger: ";
		getline(cin, cantidad_a_escoger);
	}
	for (int i = 0; i < stoi(cantidad_a_escoger); i++)
	{
		int total_a_pagar = 0;
		string producto = "0";
		string cantidad = "0"; // Cantidad del producto seleccionado del ménu.
		// Validaci�n del número del producto
		cout << "Producto número " << (i + 1) << endl;
		while (!esNumero(producto) || stoi(producto) < 1 || stoi(producto) > especialidades.size())
		{
			cout << "Escoja un número del menú de su preferencia: ";
			getline(cin, producto);
		}
		cout << endl;
		cout << "Escogido: " << especialidades[stoi(producto) - 1].nombre << " - Precio: $" << especialidades[stoi(producto) - 1].precio << endl;
		// Validación de la cantidad de productos.
		while (!esNumero(cantidad) || stoi(cantidad) < 1)
		{
			cout << "Cantidad: ";
			getline(cin, cantidad);
		}

		total_a_pagar = stoi(cantidad) * especialidades[stoi(producto) - 1].precio;

		if (mesa == 1)
		{
			mesa1.push_back(vector<Pedido>{
				{especialidades[stoi(producto) - 1].nombre, especialidades[stoi(producto) - 1].precio, stoi(cantidad), total_a_pagar},
			});
		}
		if (mesa == 2)
		{
			mesa2.push_back(vector<Pedido>{
				{especialidades[stoi(producto) - 1].nombre, especialidades[stoi(producto) - 1].precio, stoi(cantidad), total_a_pagar},
			});
		}
		if (mesa == 3)
		{
			mesa3.push_back(vector<Pedido>{
				{especialidades[stoi(producto) - 1].nombre, especialidades[stoi(producto) - 1].precio, stoi(cantidad), total_a_pagar},
			});
		}
		if (mesa == 4)
		{
			mesa4.push_back(vector<Pedido>{
				{especialidades[stoi(producto) - 1].nombre, especialidades[stoi(producto) - 1].precio, stoi(cantidad), total_a_pagar},
			});
		}
		if (mesa == 5)
		{
			mesa5.push_back(vector<Pedido>{
				{especialidades[stoi(producto) - 1].nombre, especialidades[stoi(producto) - 1].precio, stoi(cantidad), total_a_pagar},
			});
		}
	}
}

void mostrarMesas()
{
	gotoxy(55, 3);
	cout << "Menú para Generar Ordenes" << endl;
	gotoxy(30, 4);
	cout << NEGRO "============================================================================" COLOR_RESET << endl;
	cout << "¿Para que mesa?" << endl;
	cout << "1.- Mesa 1" << endl;
	cout << "2.- Mesa 2" << endl;
	cout << "3.- Mesa 3" << endl;
	cout << "4.- Mesa 4" << endl;
	cout << "5.- Mesa 5" << endl;
	cout << FONDO_ROJO "0.- Regresar..." COLOR_RESET << endl;
}

void generarOrdenes()
{
	string opc_mesa = "1";
	while (opc_mesa != "0")
	{
		mostrarMesas();
		getline(cin, opc_mesa);
		limpiarPantalla();
		if (opc_mesa == "1")
		{
			cin.clear();
			generarOrdenMesa(1);
			cout << AZUL "Orden generada con éxito" COLOR_RESET << endl;
			cin.get();
			limpiarPantalla();
		}
		else if (opc_mesa == "2")
		{
			cin.clear();
			generarOrdenMesa(2);
			cout << AZUL "Orden generada con éxito" COLOR_RESET << endl;
			cin.get();
			limpiarPantalla();
		}
		else if (opc_mesa == "3")
		{
			cin.clear();
			generarOrdenMesa(3);
			cout << AZUL "Orden generada con éxito" COLOR_RESET << endl;
			cin.get();
			limpiarPantalla();
		}
		else if (opc_mesa == "4")
		{
			cin.clear();
			generarOrdenMesa(4);
			cout << AZUL "Orden generada con éxito" COLOR_RESET << endl;
			cin.get();
			limpiarPantalla();
		}
		else if (opc_mesa == "5")
		{
			cin.clear();
			generarOrdenMesa(5);
			cout << AZUL "Orden generada con éxito" COLOR_RESET << endl;
			cin.get();
			limpiarPantalla();
		}
		else if (opc_mesa == "0")
		{
			cin.clear();
			menuPrincipal();
		}
		else
		{
			gotoxy(49, 15);
			cout << ROJO "Upss..¡Esa no es una opción correcta!" COLOR_RESET << endl;
			cin.get();
			limpiarPantalla();
		}
	}
}

string generarIdentificador()
{
	string cadena;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		cadena += static_cast<char>(rand() % 26 + 'a');
	}
	return cadena;
}

void generarArchivoTxt()
{
	ofstream archivo(generarIdentificador() + " Reporte de ventas.txt", ios::out); // identificador aleatorio para evitar que se sobreescriba el archivo
	archivo << "Totales por mesa y en general\n";
	int total_general = 0;

	// colocar fecha y hora actual
	time_t tiempo;
	char fecha[20];
	tiempo = time(0);
	strftime(fecha, sizeof(fecha), "%d/%m/%Y %H:%M:%S", localtime(&tiempo));

	archivo << "Fecha y hora del pedido: " << fecha << "\n\n";

	// mesa 1
	archivo << "---------------------------------------------------------------------------\n";
	archivo << "\n";
	archivo << "Mesa 1\n";
	int total_mesa1 = 0;
	for (int i = 0; i < mesa1.size(); i++)
	{
		for (int j = 0; j < mesa1[i].size(); j++)
		{
			total_mesa1 += mesa1[i][j].total_producto;
			archivo << "Número del Producto: " << (i + 1) << ": " << mesa1[i][j].nombre << "\n";
			archivo << "Precio unitario: $" << mesa1[i][j].precio << "\n";
			archivo << "Cantidad adquirida: " << mesa1[i][j].cantidad << "\n";
			archivo << "Total producto: $" << mesa1[i][j].total_producto << "\n";
			archivo << "\n";
		}
	}
	archivo << "Total mesa: $" << total_mesa1 << "\n";
	archivo << "---------------------------------------------------------------------------\n";
	archivo << "\n";

	// mesa 2
	archivo << "Mesa 2\n";
	int total_mesa2 = 0;
	for (int i = 0; i < mesa2.size(); i++)
	{
		for (int j = 0; j < mesa2[i].size(); j++)
		{
			total_mesa2 += mesa2[i][j].total_producto;
			archivo << "Número del Producto: " << (i + 1) << ": " << mesa2[i][j].nombre << "\n";
			archivo << "Precio unitario: $" << mesa2[i][j].precio << "\n";
			archivo << "Cantidad adquirida: " << mesa2[i][j].cantidad << "\n";
			archivo << "Total producto: $" << mesa2[i][j].total_producto << "\n";
			archivo << "\n";
		}
	}
	archivo << "Total mesa: $" << total_mesa2 << "\n";
	archivo << "---------------------------------------------------------------------------\n";
	archivo << "\n";

	// mesa 3
	archivo << "Mesa 3\n";
	int total_mesa3 = 0;
	for (int i = 0; i < mesa3.size(); i++)
	{
		for (int j = 0; j < mesa3[i].size(); j++)
		{
			total_mesa3 += mesa3[i][j].total_producto;
			archivo << "Número del Producto: " << (i + 1) << ": " << mesa3[i][j].nombre << "\n";
			archivo << "Precio unitario: $" << mesa3[i][j].precio << "\n";
			archivo << "Cantidad adquirida: " << mesa3[i][j].cantidad << "\n";
			archivo << "Total producto: $" << mesa3[i][j].total_producto << "\n";
			archivo << "\n";
		}
	}
	archivo << "Total mesa $" << total_mesa3 << "\n";
	archivo << "---------------------------------------------------------------------------\n";
	archivo << "\n";

	// mesa 4
	archivo << "Mesa 4 \n";
	int total_mesa4 = 0;
	for (int i = 0; i < mesa4.size(); i++)
	{
		for (int j = 0; j < mesa4[i].size(); j++)
		{
			total_mesa4 += mesa4[i][j].total_producto;
			archivo << "Número del Producto: " << (i + 1) << ": " << mesa4[i][j].nombre << "\n";
			archivo << "Precio unitario: $" << mesa4[i][j].precio << "\n";
			archivo << "Cantidad adquirida: " << mesa4[i][j].cantidad << "\n";
			archivo << "Total producto: $" << mesa4[i][j].total_producto << "\n";
			archivo << "\n";
		}
	}
	archivo << "Total mesa $" << total_mesa4 << "\n";
	archivo << "---------------------------------------------------------------------------\n";
	archivo << "\n";

	// mesa 5
	archivo << "Mesa 5\n";
	int total_mesa5 = 0;
	for (int i = 0; i < mesa5.size(); i++)
	{
		for (int j = 0; j < mesa5[i].size(); j++)
		{
			total_mesa5 += mesa5[i][j].total_producto;
			archivo << "Número del Producto: " << (i + 1) << ": " << mesa5[i][j].nombre << "\n";
			archivo << "Precio unitario: $" << mesa5[i][j].precio << "\n";
			archivo << "Cantidad adquirida: " << mesa5[i][j].cantidad << "\n";
			archivo << "Total producto: $" << mesa5[i][j].total_producto << "\n";
			archivo << "\n";
		}
	}
	archivo << "Total mesa $" << total_mesa5 << "\n";
	archivo << "---------------------------------------------------------------------------\n";
	archivo << "\n";
	total_general = total_mesa1 + total_mesa2 + total_mesa3 + total_mesa4 + total_mesa5;
	archivo << "TOTAL DE TODAS LAS MESAS: $" << total_general << "\n";
	archivo << "\n";

	archivo.close();
	gotoxy(49, 15);
	cout << NEGRITA_AZUL "Archivo txt generado con éxito" << COLOR_RESET << endl;
}

void registrodeTotales()
{
	// por mesa, y total de mesas
	if (mesa1.size() == 0 && mesa2.size() == 0 && mesa3.size() == 0 && mesa4.size() == 0 && mesa5.size() == 0)
	{
		gotoxy(49, 15);
		cout << NEGRITA_ROJO "No hay ventas para ninguna mesa" COLOR_RESET << endl;
		gotoxy(41, 16);
		cout << "Presione cualquier tecla para regresar al menú";
		cin.get();
	}
	else
	{
		// generar txt con toda la informaci�n
		generarArchivoTxt();
		gotoxy(41, 16);
		cout << "Presione cualquier tecla para regresar al menú";
		cin.get();
	}
}

void mostrarTotalesAlUsuario()
{
	// Para la mesa 1.
	cout << VERDE "\t\t\tMesa 1" COLOR_RESET << endl;
	int total_mesa1 = 0;
	for (int i = 0; i < mesa1.size(); i++)
	{
		for (int j = 0; j < mesa1[i].size(); j++)
		{
			total_mesa1 += mesa1[i][j].total_producto;
			cout << "\t\tProducto " << i + 1 << ": " << mesa1[i][j].nombre << endl;
			cout << "\t\tPrecio Unitario: $" << mesa1[i][j].precio << endl;
			cout << "\t\tCantidad adquirida: " << mesa1[i][j].cantidad << endl;
			cout << "\t\tTotal Producto: $" << mesa1[i][j].total_producto << endl;
		}
	}
	cout << FONDO_VERDE "\t\tTotal de la Mesa: $" << total_mesa1;
	cout << COLOR_RESET << endl;
	cin.get();

	// Para la mesa 2.
	cout << MAGENTA "\t\t\tMesa 2" COLOR_RESET << endl;
	int total_mesa2 = 0;
	for (int i = 0; i < mesa2.size(); i++)
	{
		for (int j = 0; j < mesa2[i].size(); j++)
		{
			total_mesa2 += mesa2[i][j].total_producto;
			cout << "\t\tProducto " << i + 1 << ": " << mesa2[i][j].nombre << endl;
			cout << "\t\tPrecio Unitario: $" << mesa2[i][j].precio << endl;
			cout << "\t\tCantidad adquirida: " << mesa2[i][j].cantidad << endl;
			cout << "\t\tTotal Producto: $" << mesa2[i][j].total_producto << endl;
		}
	}
	cout << FONDO_MAGENTA "\t\tTotal de la Mesa: $" << total_mesa2;
	cout << COLOR_RESET << endl;
	cin.get();

	// Para la mesa 3.
	cout << CIAN "\t\t\tMesa 3" COLOR_RESET << endl;
	int total_mesa3 = 0;
	for (int i = 0; i < mesa3.size(); i++)
	{
		for (int j = 0; j < mesa3[i].size(); j++)
		{
			total_mesa3 += mesa3[i][j].total_producto;
			cout << "\t\tProducto " << i + 1 << ": " << mesa3[i][j].nombre << endl;
			cout << "\t\tPrecio Unitario: $" << mesa3[i][j].precio << endl;
			cout << "\t\tCantidad adquirida: " << mesa3[i][j].cantidad << endl;
			cout << "\t\tTotal Producto: $" << mesa3[i][j].total_producto << endl;
		}
	}
	cout << FONDO_CIAN "\t\tTotal de la Mesa: $" << total_mesa3;
	cout << COLOR_RESET << endl;
	cin.get();

	// Para la mesa 4.
	cout << AMARILLO "\t\t\tMesa 4" COLOR_RESET << endl;
	int total_mesa4 = 0;
	for (int i = 0; i < mesa4.size(); i++)
	{
		for (int j = 0; j < mesa4[i].size(); j++)
		{
			total_mesa4 += mesa4[i][j].total_producto;
			cout << "\t\tProducto " << i + 1 << ": " << mesa4[i][j].nombre << endl;
			cout << "\t\tPrecio Unitario: $" << mesa4[i][j].precio << endl;
			cout << "\t\tCantidad adquirida: " << mesa4[i][j].cantidad << endl;
			cout << "\t\tTotal Producto: $" << mesa4[i][j].total_producto << endl;
		}
	}
	cout << FONDO_AMARILLO "\t\tTotal de la Mesa: $" << total_mesa4;
	cout << COLOR_RESET "" << endl;
	cin.get();

	// Para la mesa 5.
	cout << AZUL "\t\t\tMesa 5" COLOR_RESET << endl;
	int total_mesa5 = 0;
	for (int i = 0; i < mesa5.size(); i++)
	{
		for (int j = 0; j < mesa5[i].size(); j++)
		{
			total_mesa5 += mesa5[i][j].total_producto;
			cout << "\t\tProducto " << i + 1 << ": " << mesa5[i][j].nombre << endl;
			cout << "\t\tPrecio Unitario: $" << mesa5[i][j].precio << endl;
			cout << "\t\tCantidad adquirida: " << mesa5[i][j].cantidad << endl;
			cout << "\t\tCantidad adquirida: " << mesa5[i][j].cantidad << endl;
			cout << "\t\tTotal Producto: $" << mesa5[i][j].total_producto << endl;
		}
	}
	cout << FONDO_AZUL "\t\tTotal de la Mesa: $" << total_mesa5;
	cout << COLOR_RESET << endl;
	cin.get();
}

void mostrarMenu()
{
	limpiarPantalla();
	gotoxy(55, 3);
	cout << "Menú de Opciones: Cafetería" << endl;
	gotoxy(30, 4);
	cout << AZUL "============================================================================" COLOR_RESET << endl;
	cout << "Elija una Opción " << endl;
	cout << "1.- Mostrar Especialidades" << endl;
	cout << "2.- Generar Ordenes" << endl;
	cout << "3.- Mostrar Totales por Mesa" << endl;
	cout << "4.- Generar Registro" << endl;
	cout << FONDO_ROJO "0.- Salir del Programa... " COLOR_RESET << endl;
	cout << "¿Que desea hacer?:";
}

void menuPrincipal()
{
	string opc_menu = "1";
	while (opc_menu != "0")
	{
		mostrarMenu();
		getline(cin, opc_menu);
		limpiarPantalla();
		if (opc_menu == "1")
		{
			cin.clear();
			mostrarEspecialidades();
		}
		else if (opc_menu == "2")
		{
			cin.clear();
			generarOrdenes();
		}
		else if (opc_menu == "3")
		{
			cin.clear();
			mostrarTotalesAlUsuario();
		}
		else if (opc_menu == "4")
		{
			cin.clear();
			registrodeTotales();
		}
		else if (opc_menu == "0")
		{
			break;
		}
		else
		{
			gotoxy(49, 15);
			cout << ROJO "Upss..¡Esa no es una opción correcta!" COLOR_RESET << endl;
			cin.get();
			limpiarPantalla();
		}
	}
}