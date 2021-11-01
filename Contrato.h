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
#include "ConexionInternet.h"
#include "PaqueteDeCanales.h"
#include "Contenedor.h"

/**
 * Contratos formalizados entre PooFusion y particulares
 */
class Contrato
{
   public:
      static const int MAX_PRODUCTOS = 10;

   private:
      int _fechaDeAlta = 0;
      int _mesesPermanencia = 0;
      std::string _cuentaBancaria = "";
      bool _activo = true;
      Persona* _abonado = nullptr;

      bool _conexionInternet = false;
      Contenedor<Producto*> _productos;   ///< Productos contratados

   public:
      Contrato ( Persona* nAbonado = nullptr);
      Contrato ( const Contrato& orig );
      virtual ~Contrato ( );
      Contrato& setFechaDeAlta ( int fechaDeAlta );
      int getFechaDeAlta ( ) const;
      Contrato& addProducto ( const Canal &c );
      Contrato& addProducto ( const ConexionInternet &ci );
      Contrato& addProducto ( const PaqueteDeCanales &pc );
      Contrato& addProducto ( const Producto &p );
      Producto& getProducto(int i);
      int getNumProductos() const;
      bool tieneConexionInternet() const;

      Contrato& setAbonado ( Persona* abonado );
      Persona* getAbonado ( ) const;
      Contrato& setActivo ( bool activo );
      bool estaActivo ( ) const;
      Contrato& setCuentaBancaria ( std::string cuentaBancaria );
      std::string getCuentaBancaria ( ) const;
      Contrato& setMesesPermanencia ( int mesesPermanencia );
      int getMesesPermanencia ( ) const;
};

#endif /* CONTRATO_H */

