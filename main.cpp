/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 29 de marzo de 2021, 17:57
 */

#include <cstdlib>

#include "PooFusion.h"

using namespace std;

/**
 * @brief Punto de inicio de la aplicación
 */
int main ( int argc, char** argv )
{
   // Creación de una variable de tipo Persona
   PooFusion::Persona p;

   // Asignación de valores a los campos
   p.apeNom = "García, Javier";
   p.nif = "12345678-K";

   // Creación de una variable de tipo ConexionInternet
   PooFusion::ConexionInternet c;

   // Asignación de valores a los campos
   c.tipo = "Fibra óptica";
   c.velocidadMB = 300;

   // Creación de una variable de tipo Canal
   PooFusion::Canal c2;

   // Asignación de valores a los campos
   c2.nombre = "Eurosport";

   PooFusion::mostrarPersona ( p );
   PooFusion::mostrarConexion ( c );
   PooFusion::mostrarCanal ( c2 );

   return 0;
}

