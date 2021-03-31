/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 29 de marzo de 2021, 17:57
 */

#include <cstdlib>
#include <iostream>

#include "Persona.h"
#include "Canal.h"
#include "ConexionInternet.h"

using namespace std;

/**
 * @brief Punto de inicio de la aplicación
 */
int main ( int argc, char** argv )
{
   // Creación de un objeto de clase Persona
   Persona p;
   p.setApeNom ( "Martínez, Manuel" );
   p.setNif ( "12345678-K" );

   // Creación de un objeto de clase ConexionInternet
   ConexionInternet c;
   c.setTipo ( "Fibra" );
   c.setVelocidadMB ( 300 );

   // Creación de un objeto de clase Canal
   Canal c2;
   c2.setNombre ( "DAZN" );

   std::cout << "La persona se llama " << p.getApeNom () << std::endl
             << "El canal de televisión es " << c2.getNombre () << std::endl
             << "La conexión es " << c.getTipo () << " a "
             << c.getVelocidadMB () << " MB" << std::endl;

   // Creación de copia en memoria automática (pila)
   Persona p2 ( p );

   std::cout << "La persona copiada se llama " << p2.getApeNom () << std::endl;

   // Creación de copia en memoria dinámica (heap)
   Persona* ptrP = new Persona ( p );

   std::cout << "La persona copiada se llama " << ptrP->getApeNom () << std::endl;

   // Hay que liberar la memoria dinámica reservada antes de finalizar el programa
   delete ptrP;
   ptrP = nullptr;

   return 0;
}

