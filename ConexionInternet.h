/** 
 * @file ConexionInternet.h
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:51
 * 
 * @brief Declaración de la clase ConexionInternet
 */

#ifndef CONEXIONINTERNET_H
#define CONEXIONINTERNET_H

#include <string>

/**
 * Los objetos de esta clase representan conexiones a Internet
 */
class ConexionInternet
{
   private:
      std::string tipo = "";   ///< Tipo de conexión
      int velocidadMB = 0;    ///< Velocidad máxima en MB
};

#endif /* CONEXIONINTERNET_H */

