/** 
 * @file Producto.h
 * @author algarcia
 *
 * @date 14 de abril de 2021, 20:16
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

/**
 * Producto de PooFusion
 */
class Producto
{
   protected:
      float _precioMensual = 0;   ///< Precio mensual del producto
  
   public:
      Producto ( ) = default;
      Producto ( const Producto& orig );
      virtual ~Producto ( );
      float getPrecioMensual ( ) const;
      void setPrecioMensual ( float nPM );
      Producto& operator= ( const Producto& otro );
};

#endif /* PRODUCTO_H */

