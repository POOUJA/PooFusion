/**
 * @file Canal.cpp
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:50
 *
 * @brief Implementación de los métodos de la clase Canal
 */

#include "Canal.h"

/**
 * Constructor parametrizado
 * @param nNombre Nombre del nuevo canal
 * @pre El nombre del canal debe ser un valor válido
 * @post El nombre del nuevo canal coincidirá con el que se pasa como parámetro
 */
Canal::Canal ( std::string nNombre ): _nombre ( nNombre )
{ }


/**
 * Constructor de copia
 * @param orig Canal del que se copia la información
 * @post El nuevo canal tiene exactamente los mismos datos que el original
 */
Canal::Canal ( const Canal& orig ): _nombre ( orig._nombre )
{ }


/**
 * Destructor
 */
Canal::~Canal ( )
{ }


/**
 * Cambia el nombre del canal
 * @param nNombre Nuevo nombre para el canal
 * @pre El nombre del canal debe ser un valor válido
 * @post El nombre del canal cambia al valor que se le pasa como parámetro
 */
void Canal::setNombre ( std::string nNombre )
{
   this->_nombre = nNombre;
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
      _nombre = otro._nombre;
   }

   return *this;
}
