/**
 * @file Contrato.cpp
 * @author algarcia
 *
 * @date 3 de abril de 2021, 12:14
 *
 * @brief Implementación de los métodos de la clase Contrato
 */

#include <ctime>

#include "Contrato.h"
#include "PooFusionExc.h"

/**
 * Constructor parametrizado
 * @param nAbonado Persona a nombre de quien se hace el contrato
 * @post El nuevo contrato no tiene servicios aún, aunque sí está activo
 * @throw PooFusionExc Si se le pasa como parámetro nullptr
 */
Contrato::Contrato ( Persona* nAbonado ): _abonado ( nAbonado )
                                        , _productos ( MAX_PRODUCTOS, nullptr )
{
   if ( nAbonado == nullptr )
   {
      throw PooFusionExc ( "Contrato::Contrato"
                         , "El contrato ha de tener un abonado"
                         , "Contrato.cpp" );
   }

   // Toma la fecha actual para el contrato
   time_t ahora = std::time ( nullptr );

   struct tm* ahora2 = localtime ( &ahora );

   _fechaDeAlta = ( ahora2->tm_year + 1900 ) * 10000;
   _fechaDeAlta += ( ahora2->tm_mon + 1 ) * 100;
   _fechaDeAlta += ahora2->tm_mday;
}


/**
 * Constructor de copia
 * @param orig Contrato del que se copian los valores
 * @post El nuevo contrato tiene copias de los productos del original
 */
Contrato::Contrato ( Contrato& orig ): _fechaDeAlta ( orig._fechaDeAlta )
                                  , _mesesPermanencia ( orig._mesesPermanencia )
                                  , _cuentaBancaria ( orig._cuentaBancaria )
                                  , _activo ( orig._activo )
                                  , _abonado ( orig._abonado )
                                  , _productos ( MAX_PRODUCTOS, nullptr )
{
   // Hay que crear productos nuevos para el contrato copiado
   for ( int i = 0; i < orig._productos.getNumElementos (); i++ )
   {
      _productos.addElemento ( (Producto*)  orig._productos.getElemento (i)->copia ()  );
   }
}


/**
 * Destructor
 * @note Desvincula al abonado, pero NO lo destruye. Es una responsabilidad
 *       externa a esta clase
 */
Contrato::~Contrato ( )
{
   _abonado = nullptr;
   int nProd = _productos.getNumElementos ();

   for ( int i = 0; i < nProd; i++ )
   {
      Producto* aux = _productos.sacaElemento ( 0 );
      delete aux;
   }
}


/**
 * Cambia la fecha de alta del contrato
 * @param fechaDeAlta Nueva fecha de alta (formato YYYYMMDD)
 * @post La fecha de alta del contrato cambia al valor pasado como parámetro
 * @return Una referencia al propio contrato
 */
Contrato& Contrato::setFechaDeAlta ( int fechaDeAlta )
{
   this->_fechaDeAlta = fechaDeAlta;

   return *this;
}


/**
 * Consulta de la fecha de alta del contrato
 * @return La fecha de alta del contrato en formato YYYYMMDD
 */
int Contrato::getFechaDeAlta ( ) const
{
   return _fechaDeAlta;
}



/**
 * Añade una nueva conexión a Internet al contrato
 * @param nCI Nueva conexión a Internet. Se crea una copia de este objeto dentro del contrato
 * @post El contrato incluye un producto más
 * @throw PooFusionExc Si hay algún error
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const ConexionInternet& nCI )
{
    try
    {
        ConexionInternet* nuevaConexionInternet = new ConexionInternet(nCI);

        _conexionInternet = true;
        _productos.addElemento ( nuevaConexionInternet );
    }
    catch ( std::length_error& e )
    {
        // Añade a la información de la primera excepción los datos de este método
        throw PooFusionExc ( "Contrato::addProducto", e.what (), "Contrato.cpp" );
    }

    return *this;
}
/**
 * Añade un nuevo canal al contrato
 * @param nC Nuevo canal. Se crea una copia de este objeto dentro del contrato
 * @post El contrato incluye un producto más
 * @throw PooFusionExc Si hay algún error
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const Canal& nC )
{
    try
    {
        Producto* nuevoProducto = new Canal(nC);

        if ( _conexionInternet == false)
        {
            throw PooFusionExc ( "Contrato::addProducto"
                    , "¡No hay una conexión a Internet!"
                    , "Contrato.cpp" );
        }
        _productos.addElemento ( nuevoProducto );
    }
    catch ( std::length_error& e )
    {
        // Añade a la información de la primera excepción los datos de este método
        throw PooFusionExc ( "Contrato::addProducto", e.what (), "Contrato.cpp" );
    }

    return *this;
}
/**
 * Añade un nuevo paquete de canales al contrato
 * @param nPC Nuevo paquete de canales. Se crea una copia de este objeto dentro del contrato
 * @post El contrato incluye un producto más
 * @throw PooFusionExc Si hay algún error
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const PaqueteDeCanales& nPC )
{
    try
    {
        PaqueteDeCanales* nuevoPaqueteCanales = new PaqueteDeCanales(nPC);

        if ( _conexionInternet == false)
        {
            throw PooFusionExc ( "Contrato::addProducto"
                    , "¡No hay una conexión a Internet!"
                    , "Contrato.cpp" );
        }
        _productos.addElemento ( nuevoPaqueteCanales );
    }
    catch ( std::length_error& e )
    {
        // Añade a la información de la primera excepción los datos de este método
        throw PooFusionExc ( "Contrato::addProducto", e.what (), "Contrato.cpp" );
    }

    return *this;
}

/**
 * Añade un nuevo producto genérico al contrato
 * @param nP Nuevo producto. Se crea una copia de este objeto dentro del contrato
 * @post El contrato incluye un producto más
 * @throw PooFusionExc Si hay algún error
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const Producto& nP )
{
    try
    {
        Producto* nuevoProducto = (Producto* )nP.copia();

        if ( _conexionInternet == false)
        {
            throw PooFusionExc ( "Contrato::addProducto"
                    , "¡No hay una conexión a Internet!"
                    , "Contrato.cpp" );
        }
        _productos.addElemento ( nuevoProducto );
    }
    catch ( std::length_error& e )
    {
        // Añade a la información de la primera excepción los datos de este método
        throw PooFusionExc ( "Contrato::addProducto", e.what (), "Contrato.cpp" );
    }

   return *this;
}


/**
 * Consulta el número de productos del contrato
 * @return El número de productos del contrato
 */
