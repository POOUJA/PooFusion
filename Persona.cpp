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
      throw PooFusionExc ( "Persona.cpp", "Persona::Persona"
                        , "El nombre no puede estar vacío" );
   }

   if ( nNIF == "" )
   {
      throw PooFusionExc ( "Persona.cpp", "Persona::Persona"
                        , "El NIF no puede estar vacío" );
   }
}


/**
 * Constructor de copia
 * @param orig Persona de la que se copia la información
 * @post La nueva persona tiene exactamente los mismos datos que la original
 */
Persona::Persona ( const Persona& orig ): _apeNom ( orig._apeNom )
                                        , _nif ( orig._nif )
                                        , _miCanal ( orig._miCanal )
                                        , _miConexion ( orig._miConexion )
{ }


/**
 * Destructor
 * @post Se rompe la relación de la persona con el canal y la conexión que tenga
 *       contratadas
 * @note La conexión y el canal NO se destruyen
 */
Persona::~Persona ( )
{
   _miCanal = nullptr;
   _miConexion = nullptr;
}


/**
 * Cambia el NIF de la persona
 * @param nNif Nuevo valor de NIF
 * @post El NIF de la persona cambia al nuevo valor
 * @throw PooFusionExc Si el nuevo NIF es una cadena vacía
 */
void Persona::setNif ( std::string nNif )
{
   if ( nNif == "" )
   {
      throw PooFusionExc ( "Persona.cpp", "Persona::setNif"
                        , "El NIF no puede estar vacío" );
   }

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
 * @post La persona cambia sus apellidos y nombre al valor que se pasa como
 *       parámetro
 * @throw PooFusionExc Si la cadena con el nuevo nombre está vacía
 */
void Persona::setApeNom ( std::string nApeNom )
{
   if ( nApeNom == "" )
   {
      throw PooFusionExc ( "Persona.cpp", "Persona::setApeNom"
                        , "El nombre no puede estar vacío" );
   }

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
 * Cambia la conexión contratada por la persona
 * @param nuevaC Dirección de memoria de la nueva conexión a vincular
 * @post La conexión a Internet vinculada a la persona cambia al valor del
 *       parámetro
 * @return La dirección de memoria de la conexión anteriormente vinculada a la
 *         persona. Si no había una conexión previa, devuelve nullptr
 */
ConexionInternet* Persona::setMiConexion ( ConexionInternet* nuevaC )
{
   ConexionInternet* aux = _miConexion;
   this->_miConexion = nuevaC;

   return aux;
}


/**
 * Consulta la conexión a Internet contratada por la persona
 * @return La dirección de memoria de la conexión contratada. Si no hay una
 *         conexión contratada, devuelve nullptr
 */
ConexionInternet* Persona::getMiConexion ( ) const
{
   return _miConexion;
}


/**
 * Cambia el canal contratado por la persona
 * @param nuevoC Dirección de memoria del nuevo canal a vincular
 * @post El canal vinculado a la persona cambia al valor del parámetro
 * @return La dirección de memoria del canal anteriormente vinculado a la
 *         persona. Si no había un canal previo, devuelve nullptr
 */
Canal* Persona::setMiCanal ( Canal* nuevoC )
{
   Canal* aux = _miCanal;
   this->_miCanal = nuevoC;

   return aux;
}


/**
 * Consulta el canal de TV contratado por la persona
 * @return La dirección de memoria del canal contratado. Si no hay un canal
 *         contratado, devuelve nullptr
 */
Canal* Persona::getMiCanal ( ) const
{
   return _miCanal;
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
      _miCanal = otro._miCanal;
      _miConexion = otro._miConexion;
   }

   return *this;
}
