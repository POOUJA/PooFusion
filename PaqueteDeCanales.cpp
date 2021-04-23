/**
 * @file PaqueteDeCanales.cpp
 * @author algarcia
 *
 * @date 3 de abril de 2021, 9:38
 *
 * @brief Implementación de los métodos de la clase PaqueteDeCanales
 */

#include <sstream>

#include "PaqueteDeCanales.h"
#include "PooFusionExc.h"

/**
 * Constructor parametrizado
 * @param nDesc Descuento a aplicar
 * @post El nuevo paquete tiene el descuento pasado como parámetro
 * @throw PooFusionExc Si el descuento es negativo
 */
PaqueteDeCanales::PaqueteDeCanales ( float nDesc ): Producto ()
                                                  , _descuento ( nDesc )
                                                  , _canales ( MAX_CANALES, nullptr )
{
   if ( nDesc < 0 )
   {
      throw PooFusionExc ( "PaqueteDeCanales::PaqueteDeCanales"
                         , "El descuento no puede ser negativo"
                         , "PaqueteDeCanales.cpp" );
   }
}


/**
 * Constructor de copia
 * @param orig Paquete del que se copia la información
 * @post El nuevo paquete tiene una copia exacta de los valores del original
 */
PaqueteDeCanales::PaqueteDeCanales ( const PaqueteDeCanales& orig ):
                                   Producto ( orig )
                                 , _descuento ( orig._descuento )
                                 , _canales ( orig._canales )
{ }


/**
 * Destructor
 * @note Solamente rompe la vinculación entre el paquete y los canales. NO es
 *       responsable de eliminar los canales
 */
PaqueteDeCanales::~PaqueteDeCanales ( )
{
   int nCanales = _canales.getNumElementos ();

   for ( int i = 0; i < nCanales; i++ )
   {
      _canales.sacaElemento ( 0 );
   }
}


/**
 * Cambia el descuento del paquete de canales
 * @param descuento Nuevo valor de descuento a aplicar
 * @post El descuento del paquete cambia al valor pasado como parámetro
 * @throw PooFusionExc Si el nuevo descuento es un número negativo
 */
PaqueteDeCanales& PaqueteDeCanales::setDescuento ( float nDesc )
{
   if ( nDesc < 0 )
   {
      throw PooFusionExc ( "PaqueteDeCanales::setDescuento"
                         , "El descuento no puede ser negativo"
                         , "PaqueteDeCanales.cpp" );
   }

   this->_descuento = nDesc;

   return *this;
}


/**
 * Consulta el descuento del paquete de canales
 * @return El descuento del paquete de canales
 */
float PaqueteDeCanales::getDescuento ( ) const
{
   return _descuento;
}


/**
 * Consulta el precio mensual del paquete de canales
 * @return El precio mensual del paquete de canales, calculado sumando los
 *         precios de los canales y aplicando el descuento del paquete
 */
float PaqueteDeCanales::getPrecioMensual ( )
{
   float suma = 0;

   for ( int i = 0; i < _canales.getNumElementos (); i++ )
   {
      suma += _canales.getElemento (i)->getPrecioMensual ();
   }

   suma -= ( suma * _descuento / 100.0 );

   return suma;
}


/**
 * Añade un nuevo canal al paquete
 * @param nuevoC Canal a añadir
 * @pre El canal nuevo no está ya incluido en el paquete
 * @post El paquete de canales contiene un canal más
 * @throw PooFusionExc Si no caben más canales en el paquete
 */
PaqueteDeCanales& PaqueteDeCanales::addCanal ( Canal* nuevoC )
{
   try
   {
      _canales.addElemento ( nuevoC );
   }
   catch ( std::length_error &e )
   {
      throw PooFusionExc ( "PaqueteDeCanales::addCanal", e.what ()
                         , "PaqueteDeCanales.cpp" );
   }

   return *this;
}


/**
 * Consulta un canal del paquete
 * @param cual Ordinal del canal que se quiere consultar (rango: 1..número de
 *        canales)
 * @return La dirección de memoria del canal
 * @throw PooFusionExc Si el ordinal está fuera del rango indicado
 */
Canal* PaqueteDeCanales::getCanal ( int cual )
{
   Canal* aDevolver = nullptr;

   try
   {
      aDevolver = _canales.getElemento ( cual-1 );
   }
   catch ( std::out_of_range &e )
   {
      throw PooFusionExc ( "PaqueteDeCanales::getCanal", e.what ()
                         , "PaqueteDeCanales.cpp" );
   }

   return aDevolver;
}


/**
 * Saca un canal del paquete
 * @param cual Ordinal del canal que se quiere sacar (rango: 1..número de
 *        canales)
 * @post El paquete tiene un canal menos
 * @return La dirección de memoria del canal que se saca
 * @throw PooFusionExc Si el ordinal está fuera del rango indicado
 */
Canal* PaqueteDeCanales::sacaCanal ( int cual )
{
   Canal* aDevolver = nullptr;

   try
   {
      aDevolver = _canales.sacaElemento ( cual-1 );
   }
   catch ( std::out_of_range &e )
   {
      throw PooFusionExc ( "PaqueteDeCanales::sacaCanal", e.what ()
                         , "PaqueteDeCanales.cpp" );
   }

   return aDevolver;
}


/**
 * Consulta cuántos canales hay en el paquete
 * @return El número de canales en el paquete
 */
int PaqueteDeCanales::getNumCanales ( ) const
{
   return _canales.getNumElementos ();
}


/**
 * Operador de asignación
 * @param otro Paquete del que se copian los datos
 * @post Los datos del paquete cambian a los del paquete que se pasa como
 *       parámetro
 * @return Una referencia al propio objeto, para permitir encadenamiento de
 *         asignaciones
 * @note Este operador NO es responsable de liberar la memoria ocupada por los
 *       canales previamente presentes en el paquete
 */
PaqueteDeCanales& PaqueteDeCanales::operator= ( const PaqueteDeCanales& otro )
{
   if ( this != &otro )
   {
      Producto::operator = ( otro );
      _canales = otro._canales;
      _descuento = otro._descuento;
   }

   return *this;
}


/**
 * Consulta la descripción del paquete de canales
 * @return Una cadena de texto con la información de los canales incluídos
 */
std::string PaqueteDeCanales::getDescripcion ( )
{
   std::stringstream aux;

   aux << "Paquete de canales que contiene ";

   for ( int i = 0; i < _canales.getNumElementos (); i++ )
   {
      aux << std::endl << "\t" << _canales.getElemento (i)->getNombre ();
   }

   return aux.str ();
}


/**
 * Crea una copia del propio paquete de canales
 * @return La dirección de memoria del nuevo paquete de canales
 */
Duplicable* PaqueteDeCanales::copia ( ) const
{
   Duplicable* aDevolver = new PaqueteDeCanales ( *this );

   return aDevolver;
}

