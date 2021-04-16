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
#include "Contenedores.h"

/**
 * Paquetes de canales de TV con un descuento
 */
class PaqueteDeCanales: public Producto
{
   private:
      float _descuento = 0;   ///< Descuento por el paquete
      ContenedorA<Canal> _canales;
  
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
      virtual std::string getDescripcion ();
      virtual Producto* copia ();
};

#endif /* PAQUETEDECANALES_H */

