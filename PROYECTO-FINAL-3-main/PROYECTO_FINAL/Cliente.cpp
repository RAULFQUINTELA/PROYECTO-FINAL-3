#include "Cliente.h"

// Constructor con parámetros
Cliente::Cliente(string _login, string _password, string _calificacion, string _deudas)
    : Usuario(_login, _password), calificacionCliente(_calificacion), deudasPendientesCliente(_deudas)
{
    cout << "¡Bienvenido, estimado cliente " << _login << "! Gracias por unirte a nuestra aplicacion." << endl;
}

bool Cliente::verificarLogin(string _username, string _password)
{
    return (getLogin() == _username && getPassword() == _password);
}