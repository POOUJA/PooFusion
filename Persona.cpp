/**
 * @file Persona.cpp
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:46
 *
 * @brief Implementación de los métodos de la clase Persona
 */

#include "Persona.h"
#include "PooFusionExc.h"

/**
 * Constructor parametrizado
 * @param nApeNom Apellidos y nombre de la persona
 * @param nNIF NIF de la persona
 * @post Los datos de la nueva persona son iguales a los que se pasan como
 *       parámetros
 * @throw PooFusionExc Si alguna de las dos cadenas está vacía
 */
Persona::Persona ( std::string nApeNom, std::string nNIF ): _apeNom ( nApeNom )
                                                          , _nif ( nNIF )
{
   if ( nApeNom == "" )
   {
      throw PooFusionExc ( "Persona::Persona", "El nombre no puede estar vacío"
                         , "Persona.cpp" );
   }

   if ( nNIF == "" )
   {
      throw PooFusionExc ( "Persona::Persona", "El NIF no puede estar vacío"
                         , "Persona.cpp" );
   }
}


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
 * @post El NIF de la persona cambia al nuevo valor
 * @throw PooFusionExc Si el nuevo NIF es una cadena vacía
 */
Persona& Persona::setNif ( std::string nNif )
{
   if ( nNif == "" )
   {
      throw PooFusionExc ( "Persona::setNif", "El NIF no puede estar vacío"
                         , "Persona.cpp" );
   }

   this->_nif = nNif;

   return *this;
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
 * @post La persona cambia sus apellidos y nombre al valor que se pasa como
 *       parámetro
 * @throw PooFusionExc Si la cadena con el nuevo nombre está vacía
 */
Persona& Persona::setApeNom ( std::string nApeNom )
{
   if ( nApeNom == "" )
   {
      throw PooFusionExc ( "Persona::setApeNom", "El nombre no puede estar vacío"
                         , "Persona.cpp" );
   }

   this->_apeNom = nApeNom;

   return *this;
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
