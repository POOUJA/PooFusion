/** 
 * @file PaqueteDeCanales.h
 * @author algarcia
 *
 * @date 3 de abril de 2021, 9:38
 * 
 * @brief Declaración de la clase PaqueteDeCanales
 */

#ifndef PAQUETEDECANALES_H
#define PAQUETEDECANALES_H

#include "Canal.h"
#include "Contenedor.h"
#include "Producto.h"

/**
 * Paquetes de canales de TV con un descuento
 */
class PaqueteDeCanales: public Producto
{
   public:
      static const int MAX_CANALES = 5;   ///< Máximo de canales por paquete

   private:
      float _descuento = 0;   ///< Descuento por el paquete
      Contenedor<Canal*> _canales;   ///< Canales del paquete
  
   public:
      PaqueteDeCanales ( float nDesc );
      PaqueteDeCanales ( const PaqueteDeCanales& orig );
      virtual ~PaqueteDeCanales ( );
      PaqueteDeCanales& setDescuento ( float nDesc );
      float getDescuento ( ) const;
      virtual float getPrecioMensual ( ) override;
      PaqueteDeCanales& addCanal ( Canal* nuevoC );
      Canal* getCanal ( int cual );
      Canal* sacaCanal ( int cual );
      int getNumCanales () const;
      PaqueteDeCanales& operator= ( const PaqueteDeCanales& otro );
      virtual std::string getDescripcion () override;
      virtual Duplicable* copia () const override;
};

#endif /* PAQUETEDECANALES_H */

