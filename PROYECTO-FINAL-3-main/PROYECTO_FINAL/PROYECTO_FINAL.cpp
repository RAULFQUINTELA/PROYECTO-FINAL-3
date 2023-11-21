#include <iostream>
#include <string>
#include "Cliente.h"
#include "Chofer.h"
#include "RegistroPasajero.h"
#include "RegistroChofer.h"

using namespace std;

// Funciones para las opciones del menú
void iniciarSesion(Cliente& cliente, Chofer& chofer)
{
    string username, password;

    cout << "Ingrese su nombre de usuario: ";
    cin >> username;
    cout << "Ingrese su contraseña: ";
    cin >> password;
    // Verificar si el usuario es un Cliente registrado
    if (cliente.verificarLogin(username, password))
    {
        cout << "¡Inicio de sesión exitoso como cliente!" << endl;
        // Puedes realizar acciones específicas para clientes aquí
    }
    // Verificar si el usuario es un Chofer registrado
    else if (chofer.verificarLogin(username, password))
    {
        cout << "¡Inicio de sesión exitoso como chofer!" << endl;
        // Puedes realizar acciones específicas para choferes aquí
    }
    else
    {
        cout << "Nombre de usuario o contraseña incorrectos. Por favor, regístrese primero." << endl;
    }
}

Cliente registrarCliente()
{
    // Registro de Pasajero
    Cliente nuevoPasajero = RegistroPasajero::registrarPasajero();
    cout << "Registro exitoso como cliente. Ahora puedes iniciar sesion." << endl;
    return nuevoPasajero;
}

Chofer registrarChofer()
{
    // Registro de Chofer
    Chofer nuevoChofer = RegistroChofer::registrarChofer();
    cout << "Registro exitoso como chofer. Ahora puedes iniciar sesion." << endl;
    return nuevoChofer;
}

int main()
{
    Cliente clienteActual("default_login", "default_password", "0", "0"); // Cliente actualmente en sesión
    Chofer choferActual("default_login", "default_password", "0", "0");  // Chofer actualmente en sesión

    int opcion;

    do
    {
        cout << "Bienvenido a la aplicacion. Por favor, elige tu opcion:" << endl;
        cout << "1. Iniciar Sesion" << endl;
        cout << "2. Registrarse como Cliente" << endl;
        cout << "3. Registrarse como Chofer" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese el numero correspondiente a su eleccion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: iniciarSesion(clienteActual, choferActual); break;
        case 2: clienteActual = registrarCliente(); break;
        case 3: choferActual = registrarChofer(); break;
        case 4: cout << "Gracias por usar la aplicacion. ¡Hasta luego!" << endl; break;
        default: cout << "Opcion no valida. Por favor, elige una opcion valida." << endl; break;
        }

    } while (opcion != 4);

    return 0;
}