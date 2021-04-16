/*
 * File:   Producto.cpp
 * Author: algarcia
 *
 * Created on 16 de abril de 2021, 12:24
 */

#include <stdexcept>

#include "Producto.h"
#include "MiExcepcion.h"

Producto::Producto ( float nPM ): _precioMensual ( nPM )
{
   if ( nPM < 0 )
   {
      throw MiExcepcion ( "Producto.cpp", "Producto::Producto",
                          "Precio de producto no válido" );
   }
}

Producto::Producto ( const Producto& orig ): _precioMensual ( orig._precioMensual )
{ }

Producto::~Producto ( )
{ }

float Producto::getPrecioMensual ( )
{
   return _precioMensual;
}

void Producto::setPrecioMensual ( float nPM )
{
   if ( nPM < 0 )
   {
      throw MiExcepcion ( "Producto.cpp", "Producto::setPrecioMensual",
                          "Precio de producto no válido" );
   }

   _precioMensual = nPM;
}

Producto& Producto::operator = ( const Producto& otro )
{
   if ( this != &otro )
   {
      _precioMensual = otro._precioMensual;
   }
}
