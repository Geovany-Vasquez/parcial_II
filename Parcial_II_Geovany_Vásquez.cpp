#include <iostream>
#include <mysql.h>
#include "conexion_bd.h"
#include "producto.h"

using namespace std;

int main()
{
	/*
	string product, descripcion, Imagen, fecha_ingreso;
	int idMarca, existencia;
	float precio_costo, precio_venta;
	cout << "ingrese el producto: ";
	getline(cin, product);
	cout << "ingrese el ID de la marca: ";
	cin >> idMarca;
	cin.ignore();
	cout << "ingrese la descripcion: ";
	getline(cin, descripcion);
	cout << "ingrese la imagen: ";
	getline(cin, Imagen);
	cout << "ingrese el precio costo del producto: ";
	cin >> precio_costo;
	cin.ignore();
	cout << "ingrese el precio venta del producto: ";
	cin >> precio_venta;
	cin.ignore();
	cout << "ingrese el numero de existencias: ";
	cin >> existencia;
	cin.ignore();
	cout << "ingrese la fecha de ingreso: ";
	getline(cin, fecha_ingreso);


	producto c = producto(product, idMarca, descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
	c.crear();*/

	/*
			int prod;
			cout << ("Ingrese Id a eliminar: ");
			cin >> prod;
			producto c = producto();
			c.eliminar(prod);
			system("pause");*/

		int prod;
		cout << ("Ingrese Id a modificar: ");
		cin >> prod;
		producto c = producto();
		c.actualizar(prod);
		system("pause");
                            	
};


