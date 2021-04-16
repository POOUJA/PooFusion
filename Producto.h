/* 
 * File:   Producto.h
 * Author: algarcia
 *
 * Created on 16 de abril de 2021, 12:24
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>


class Producto
{
   protected:
      float _precioMensual = 0;
     
   public:
      Producto ( ) = default;
      Producto ( float nPM );
      Producto ( const Producto& orig );
      virtual ~Producto ( );
      virtual std::string getDescripcion () = 0;
      virtual Producto* copia () const = 0;
      virtual float getPrecioMensual ();
      void setPrecioMensual ( float nPM );
      Producto& operator= ( const Producto& otro );
} ;

#endif /* PRODUCTO_H */