int Contrato::getNumProductos ( )
{
   return _productos.getNumElementos ();
}


/**
 * Consulta un producto del contrato
 * @param cual Ordinal del producto que se quiere consultar. El rango de valores
 *        válidos es [1..número de productos contratados]
 * @return El producto consultado
 * @throw PooFusionExc Si hay algún problema
 */
Producto& Contrato::getProducto ( int cual )
{
   try
   {
      return *_productos.getElemento ( cual-1 );
   }
   catch ( std::out_of_range& e )
   {
      throw PooFusionExc ( "Contrato::getProducto", e.what (), "Contrato.cpp" );
   }
}


/**
 * Asigna un nuevo abonado al contrato
 * @param abonado Nuevo abonado
 * @post El contrato cambia de abonado
 * @return Una referencia al propio contrato
 * @throw PooFusionExc Si el parámetro es nullptr
 * @note El abonado anterior NO se destruye. Es una responsabilidad externa a
 *       esta clase
 */
Contrato& Contrato::setAbonado ( Persona* abonado )
{
   if ( abonado == nullptr )
   {
      throw PooFusionExc ( "Contrato::setAbonado"
                         , "El contrato tiene que tener un abonado"
                         , "Contrato.cpp" );
   }

   this->_abonado = abonado;

   return *this;
}


/**
 * Consulta el abonado asociado al contrato
 * @return Un puntero al abonado, o nullptr si no hay abonado asignado
 */
Persona* Contrato::getAbonado ( ) const
{
   return _abonado;
}


/**
 * Cambia el estado del contrato (activo/inactivo)
 * @param activo Nuevo estado del contrato
 * @post El contrato cambia de estado según el parámetro que se le pasa
 * @return Una referencia al propio contrato
 * @throw PooFusionExc Si se intenta activar un contrato al que le faltan datos
 */
Contrato& Contrato::setActivo ( bool activo )
{
   if ( activo )
   {
      if ( !_abonado )
      {
         throw PooFusionExc ( "Contrato::setActivo"
                            , "El contrato no tiene un abonado asociado"
                            , "Contrato.cpp" );
      }

      if ( _cuentaBancaria == "" )
      {
         throw PooFusionExc ( "Contrato::setActivo"
                            , "El contrato no tiene una cuenta de domiciliación"
                            , "Contrato.cpp" );
      }
   }

   this->_activo = activo;

   return *this;
}


/**
 * Consulta si el contrato está activo
 * @retval true Si el contrato está activo
 * @retval false Si el contrato no está activo
 */
bool Contrato::estaActivo ( ) const
{
   return _activo;
}


/**
 * Cambia la cuenta bancaria asociada al contrato
 * @param cuentaBancaria Nueva cuenta bancaria (formato IBAN)
 * @post El contrato tiene una nueva cuenta de domiciliación
 * @return Una referencia al propio contrato
 * @throw PooFusionExc Si se le pasa como parámetro una cadena vacía
 */
Contrato& Contrato::setCuentaBancaria ( std::string cuentaBancaria )
{
   if ( cuentaBancaria == "" )
   {
      throw PooFusionExc ( "Contrato::setCuentaBancaria"
                         , "El contrato tiene que tener cuenta bancaria"
                         , "Contrato.cpp" );
   }

   this->_cuentaBancaria = cuentaBancaria;

   return *this;
}


/**
 * Consulta la cuenta bancaria asociada al contrato
 * @return La cuenta bancaria asociada al contrato (formato IBAN)
 */
std::string Contrato::getCuentaBancaria ( ) const
{
   return _cuentaBancaria;
}


/**
 * Cambia los meses de permanencia del contrato
 * @param mesesPermanencia Número de meses
 * @post La permanencia del contrato cambia según el parámetro
 * @return Una referencia al propio contrato
 * @throw PooFusionExc Si el número de meses es negativo
 */
Contrato& Contrato::setMesesPermanencia ( int mesesPermanencia )
{
   if ( mesesPermanencia < 0 )
   {
      throw PooFusionExc ( "Contrato::setMesesPermanencia"
                         , "El contrato no puede tener una permanencia negativa"
                         , "Contrato.cpp" );
   }

   this->_mesesPermanencia = mesesPermanencia;

   return *this;
}


/**
 * Consulta los meses de permanencia del contrato
 * @return Los meses de permanencia del contrato
 */
int Contrato::getMesesPermanencia ( ) const
{
   return _mesesPermanencia;
}


/**
 * Consulta la cuota mensual del contrato
 * @return La cuota mensual del contrato, calculada sumando los precios de los
 *         productos contratados
 */
float Contrato::getPrecioMensual ( )
{
   float aDevolver = 0;

   for ( int i = 0; i < _productos.getNumElementos (); i++ )
   {
      aDevolver += _productos.getElemento ( i )->getPrecioMensual ();
   }

   return aDevolver;
}

