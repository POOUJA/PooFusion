/**
 * @file Producto.cpp
 * @author algarcia
 *
 * @date 16 de abril de 2021, 12:24
 *
 * @brief Implementación de la clase Producto
 */

#include <stdexcept>

#include "Producto.h"
#include "PooFusionExc.h"

/**
 * Constructor parametrizado
 * @param nPM Precio del producto que se crea
 * @throw PooFusionExc Si el precio del producto es negativo
 */
Producto::Producto ( float nPM ): _precioMensual ( nPM )
{
   if ( nPM < 0 )
   {
      throw PooFusionExc ( "Producto::Producto", "Precio de producto no válido"
                         , "Producto.cpp" );
   }
}


/**
 * Constructor de copia
 * @param orig Producto del que se copia la información
 */
Producto::Producto ( const Producto& orig ): _precioMensual ( orig._precioMensual )
{ }


/**
 * Destructor
 */
Producto::~Producto ( )
{ }


/**
 * Consulta el precio mensual del producto
 * @return El precio mensual del producto
 */
float Producto::getPrecioMensual ( )
{
   return _precioMensual;
}


/**
 * Cambia el precio mensual del producto
 * @param nPM Nuevo precio mensual
 * @throw PooFusionExc Si el nuevo precio es menor de cero
 */
void Producto::setPrecioMensual ( float nPM )
{
   if ( nPM < 0 )
   {
      throw PooFusionExc ( "Producto::setPrecioMensual"
                         , "Precio de producto no válido", "Producto.cpp" );
   }

   _precioMensual = nPM;
}


/**
 * Operador de asignación
 * @param otro Producto del que se copian los atributos
 * @return Una referencia al propio producto, para permitir encadenar las
 *         asignaciones
 */
Producto& Producto::operator = ( const Producto& otro )
{
   if ( this != &otro )
   {
      _precioMensual = otro._precioMensual;
   }

   return *this;
}
