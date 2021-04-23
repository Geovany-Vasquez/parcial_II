#pragma once
#include <iostream>
#include <mysql.h>
using namespace std;

class conexion_bd
{
private:  MYSQL* conectar;
public:
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "Usr_parcial", "parcial@20301", "parcial_ii", 3306, NULL, 0);
	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}

};

