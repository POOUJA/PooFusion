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

/**
 * Paquetes con (por el momento) hasta dos canales de TV con un descuento
 */
class PaqueteDeCanales
{
   private:
      Canal* _c1 = nullptr;   ///< Primer canal del paquete
      Canal* _c2 = nullptr;   ///< Segundo canal del paquete
      float _descuento = 0;   ///< Descuento por el paquete
  
   public:
      PaqueteDeCanales ( Canal* nC1, Canal* nC2, float nDesc );
      PaqueteDeCanales ( const PaqueteDeCanales& orig );
      virtual ~PaqueteDeCanales ( );
      void setDescuento ( float nDesc );
      float getDescuento ( ) const;
      Canal* setC2 ( Canal* nC2 );
      Canal* getC2 ( ) const;
      Canal* setC1 ( Canal* nC1 );
      Canal* getC1 ( ) const;
      PaqueteDeCanales& operator= ( const PaqueteDeCanales& otro );
};

#endif /* PAQUETEDECANALES_H */

