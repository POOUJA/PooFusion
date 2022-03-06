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
#include "Producto.h"

/**
 * Los objetos de esta clase representan conexiones a Internet
 */
class ConexionInternet: public Producto
{
   private:
      std::string _tipo = "";   ///< Tipo de conexión
      int _velocidadMB = 0;    ///< Velocidad máxima en MB
      
   public:
      ConexionInternet () = default;
      ConexionInternet ( float nPrecio, std::string nTipo, int nVel );
      ConexionInternet ( std::string nTipo, int nVel );
      ConexionInternet ( const ConexionInternet& orig );
      ~ConexionInternet ();
      void setVelocidadMB ( int nVel );
      int getVelocidadMB ( ) const;
      void setTipo ( std::string nTipo );
      std::string getTipo ( ) const;
      ConexionInternet& operator= ( const ConexionInternet& otro );
      bool operator< ( const ConexionInternet& otro );
      bool operator== ( const ConexionInternet& otro );
};

#endif /* CONEXIONINTERNET_H */

