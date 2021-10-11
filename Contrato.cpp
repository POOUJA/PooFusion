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
#include "MiExcepcion.h"
#include "ConexionInternet.h"
#include "PaqueteDeCanales.h"

/**
 * Constructor parametrizado
 * @param nAbonado Persona a nombre de quien se hace el contrato
 * @post El nuevo contrato no tiene servicios aún, aunque sí está activo
 * @throw MiExcepcion Si se le pasa como parámetro nullptr
 */
Contrato::Contrato ( Persona* nAbonado ): _abonado ( nAbonado )
{
   if ( nAbonado == nullptr )
   {
      throw MiExcepcion ( "Contrato.cpp", "Contrato::Contrato"
                        , "El contrato ha de tener un abonado" );
   }

   // Toma la fecha actual para el contrato
   time_t ahora = std::time ( nullptr );

   struct tm* ahora2 = localtime ( &ahora );

   _fechaDeAlta = ( ahora2->tm_year + 1900 ) * 10000;
   _fechaDeAlta += ( ahora2->tm_mon + 1 ) * 100;
   _fechaDeAlta += ahora2->tm_mday;
    _canales = new PaqueteDeCanales (0 );
}


/**
 * Constructor de copia
 * @param orig Contrato del que se copian los valores
 * @post El nuevo contrato es igual al original. Se duplica la conexión y el
 *       paquete de canales
 */
Contrato::Contrato ( const Contrato& orig ): _fechaDeAlta ( orig._fechaDeAlta )
                                  , _mesesPermanencia ( orig._mesesPermanencia )
                                  , _cuentaBancaria ( orig._cuentaBancaria )
                                  , _activo ( orig._activo )
                                  , _abonado ( orig._abonado )
{
   _conexion = new ConexionInternet ( *orig._conexion );
    _canales = new PaqueteDeCanales (*orig._canales );
}


/**
 * Destructor
 * @note Desvincula al abonado, pero NO lo destruye. Es una responsabilidad
 *       externa a esta clase
 */
Contrato::~Contrato ( )
{
   _abonado = nullptr;
   delete _conexion;
   _conexion = nullptr;
   delete _canales;
    _canales = nullptr;
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
 * Añade un canal de TV al paquete contratado por el abonado. El descuento
 * del paquete empieza siendo un 10%, y con cada nuevo canal se incrementa un
 * 2% más
 * @param c Canal de TV que se añade
 * @post El contrato incluye un canal más
 * @throw MiExcepcion Si el contrato no permite más canales
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addCanal ( Canal* c )
{

   try
   {
      _canales->addCanal (c );
      // Con cada nuevo canal, se aumenta el descuento
      _canales->setDescuento (_canales->getDescuento () + 2 );
   }
   catch ( MiExcepcion& e )
   {
      // Añade a la información de la primera excepción los datos de este método
      throw MiExcepcion ( "Contrato.cpp", "Contrato::addCanalTV",
                          e.quePasa () );
   }

   return *this;
}


/**
 * Consulta el paquete de canales contratado
 * @return Un puntero al paquete de canales contratado. Si no hay paquete de
 *         canales, devuelve nullptr.
 */
PaqueteDeCanales* Contrato::getPaqueteTV ( ) const
{
   return _canales;
}


/**
 * Añade una conexión a Internet al contrato
 * @param tipo Tipo de la nueva conexión (ADSL, Fibra, WiMAX...)
 * @param velocidad Velocidad de la conexión en MB
 * @post El contrato tiene una conexión a Internet vinculada
 * @note Si no había una conexión previa, la crea. Si ya existía, la destruye
 * @return Una referencia al propio objeto, para permitir encadenar llamadas a
 *         métodos
 * @throw MiExcepcion Si hay algún problema
 */
Contrato& Contrato::addConexion ( std::string tipo, int velocidad, float precio )
{
   if ( _conexion != nullptr )
   {
      delete _conexion;
   }

   try
   {
      _conexion = new ConexionInternet ( tipo, velocidad, precio );
   }
   catch ( MiExcepcion& e )
   {
      // Añade a la información de la primera excepción los datos de este método
      throw MiExcepcion ( "Contrato.cpp", "Contrato::addConexion",
                          e.quePasa () );
   }

   return *this;
}


/**
 * Consulta la conexión a Internet asociada al contrato
 * @return Un puntero a la conexión, o nullptr si no hay conexión vinculada
 */
ConexionInternet* Contrato::getConexion ( ) const
{
   return _conexion;
}


/**
 * Asigna un nuevo abonado al contrato
 * @param abonado Nuevo abonado
 * @post El contrato cambia de abonado
 * @return Una referencia al propio contrato
 * @throw MiExcepcion Si el parámetro es nullptr
 * @note El abonado anterior NO se destruye. Es una responsabilidad externa a
 *       esta clase
 */
Contrato& Contrato::setAbonado ( Persona* abonado )
{
   if ( abonado == nullptr )
   {
      throw MiExcepcion ( "Contrato.cpp", "Contrato::setAbonado"
                        , "El contrato tiene que tener un abonado" );
   }

   this->_abonado = abonado;

   return *this;
}


/**
 * Consulta el abonado asociado al contrato
 * @return Un puntero al abonado
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
 */
Contrato& Contrato::setActivo ( bool activo )
{
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
 * @throw MiExcepcion Si se le pasa como parámetro una cadena vacía
 */
Contrato& Contrato::setCuentaBancaria ( std::string cuentaBancaria )
{
   if ( cuentaBancaria == "" )
   {
      throw MiExcepcion ( "Contrato.cpp", "Contrato::setCuentaBancaria"
                        , "El contrato tiene que tener cuenta bancaria" );
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
 * @throw MiExcepcion Si el número de meses es negativo
 */
Contrato& Contrato::setMesesPermanencia ( int mesesPermanencia )
{
   if ( mesesPermanencia < 0 )
   {
      throw MiExcepcion ( "Contrato.cpp", "Contrato::setMesesPermanencia"
                        , "El contrato no puede tener una permanencia negativa" );
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


