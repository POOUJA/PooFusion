/** 
 * @file Canal.h
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:50
 * 
 * @brief Declaración de la clase Canal
 */

#ifndef CANAL_H
#define CANAL_H

#include <string>

/**
 * Los objetos de esta clase representan canales de TV
 */
class Canal
{
   private:
      std::string _nombre = "";   ///< Nombre del canal
      
   public:
      Canal () = default;
      Canal ( std::string nNombre );
      Canal ( const Canal& orig );
      void setNombre ( std::string nNombre );
      std::string getNombre ( ) const;
};

#endif /* CANAL_H */

