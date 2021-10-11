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

/**
 * Producto a contratar
 */
class Producto
{
   protected:
      float _precioMensual = 0;   ///< Precio mensual del producto
     
   public:
      Producto ( ) = default;
      Producto ( float nPM );
      Producto ( const Producto& orig );
      virtual ~Producto ( );
      virtual std::string getDescripcion ();
      virtual float getPrecioMensual ();
      void setPrecioMensual ( float nPM );
      Producto& operator= ( const Producto& otro );
} ;

#endif /* PRODUCTO_H */

