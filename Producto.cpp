/*
 * File:   Producto.cpp
 * Author: algarcia
 *
 * Created on 16 de abril de 2021, 12:24
 */

#include <stdexcept>

#include "Producto.h"

Producto::Producto ( float nPM ): _precioMensual ( nPM )
{ }

Producto::Producto ( const Producto& orig ): _precioMensual ( orig._precioMensual )
{ }

Producto::~Producto ( )
{ }

float Producto::getPrecioMensual ( ) const
{
   return _precioMensual;
}

void Producto::setPrecioMensual ( float nPM )
{
   if ( nPM < 0 )
   {
      throw std::invalid_argument ( "[Producto::setPrecioMensual]: precio"
                                    " incorrecto" );
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
