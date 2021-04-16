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

#include "Producto.h"

/**
 * Los objetos de esta clase representan canales de TV
 */
class Canal: public Producto
{
   private:
      std::string _nombre = "";   ///< Nombre del canal
      
   public:
      Canal () = default;
      Canal ( std::string nNombre, float precio );
      Canal ( const Canal& orig );
      ~Canal ();
      Canal& setNombre ( std::string nNombre );
      std::string getNombre ( ) const;
      Canal& operator= ( const Canal& otro );
      virtual std::string getDescripcion () override;
      virtual Producto* copia () const override;
};

#endif /* CANAL_H */

