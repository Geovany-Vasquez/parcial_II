#pragma once
#include <iostream>
#include <string>
#include <mysql.h>
#include "conexion_bd.h"
#include "ventas_detalle.h"
class producto : ventas_detalle{

public:

	producto() {

	}

	producto(string prod, int id_m, string desc, string Ima, float prec, float prev, int exis, string fn) : ventas_detalle(prod, id_m, desc, Ima, prec, prev, exis, fn ) {

	}
	// METODOS

	//set (modificar)

	void setProduct(string prod) { product = prod; }
	void setDescripcion(string desc) { descripcion = desc; }
	void setImagen(string Ima) { Imagen = Ima; }
	void setFecha_ingreso(string fn) {fecha_ingreso = fn; }
	void setidMarca(int id_m) { idMarca = id_m; }
	void setExistencia(int exis) { existencia = exis; }
	void setPrecio_costo(float prec) { precio_costo = prec; }
	void setPrecio_venta(float prev) { precio_venta = prev; }

	//get (mostrar)

	string getProduct() { return product; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return Imagen; }
	string getFecha_ingreso() { return fecha_ingreso; }
	int getidMarca() { return idMarca; }
	int getExistencia() { return existencia; }
	float getPrecio_costo() { return precio_costo; }
	float getPrecio_venta() { return precio_venta; }
	
	// metodo
	void crear() {
		int q_estado;
		conexion_bd cn = conexion_bd();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idMarca);
			string pc = to_string(precio_costo);
			string pv = to_string(precio_venta);
			string ex = to_string(existencia);
			string insert = "insert into parcial_ii.productos(producto, idMarca, descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso)values('"+ product +"','"+ t +"','" + descripcion +"','" + Imagen +"','" + pc +"','" + pv +"','" + ex +"','" + fecha_ingreso +"');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso" << endl;
			}
			else {
				cout << "error al ingresar la informacion" << endl;
			}
		}
		else {
			cout << "---Error en la conexion---" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		conexion_bd cn = conexion_bd();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if(cn.getConectar()){
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "|---------------------------------------------------------------------------------------------------|" << endl;
				cout << "|---------------------------------------////// productos //////-------------------------------------|" << endl;
				cout << "|___________________________________________________________________________________________________|" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "|" << fila[1] << "|" << fila[2] << "|" << fila[3] << "|" << fila[4] << "|" << fila[5] << "|" << fila[6] << "|" << fila[7] << "|" << fila[8] << endl;
				}
			}
			else {
				cout << "....Error al consultar..." << endl;
		}
	}
		else {
			cout << "---Error en la conexion---" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizar(int prod) {

		int q_estado;
		conexion_bd cn = conexion_bd();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Id = to_string(prod);
			string prod, des, imagen, fecha = "now()";
			int idmarca = 0, exist = 0;
			float prec, prev;

			string consulta = "select * from productos where idProducto= " + Id + "";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "idProducto: " << fila[0] << endl;
					cout << "producto: " << fila[1] << endl;
					cout << "idMarca: " << fila[2] << endl;
					cout << "descripcion: " << fila[3] << endl;
					cout << "Imagen: " << fila[4] << endl;
					cout << "precio_costo: " << fila[5] << endl;
					cout << "precio_venta " << fila[6] << endl;
					cout << "existencia: " << fila[7] << endl;
					cout << "fecha_ingreso: " << fila[8] << endl;

					cout << ("\n\nNuevo Producto: ") << fila[1] << endl;
					cin >> prod;

					cout << ("\n\n Nuevo id marca: ") << fila[2] << endl;
					cin >> idmarca;
					cin.ignore();
					cout << ("\n\nNueva decripcion: ") << fila[3] << endl;
					getline(cin, des);

					cout << ("\n\nNueva imagen: ") << fila[4] << endl;
					cin >> imagen;
					cin.ignore();

					cout << ("\n\nNuevo precio costo: ") << fila[5] << endl;
					cin >> prec;
					cin.ignore();

					cout << ("\n\nNuevo precio venta: ") << fila[6] << endl;
					cin >> prev;
					cin.ignore();

					cout << ("\n\nNueva existencia: ") << fila[7] << endl;
					cin >> exist;
					cin.ignore();
					cout << ("\n\nFecha: ") << fila[8] << endl;

					string q = to_string(idmarca);
					string w = to_string(exist);
					string e = to_string(prec);
					string r = to_string(prev);


					string consulta = "update productos set Producto = '" + prod + "',idMarca = " + q + ", descripcion = '" + des + "', Imagen = '" + imagen + "', precio_costo = " + e + ", precio_venta = " + r + ", existencia = " + w + ", fecha_ingreso = " + fecha + "  where idProducto = " + Id + "";

					const char* c = consulta.c_str();
					q_estado = mysql_query(cn.getConectar(), c);
					cout << "datos actualizados correctamente" << endl;
				}

			}
			else {
				cout << "\n\n--------- Error al modificar  ---------" << endl;
			}

		}
		else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int prod) {
		int q_estado;
		conexion_bd cn = conexion_bd();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		char m;
	if (cn.getConectar()) {
	string id = to_string(prod);

	string consulta = "select * from productos where idProducto= " + id + "";
	const char* c = consulta.c_str();
	q_estado = mysql_query(cn.getConectar(), c);

	if (!q_estado) {
		resultado = mysql_store_result(cn.getConectar());

		while (fila = mysql_fetch_row(resultado)) {

			cout << "idProducto: " << fila[0] << endl;
			cout << "producto: " << fila[1] << endl;
			cout << "idMarca: " << fila[2] << endl;
			cout << "descripcion: " << fila[3] << endl;
			cout << "Imagen: " << fila[4] << endl;
			cout << "precio_costo: " << fila[5] << endl;
			cout << "precio_venta " << fila[6] << endl;
			cout << "existencia: " << fila[7] << endl;
			cout << "fecha_Ingreso: " << fila[8] << endl;
			cout << ("\n\nDesea eliminar  s/n: ");
			cin >> m;
			if (m == 's') {
				string consulta = "delete from productos where idProducto =" + id + "";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				cout << ("\n\nDatos Eliminados correctamente");
			}
		}

	}
	else {
		cout << "\n\n--------- Error al eliminar ---------" << endl;
	}

}
		else {
		cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();

	}

};

