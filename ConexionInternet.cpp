/**
 * @file ConexionInternet.cpp
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:51
 *
 * @brief Implementación de los métodos de la clase ConexionInternet
 */

#include <sstream>
#include "ConexionInternet.h"
#include "MiExcepcion.h"

/**
 * Constructor parametrizado
 * @param nTipo Tipo de la conexión (fibra, ADSL, WiMAX...)
 * @param nVel Velocidad de la conexión
 * @param precio Precio mensual de la conexión
 * @post La información de la nueva conexión coincide con los valores que se le
 *       pasan
 * @throw MiExcepcion Si hay algún problema
 */
ConexionInternet::ConexionInternet ( std::string nTipo, int nVel
                                   , float precio ) try : Producto ( precio )
                                                        , _tipo ( nTipo )
                                                        , _velocidadMB ( nVel )
{
   if ( nVel <= 0 )
   {
      throw MiExcepcion ( "ConexionInternet.cpp"
                        , "ConexionInternet::ConexionInternet"
                        , "La velocidad ha de ser un número positivo" );
   }

   if ( nTipo == "" )
   {
      throw MiExcepcion ( "ConexionInternet.cpp"
                        , "ConexionInternet::ConexionInternet"
                        , "El tipo de conexión no puede ser una cadena vacía" );
   }
}
catch ( MiExcepcion& e )
{
   throw MiExcepcion ( "ConexionInternet.cpp"
                     , "ConexionInternet::ConexionInternet"
                     , e.quePasa () );
}


/**
 * Constructor de copia
 * @param orig Conexión de la que se copia la información
 * @post La nueva conexión tiene exactamente los mismos datos que la original
 */
ConexionInternet::ConexionInternet ( const ConexionInternet& orig ):
                                   Producto ( orig ), _tipo ( orig._tipo )
                                 , _velocidadMB ( orig._velocidadMB )
{ }


/**
 * Destructor
 */
ConexionInternet::~ConexionInternet ( )
{ }


/**
 * Cambia la velocidad de la conexión
 * @param nVel Nueva velocidad
 * @post La velocidad de la conexión cambia al nuevo valor
 * @throw MiExcepcion Si la nueva velocidad no es un número positivo
 * @return Una referencia a la propia conexión, para permitir el encadenamiento
 *         de llamadas a métodos
 */
ConexionInternet& ConexionInternet::setVelocidadMB ( int nVel )
{
   if ( nVel <= 0 )
   {
      throw MiExcepcion ( "ConexionInternet.cpp"
                        , "ConexionInternet::setVelocidadMB"
                        , "La velocidad ha de ser un número positivo" );
   }

   this->_velocidadMB = nVel;

   return *this;
}


/**
 * Consulta la velocidad de la conexión
 * @return La velocidad de la conexión
 */
int ConexionInternet::getVelocidadMB ( ) const
{
   return _velocidadMB;
}


/**
 * Cambia el tipo de la conexión
 * @param nTipo Tipo de la conexión (fibra, ADSL, WiMAX...)
 * @post El tipo de la conexión cambia al nuevo valor
 * @throw MiExcepcion Si el tipo es una cadena vacía
 * @return Una referencia a la propia conexión, para permitir el encadenamiento
 *         de llamadas a métodos
 */
ConexionInternet& ConexionInternet::setTipo ( std::string nTipo )
{
   if ( nTipo == "" )
   {
      throw MiExcepcion ( "ConexionInternet.cpp"
                        , "ConexionInternet::setTipo"
                        , "El tipo de conexión no puede ser una cadena vacía" );
   }

   this->_tipo = nTipo;

   return *this;
}


/**
 * Consulta el tipo de la conexión
 * @return El tipo de la conexión
 */
std::string ConexionInternet::getTipo ( ) const
{
   return _tipo;
}


/**
 * Operador de asignación
 * @param otro Conexión de la que se copia la información
 * @post La conexión tiene exactamente la misma información que la que se pasa
 *       como parámetro
 * @return Una referencia a la conexión actual, para permitir asignaciones
 *         encadenadas (a = b = c)
 */
ConexionInternet& ConexionInternet::operator= ( const ConexionInternet& otro )
{
   if ( this != &otro )
   {
      Producto::operator = ( otro );
      _tipo = otro._tipo;
      _velocidadMB = otro._velocidadMB;
   }

   return *this;
}


/**
 * Operador de comparación "menor que"
 * @param otro Conexión con la que se compara
 * @retval true Si la conexión actual tiene menos velocidad que la que se pasa
 *              como parámetro
 * @retval false Si la conexión actual tiene igual o más velocidad que la que
 *               se pasa como parámetro
 */
bool ConexionInternet::operator< ( const ConexionInternet& otro )
{
   return ( _velocidadMB < otro._velocidadMB );
}


/**
 * Operador de comparación "igual que"
 * @param otro Conexión con la que se compara
 * @retval true Si la conexión actual tiene la misma velocidad que la que se
 *              pasa como parámetro
 * @retval false Si la conexión actual tiene distinta velocidad que la que se
 *               pasa como parámetro
 */
bool ConexionInternet::operator== ( const ConexionInternet& otro )
{
   return ( _velocidadMB == otro._velocidadMB );
}


/**
 * Consulta la descripción de la conexión
 * @return Una cadena de texto describiendo la conexión a Internet
 */
std::string ConexionInternet::getDescripcion ( )
{
   std::stringstream aux;

   aux << "Conexión a Internet de tipo " << _tipo << " a " << _velocidadMB
       << " MB por segundo";

   return aux.str ();
}


/**
 * Crea una copia de la conexión
 * @return La dirección de memoria de un nuevo objeto que copia los atributos
 *         del objeto actual
 */
Producto* ConexionInternet::copia ( ) const
{
   Producto* aDevolver = new ConexionInternet ( *this );

   return aDevolver;
}
