/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 29 de marzo de 2021, 17:57
 */

#include <cstdlib>
#include <iostream>

#include "Persona.h"
#include "PooFusionExc.h"
#include "Contrato.h"

using namespace std;

/**
 * @brief Muestra la información de una persona por consola
 * @param paramP Persona de la que muestra la información
 */
void mostrar ( Persona& paramP )
{
   std::cout << "La persona se llama " << paramP.getApeNom () << ". NIF "
             << paramP.getNif () << std::endl;
}

/**
 * Muestra la información relativa a un contrato
 * @param paramC Contrato del que se muestra la información
 */
void mostrar ( Contrato& paramC )
{
    std::cout << "Contrato con fecha " << paramC.getFechaDeAlta() << std::endl
            << "===========================" << std::endl
            << "Abonado: " << paramC.getAbonado()->getApeNom() << std::endl;

    for (int i = 1; i <= paramC.getNumProductos(); i++)
    {
        std::cout << paramC.getProducto(i).getDescripcion() << std::endl;
    }

    std::cout << "El precio mensual del contrato es "
            << paramC.getPrecioMensual() << std::endl;

    if (paramC.estaActivo())
    {
        std::cout << std::endl << "Actualmente activo";
    }
    else
    {
        std::cout << std::endl << "Actualmente NO activo";
    }
    std::cout << std::endl;
}

/**
 * @brief Punto de inicio de la aplicación
 */
int main ( int argc, char** argv )
{
   // Creación de un objeto de clase Persona
   Persona p;
   p.setApeNom ( "Martínez, Manuel" )
    .setNif ( "12345678-K" );

   // Creación de objetos de clase ConexionInternet
   ConexionInternet c, otraC;

   c.setTipo ( "Fibra" )
    .setVelocidadMB ( 300 )
    .setPrecioMensual ( 30 );

   otraC.setTipo ( "WiMAX" )
        .setVelocidadMB ( 20 )
        .setPrecioMensual ( 20 );

    // Creación de objetos de clase Canal
    Canal c1, c2;
    c1.setNombre("DAZN").setPrecioMensual(5);
    c2.setNombre("POO 24h").setPrecioMensual(42);

    mostrar(p);
    std::cout << c2.getDescripcion() << std::endl
            << c.getDescripcion() << std::endl;

   // Creación de copia en memoria automática (pila)
   Persona p2 ( p );

   std::cout << "La persona copiada en memoria automática es: " << std::endl;
   mostrar ( p2 );

   // Creación de copia en memoria dinámica (heap)
   Persona* ptrP = new Persona ( p );

   std::cout << "La persona copiada en memoria dinámica es: " << std::endl;
   mostrar ( *ptrP );

   // Creación de array de objetos en memoria automática (pila)
   Persona aP[3];

   aP[0].setApeNom ( "Pérez, Pedro" )
        .setNif ( "11111111-A" );
   aP[1].setApeNom ( "Álvarez, Antonio" )
        .setNif ( "22222222-B" );
   aP[2].setApeNom ( "González, Gabriel" )
        .setNif ( "33333333-C" );

    // Creación de array de objetos en memoria dinámica (heap)
    Canal* aC = new Canal[4];

    aC[0].setNombre("Eurosport").setPrecioMensual(3);
    aC[1].setNombre("TDP").setPrecioMensual(2);
    aC[2].setNombre("#Vamos").setPrecioMensual(7);
    aC[3].setNombre("Paramount").setPrecioMensual(7);

    // Uso del operador de asignación
    std::cout << "Antes de la asignación: " << std::endl;
    mostrar(p2);

   p2 = aP[0];

   std::cout << "Después de la asignación: " << std::endl;
   mostrar ( p2 );

    // Uso de los operadores de comparación
    if (c < otraC)
    {
        std::cout << "La conexión " << c.getTipo()
                << " es más lenta que la conexión " << otraC.getTipo()
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
       aP[2].setApeNom("");
    }
    catch (PooFusionExc& e)
    {
        std::cerr << e.quePasa() << std::endl << std::endl;
    }

    // Creación de un paquete de canales
    PaqueteDeCanales pC1(20);

    //Captura de excepciones independientes
    try
    {
        pC1.addCanal(&c1);
        pC1.addCanal(&c2);
        pC1.addCanal(&aC[2]);
        pC1.addCanal(&aC[1]);
        pC1.addCanal(&aC[0]);
        pC1.addCanal(&aC[3]); //este canal no se podrá añadir
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl << std::endl;
    }
    catch (PooFusionExc &e)
    {
        std::cerr << e.quePasa() << std::endl << std::endl;
    }
    try
    {
        pC1.addCanal(nullptr); //No se admite un canal nulo en la agregación
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl << std::endl;
    }
    catch (PooFusionExc &e)
    {
        std::cerr << e.quePasa() << std::endl << std::endl;
    }

   // Crea un nuevo contrato
   Contrato cto01 ( &p );

   try
   {
      cto01.addProducto ( c2 );
   }
   catch ( PooFusionExc& e )
   {
      std::cerr << "Capturada excepción: " << e.quePasa () << std::endl;
   }

   // Introduce datos en el contrato
   cto01.addProducto ( ConexionInternet ( "Fibra", 300, 30 ) )
        .addProducto ( c2 )
        .addProducto ( aC[0] )
        .addProducto ( aC[2] )
        .addProducto ( pC1 )
        .setCuentaBancaria ( "ES23 1234 1234 1234 1234" )
        .setActivo ( true );

   // Comprobamos el contrato
   mostrar ( cto01 );

   // Utilizamos la plantilla de contenedor que hemos creado
   Contenedor<Persona> clientes ( 3 );
   clientes.addElemento ( Persona ( "Er pobre Migué", "1234-X" ) )
           .addElemento ( Persona ( "El Risitas", "9876-Y" ) );

   mostrar ( clientes.getElemento ( 0 ) );
   mostrar ( clientes.getElemento ( 1 ) );

   // Hay que liberar la memoria dinámica reservada antes de finalizar el programa
   delete ptrP;
   ptrP = nullptr;

   delete [] aC;
   aC = nullptr;

   // La memoria automática se libera automáticamente (valga la redundancia)
   return 0;
}

