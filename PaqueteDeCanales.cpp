/**
 * @file PaqueteDeCanales.cpp
 * @author algarcia
 *
 * @date 3 de abril de 2021, 9:38
 *
 * @brief Implementación de los métodos de la clase PaqueteDeCanales
 */

#include "PaqueteDeCanales.h"
#include "PooFusionExc.h"

/**
 * Constructor parametrizado
 * @param nC1 Primer canal del paquete
 * @param nC2 Segundo canal del paquete
 * @param nDesc Descuento a aplicar
 * @post El nuevo paquete tiene los valores pasados como parámetros
 * @throw PooFusionExc Si el descuento es negativo
 */
PaqueteDeCanales::PaqueteDeCanales ( Canal* nC1, Canal* nC2, float nDesc ):
                                   _c1 ( nC1 ), _c2 ( nC2 ), _descuento ( nDesc )
{
   if ( nDesc < 0 )
   {
      throw PooFusionExc ( "PaqueteDeCanales.cpp"
                        , "PaqueteDeCanales::PaqueteDeCanales"
                        , "El descuento no puede ser negativo" );
   }
}


/**
 * Constructor de copia
 * @param orig Paquete del que se copia la información
 * @post El nuevo paquete tiene una copia exacta de los valores del original
 */
PaqueteDeCanales::PaqueteDeCanales ( const PaqueteDeCanales& orig ):
                                   _c1 ( orig._c1 ), _c2 ( orig._c2 )
                                 , _descuento ( orig._descuento )
{ }


/**
 * Destructor
 * @note Solamente rompe la vinculación entre el paquete y los canales. NO es
 *       responsable de eliminar los canales
 */
PaqueteDeCanales::~PaqueteDeCanales ( )
{
   _c1 = nullptr;
   _c2 = nullptr;
}


/**
 * Cambia el descuento del paquete de canales
 * @param descuento Nuevo valor de descuento a aplicar
 * @post El descuento del paquete cambia al valor pasado como parámetro
 * @throw PooFusionExc Si el nuevo descuento es un número negativo
 */
void PaqueteDeCanales::setDescuento ( float nDesc )
{
   if ( nDesc < 0 )
   {
      throw PooFusionExc ( "PaqueteDeCanales.cpp", "PaqueteDeCanales::setDescuento"
                        , "El descuento no puede ser negativo" );
   }

   this->_descuento = nDesc;
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
 * Cambia el segundo canal del paquete
 * @param nC2 Dirección de memoria del nuevo canal
 * @post El segundo canal del paquete cambia al valor del parámetro
 * @return La dirección de memoria del antiguo canal, o nullptr, si no estaba
 *         fijado
 */
Canal* PaqueteDeCanales::setC2 ( Canal* nC2 )
{
   Canal* aux = _c2;
   this->_c2 = nC2;

   return aux;
}


/**
 * Consulta el segundo canal del paquete
 * @return La dirección de memoria del segundo canal del paquete, o nullptr si
 *         no está fijado
 */
Canal* PaqueteDeCanales::getC2 ( ) const
{
   return _c2;
}


/**
 * Cambia el primer canal del paquete
 * @param nC1 Dirección de memoria del nuevo canal
 * @post El primer canal del paquete cambia al valor del parámetro
 * @return La dirección de memoria del antiguo canal, o nullptr si no estaba
 *         asignado
 */
Canal* PaqueteDeCanales::setC1 ( Canal* nC1 )
{
   Canal* aux = _c1;
   this->_c1 = nC1;

   return aux;
}


/**
 * Consulta el primer canal del paquete
 * @return La dirección de memoria del primer canal del paquete, o nullptr si
 *         no estuviera asignado
 */
Canal* PaqueteDeCanales::getC1 ( ) const
{
   return _c1;
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
      _c1 = otro._c1;
      _c2 = otro._c2;
      _descuento = otro._descuento;
   }

   return *this;
}
