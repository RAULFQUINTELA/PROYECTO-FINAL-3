#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;

class Cliente : public Usuario
{
private:
    string calificacionCliente;
    string deudasPendientesCliente;

public:
    // Constructor con parámetros
    Cliente(string _login, string _password, string _calificacion, string _deudas);

    bool verificarLogin(string _username, string _password);
};