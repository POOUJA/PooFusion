/**
 * @file PooFusionExc.cpp
 * @author algarcia
 *
 * @date 31 de marzo de 2021, 18:08
 *
 * @brief Implementación de los métodos de la clase PooFusionExc
 */

#include "PooFusionExc.h"

/**
 * Constructor parametrizado
 * @param nFich Nombre del archivo desde donde se lanza la excepción
 * @param nFun Nombre de la función/método que lanza la excepción
 * @param msg Descripción del error acaecido
 */
PooFusionExc::PooFusionExc ( std::string nFich
   , std::string nFun, std::string msg ): _fichero ( nFich )
                                          , _funcion ( nFun )
                                          , _mensaje ( msg )
{ }


/**
 * Constructor de copia
 * @param orig Excepción de la que se copian los valores
 * @post El nuevo objeto tiene exactamente la misma información que el que se
 *       pasa como parámetro
 */
PooFusionExc::PooFusionExc ( const PooFusionExc& orig ): _fichero ( orig._fichero )
                                                         , _funcion ( orig._funcion )
                                                         , _mensaje ( orig._mensaje )
{ }


/**
 * Destructor
 */
PooFusionExc::~PooFusionExc ( )
{ }


/**
 * Consulta sobre la excepción acaecida
 * @return Un mensaje indicando archivo, función/método y descripción del error
 */
std::string PooFusionExc::quePasa ( ) const
{
   return std::string ( _fichero + " -> " + _funcion + ": " + _mensaje );
}
