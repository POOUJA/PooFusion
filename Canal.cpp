/**
 * @file Canal.cpp
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:50
 *
 * @brief Implementación de los métodos de la clase Canal
 */

#include "Canal.h"
#include "MiExcepcion.h"

/**
 * Constructor parametrizado
 * @param nNombre Nombre del nuevo canal
 * @param precio Precio del canal
 * @post El nombre del nuevo canal coincidirá con el que se pasa como parámetro
 * @throw MiExcepcion Si hay algún problema
 */
Canal::Canal ( std::string nNombre, float precio ) try : Producto ( precio )
                                                  , _nombre ( nNombre )
{
   if ( nNombre == "" )
   {
      throw MiExcepcion ( "Canal.cpp", "Canal::Canal"
                        , "Un canal tiene que tener nombre" );
   }
}
catch ( MiExcepcion& e )
{
   throw MiExcepcion ( "Canal.cpp", "Canal::Canal", e.quePasa () );
}


/**
 * Constructor de copia
 * @param orig Canal del que se copia la información
 * @post El nuevo canal tiene exactamente los mismos datos que el original
 */
Canal::Canal ( const Canal& orig ): Producto ( orig ), _nombre ( orig._nombre )
{ }


/**
 * Destructor
 */
Canal::~Canal ( )
{ }


/**
 * Cambia el nombre del canal
 * @param nNombre Nuevo nombre para el canal
 * @post El nombre del canal cambia al valor que se le pasa como parámetro
 * @throw MiExcepcion Si se intenta asignar como nombre una cadena vacía
 * @return Una referencia al propio canal, para permitir el encadenamiento de
 *         llamadas a métodos
 */
Canal& Canal::setNombre ( std::string nNombre )
{
   if ( nNombre == "" )
   {
      throw MiExcepcion ( "Canal.cpp", "Canal::setNombre"
                        , "Un canal tiene que tener nombre" );
   }

   this->_nombre = nNombre;

   return *this;
}

/**
 * Consulta el nombre del canal
 * @return El nombre del canal
 */
std::string Canal::getNombre ( ) const
{
   return _nombre;
}


/**
 * Operador de asignación
 * @param otro Canal del que se copia la información
 * @post El canal tiene exactamente la misma información que el que se pasa
 *       como parámetro
 * @return Una referencia al canal actual, para permitir asignaciones
 *         encadenadas (a = b = c)
 */
Canal& Canal::operator= ( const Canal& otro )
{
   if ( this != &otro )
   {
      Producto::operator= ( otro );
      _nombre = otro._nombre;
   }

   return *this;
}


/**
 * Consulta la descripción del canal
 * @return Una descripción en modo texto del canal
 */
std::string Canal::getDescripcion ( )
{
   return ( "Canal " + _nombre );
}


/**
 * Crea una copia del canal
 * @return La dirección de memoria de un nuevo objeto de clase Canal que copia
 *         los atributos del objeto actual
 */
Producto* Canal::copia ( ) const
{
   Producto* aDevolver = new Canal ( *this );

   return aDevolver;
}
