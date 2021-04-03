/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 29 de marzo de 2021, 17:57
 */

#include <cstdlib>
#include <iostream>

#include "Persona.h"
#include "MiExcepcion.h"

using namespace std;

void muestraPaqueteCanales ( PaqueteDeCanales& paramPC )
{
   std::cout << "Paquete de canales que contiene "
             << paramPC.getC1 ()->getNombre () << " y "
             << paramPC.getC2 ()->getNombre ();
}

/**
 * @brief Muestra la información de una persona por consola
 * @param paramP Persona de la que muestra la información
 */
void muestraPersona ( Persona& paramP )
{
   std::cout << "La persona se llama " << paramP.getApeNom () << std::endl
             << "está abonada a ";

   muestraPaqueteCanales ( *paramP.getPaqueteC () );

   std::cout << std::endl
             << "y tiene contratada una conexión de tipo "
             << paramP.getConexion ()->getTipo () << " a una velocidad de "
             << paramP.getConexion ()->getVelocidadMB () << " MB" << std::endl;
}

/**
 * @brief Punto de inicio de la aplicación
 */
int main ( int argc, char** argv )
{
   // Creación de un objeto de clase Persona
   Persona p;
   p.setApeNom ( "Martínez, Manuel" );
   p.setNif ( "12345678-K" );

   // Creación de objetos de clase ConexionInternet
   ConexionInternet c, otraC;
   c.setTipo ( "Fibra" );
   c.setVelocidadMB ( 300 );
   otraC.setTipo ( "WiMAX" );
   otraC.setVelocidadMB ( 20 );

   // Creación de un objeto de clase Canal
   Canal c2;
   c2.setNombre ( "DAZN" );

   std::cout << "La persona se llama " << p.getApeNom () << std::endl
             << "El canal de televisión es " << c2.getNombre () << std::endl
             << "La conexión es " << c.getTipo () << " a "
             << c.getVelocidadMB () << " MB" << std::endl << std::endl;

   // Creación de copia en memoria automática (pila)
   Persona p2 ( p );

   std::cout << "La persona copiada se llama " << p2.getApeNom ()
             << std::endl << std::endl;

   // Creación de copia en memoria dinámica (heap)
   Persona* ptrP = new Persona ( p );

   std::cout << "La persona copiada se llama " << ptrP->getApeNom ()
             << std::endl << std::endl;

   // Creación de array de objetos en memoria automática (pila)
   Persona aP[3];

   aP[0].setApeNom ( "Pérez, Pedro" );
   aP[0].setNif ( "11111111-A" );
   aP[1].setApeNom ( "Álvarez, Antonio" );
   aP[1].setNif ( "22222222-B" );
   aP[2].setApeNom ( "González, Gabriel" );
   aP[2].setNif ( "33333333-C" );

   // Creación de array de objetos en memoria dinámica (heap)
   Canal* aC = new Canal[3];

   aC[0].setNombre ( "Eurosport" );
   aC[1].setNombre ( "TDP" );
   aC[2].setNombre ( "#Vamos" );

   // Uso del operador de asignación
   std::cout << "Antes de la asignación, el nombre es " << p2.getApeNom ()
             << std::endl;
   p2 = aP[0];
   std::cout << "Después de la asignación el nombre es " << p2.getApeNom ()
             << std::endl << std::endl;

   // Uso de los operadores de comparación
   if ( c < otraC )
   {
      std::cout << "La conexión " << c.getTipo ()
                << " es más lenta que la conexión " << otraC.getTipo ()
                << std::endl << std::endl;
   }
   else
   {
      if ( c == otraC )
      {
         std::cout << "La conexión " << c.getTipo ()
                   << " es igual de rápida que la conexión " << otraC.getTipo ()
                   << std::endl << std::endl;
      }
      else
      {
         std::cout << "La conexión " << c.getTipo ()
                   << " es más rápida que la conexión " << otraC.getTipo ()
                   << std::endl << std::endl;
      }
   }

   // Captura de excepciones
   //aP[0].setNif ( "" ); // Descomenta esta línea para ver qué pasa si no se captura
   try
   {
      aP[2].setApeNom ("");
   }
   catch ( MiExcepcion& e )
   {
      std::cerr << e.quePasa () << std::endl << std::endl;
   }

   // Creación de un paquete de canales
   PaqueteDeCanales pC1 ( &c2, &aC[1], 20 );

   // Relaciona un paquete de canales y una conexión con una persona
   p.setPaqueteC ( &pC1 );
   p.setConexion ( &c );

   // Comprobamos que se ha relacionado correctamente
   muestraPersona ( p );

   // Hay que liberar la memoria dinámica reservada antes de finalizar el programa
   delete ptrP;
   ptrP = nullptr;

   delete [] aC;
   aC = nullptr;

   // La memoria automática se libera automáticamente (valga la redundancia)
   return 0;
}

