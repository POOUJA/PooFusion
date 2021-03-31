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
