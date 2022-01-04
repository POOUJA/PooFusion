/** 
 * @file Contrato.h
 * @author algarcia
 *
 * @date 3 de abril de 2021, 12:14
 * 
 * @brief Declaración de la clase Contrato
 */

#ifndef CONTRATO_H
#define CONTRATO_H

#include "Persona.h"
#include "Contenedor.h"
#include "Producto.h"

/**
 * Contratos formalizados entre PooFusion y particulares
 */
class Contrato
{
   public:
      static const int MAX_PRODUCTOS = 10;   ///< Máximo número de productos

   private:
      int _fechaDeAlta = 0;   ///< Fecha de alta del contrato
      int _mesesPermanencia = 0;   ///< Meses de permanencia del contrato
      std::string _cuentaBancaria = "";   ///< IBAN de la cuenta de domiciliación
      bool _activo = true;   ///< Indica si el contrato está activo o no
      bool _conexionInternet = false; ///< Se ha añadido al contrato una conexión a Internet
      Persona* _abonado = nullptr;   ///< Persona a cuyo nombre está el contrato
      Contenedor<Producto*> _productos;   ///< Productos contratados

   public:
      Contrato ( Persona* nAbonado );
      Contrato ( Contrato& orig );
      virtual ~Contrato ( );
      Contrato& setFechaDeAlta ( int fechaDeAlta );
      int getFechaDeAlta ( ) const;
      bool tieneConexionInternet() const;
      Contrato& addProducto ( const ConexionInternet& nCI );
      Contrato& addProducto ( const Canal& nC );
      Contrato& addProducto ( const PaqueteDeCanales& nPC );
      Contrato& addProducto ( const Producto& nP );
      int getNumProductos ();
      Producto& getProducto ( int cual );
      Contrato& setAbonado ( Persona* abonado );
      Persona* getAbonado ( ) const;
      Contrato& setActivo ( bool activo );
      bool estaActivo ( ) const;
      Contrato& setCuentaBancaria ( std::string cuentaBancaria );
      std::string getCuentaBancaria ( ) const;
      Contrato& setMesesPermanencia ( int mesesPermanencia );
      int getMesesPermanencia ( ) const;
      float getPrecioMensual ();
};

#endif /* CONTRATO_H */

