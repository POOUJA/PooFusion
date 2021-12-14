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
 * @param nDesc Descuento a aplicar
 * @post El nuevo paquete tiene el descuento pasado como parámetro
 * @throw PooFusionExc Si el descuento es negativo
 */
PaqueteDeCanales::PaqueteDeCanales ( float nDesc ): _descuento ( nDesc )
{
   if ( nDesc < 0 )
   {
      throw PooFusionExc ( "PaqueteDeCanales.cpp"
                        , "PaqueteDeCanales::PaqueteDeCanales"
                        , "El descuento no puede ser negativo" );
   }

   for ( int i = 0; i < MAX_CANALES; i++ )
   {
      _canales[i] = nullptr;
   }
}


/**
 * Constructor de copia
 * @param orig Paquete del que se copia la información
 * @post El nuevo paquete tiene una copia exacta de los valores del original
 */
PaqueteDeCanales::PaqueteDeCanales ( const PaqueteDeCanales& orig ):
                                                _descuento ( orig._descuento )
                                                , _nCanales ( orig._nCanales )
{
   for ( int i = 0; i < MAX_CANALES; i++ )
   {
      _canales[i] = orig._canales[i];
   }
}


/**
 * Destructor
 * @note Solamente rompe la vinculación entre el paquete y los canales. NO es
 *       responsable de eliminar los canales
 */
PaqueteDeCanales::~PaqueteDeCanales ( )
{
   for ( int i = 0; i < _nCanales; i++ )
   {
      _canales[i] = nullptr;
   }
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
 * Añade un nuevo canal al paquete
 * @param nuevoC Canal a añadir
 * @pre El canal nuevo no está ya incluido en el paquete
 * @post El paquete de canales contiene un canal más
 * @throw PooFusionExc Si no caben más canales en el paquete
 */
void PaqueteDeCanales::addCanal ( Canal* nuevoC )
{
   if ( _nCanales == MAX_CANALES )
   {
      throw PooFusionExc ( "PaqueteDeCanales.cpp", "PaqueteDeCanales::addCanal",
                          "No caben más canales en el paquete" );
   }

   _canales[_nCanales] = nuevoC;
   _nCanales++;
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
   if ( ( cual < 1 ) || ( cual > _nCanales ) )
   {
      throw PooFusionExc ( "PaqueteDeCanales.cpp", "PaqueteDeCanales::getCanal",
                          "Valor de índice incorrecto" );
   }

   return _canales[cual-1];
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
   if ( ( cual < 1 ) || ( cual > _nCanales ) )
   {
      throw PooFusionExc ( "PaqueteDeCanales.cpp", "PaqueteDeCanales::sacaCanal",
                          "Valor de índice incorrecto" );
   }

   Canal* aux = _canales[cual-1];

   // Compactación del vector de punteros
   for ( int i = cual-1; i < _nCanales-1; i++ )
   {
      _canales[i] = _canales[i+1];
   }

   _nCanales--;

   return aux;
}


/**
 * Consulta cuántos canales hay en el paquete
 * @return El número de canales en el paquete
 */
int PaqueteDeCanales::getNumCanales ( ) const
{
   return _nCanales;
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
      for ( int i = 0; i < MAX_CANALES; i++ )
      {
         _canales[i] = otro._canales[i];
      }
      _nCanales = otro._nCanales;
      _descuento = otro._descuento;
   }

   return *this;
}
/**
 * Obtiene el precio del paquete de canales
 *
 * @post Calcula el precio del paquete como la suma del precio de los canales asignados menos el descuento aplicado
 * @return El precio final del paquete
 */
float PaqueteDeCanales::getPrecioMensual() {
    float precioTotal=0;
    for (int i = 0; i < _nCanales; ++i) {
        precioTotal+=_canales[i]->getPrecioMensual();
    }
    return precioTotal*(1-_descuento/100);
}
