#pragma once
#include "conexion_bd.h"
#include <iostream>
#include <mysql.h>

class marcas{
protected: string marca;
		
protected:
	marcas() {
	}
	marcas(string marc) {
		marca = marc;
		
	}
};
