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
 * Paquetes de canales de TV con un descuento
 */
class PaqueteDeCanales
{
   public:
      static const int MAX_CANALES = 5;   ///< Máximo de canales

   private:
      Canal* _canales[MAX_CANALES];   ///< Canales del paquete
      int _nCanales = 0;   ///< Número de canales que contiene el paquete
      float _descuento = 0;   ///< Descuento por el paquete
  
   public:
      PaqueteDeCanales ( float nDesc );
      PaqueteDeCanales ( const PaqueteDeCanales& orig );
      virtual ~PaqueteDeCanales ( );
      void setDescuento ( float nDesc );
      float getDescuento ( ) const;
      void addCanal ( Canal* nuevoC );
      Canal* getCanal ( int cual );
      Canal* sacaCanal ( int cual );
      int getNumCanales () const;
      PaqueteDeCanales& operator= ( const PaqueteDeCanales& otro );
};

#endif /* PAQUETEDECANALES_H */

