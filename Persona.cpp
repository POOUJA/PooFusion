/**
 * @file Persona.cpp
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:46
 *
 * @brief Implementación de los métodos de la clase Persona
 */

#include "Persona.h"

/**
 * Constructor parametrizado
 * @param nApeNom Apellidos y nombre de la persona
 * @param nNIF NIF de la persona
 * @pre Los parámetros han de tener valores válidos
 * @post Los datos de la nueva persona son iguales a los que se pasan como
 *       parámetros
 */
Persona::Persona ( std::string nApeNom, std::string nNIF ): _apeNom ( nApeNom )
                                                          , _nif ( nNIF )
{ }


/**
 * Constructor de copia
 * @param orig Persona de la que se copia la información
 * @post La nueva persona tiene exactamente los mismos datos que la original
 */
Persona::Persona ( const Persona& orig ): _apeNom ( orig._apeNom )
                                        , _nif ( orig._nif )
{ }


/**
 * Destructor
 */
Persona::~Persona ( )
{ }


/**
 * Cambia el NIF de la persona
 * @param nNif Nuevo valor de NIF
 * @pre El valor de NIF ha de ser válido
 * @post El NIF de la persona cambia al nuevo valor
 */
void Persona::setNif ( std::string nNif )
{
   this->_nif = nNif;
}


/**
 * Consulta el NIF de la persona
 * @return El NIF de la persona
 */
std::string Persona::getNif ( ) const
{
   return _nif;
}


/**
 * Cambia el nombre y los apellidos de la persona
 * @param nApeNom Apellidos y nombre de la persona
 * @pre El valor que se pasa como parámetro ha de ser válido
 * @post La persona cambia sus apellidos y nombre al valor que se pasa como
 *       parámetro
 */
void Persona::setApeNom ( std::string nApeNom )
{
   this->_apeNom = nApeNom;
}


/**
 * Consulta el nombre y apellidos de la persona
 * @return El nombre y apellidos de la persona
 */
std::string Persona::getApeNom ( ) const
{
   return _apeNom;
}


/**
 * Operador de asignación
 * @param otro Persona de la que se copia la información
 * @post La persona tiene exactamente la misma información que la que se pasa
 *       como parámetro
 * @return Una referencia a la persona actual, para permitir asignaciones
 *         encadenadas (a = b = c)
 */
Persona& Persona::operator= ( const Persona& otro )
{
   if ( this != &otro )
   {
      _apeNom = otro._apeNom;
      _nif = otro._nif;
   }

   return *this;
}
