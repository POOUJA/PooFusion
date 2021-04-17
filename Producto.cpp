/**
 * @file Producto.cpp
 * @author algarcia
 *
 * @date 14 de abril de 2021, 20:16
 */

#include "Producto.h"

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
   this->_precioMensual = nPM;
}

Producto& Producto::operator= ( const Producto& otro )
{
   if ( this != &otro )
   {
      _precioMensual = otro._precioMensual;
   }

   return *this;
}
