/**
 * @file ConexionInternet.cpp
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:51
 *
 * @brief Implementación de los métodos de la clase ConexionInternet
 */

#include "ConexionInternet.h"
#include "MiExcepcion.h"

/**
 * Constructor parametrizado
 * @param nTipo Tipo de la conexión (fibra, ADSL, WiMAX...)
 * @param nVel Velocidad de la conexión
 * @post La información de la nueva conexión coincide con los valores que se le
 *       pasan
 * @throw MiExcepcion Si la velocidad es un número menor o igual a cero, o si el
 *        tipo es una cadena vacía
 */
ConexionInternet::ConexionInternet ( std::string nTipo, int nVel) :    _tipo ( nTipo )
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


/**
 * Constructor de copia
 * @param orig Conexión de la que se copia la información
 * @post La nueva conexión tiene exactamente los mismos datos que la original
 */
ConexionInternet::ConexionInternet ( const ConexionInternet& orig ):
                                 _tipo ( orig._tipo )
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
 */
void ConexionInternet::setVelocidadMB ( int nVel )
{
   if ( nVel <= 0 )
   {
      throw MiExcepcion ( "ConexionInternet.cpp"
                        , "ConexionInternet::setVelocidadMB"
                        , "La velocidad ha de ser un número positivo" );
   }

   this->_velocidadMB = nVel;
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
 */
void ConexionInternet::setTipo ( std::string nTipo )
{
   if ( nTipo == "" )
   {
      throw MiExcepcion ( "ConexionInternet.cpp"
                        , "ConexionInternet::setTipo"
                        , "El tipo de conexión no puede ser una cadena vacía" );
   }

   this->_tipo = nTipo;
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
      this->Producto::operator = ( otro );
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

