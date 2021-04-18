/** 
 * @file Producto.h
 * @author algarcia
 *
 * @date 16 de abril de 2021, 12:24
 * 
 * @brief Declaración de la clase Producto
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

#include "Duplicable.h"


/**
 * Producto a contratar
 */
class Producto: public Duplicable
{
   protected:
      float _precioMensual = 0;   ///< Precio mensual del producto
     
   public:
      Producto ( ) = default;
      Producto ( float nPM );
      Producto ( const Producto& orig );
      virtual ~Producto ( );
      virtual std::string getDescripcion () = 0;
      virtual Duplicable* copia () const override = 0;
      virtual float getPrecioMensual ();
      void setPrecioMensual ( float nPM );
      Producto& operator= ( const Producto& otro );
} ;

#endif /* PRODUCTO_H */

