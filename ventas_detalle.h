#pragma once
#include "conexion_bd.h"
#include <iostream>
#include <mysql.h>

class ventas_detalle{

protected: string product, descripcion, Imagen, fecha_ingreso;
		 int idMarca, existencia;
		 float precio_costo, precio_venta;
		 
protected:
	ventas_detalle() {
	}
	ventas_detalle(string prod, int id_m, string desc, string Ima, float prec, float prev, int exis, string fn  ) {
		product = prod;
		idMarca = id_m;
		descripcion = desc;
		Imagen = Ima;
		precio_costo = prec;
		precio_venta = prev;
		existencia = exis;
		fecha_ingreso = fn;

	}
};

