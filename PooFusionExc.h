/** 
 * @file PooFusionExc.h
 * @author algarcia
 *
 * @date 31 de marzo de 2021, 18:08
 * 
 * @brief Declaración de la clase PooFusionExc
 */

#ifndef POOFUSIONEXC_H
#define POOFUSIONEXC_H

#include <string>

/**
 * Los objetos de esta clase guardan información relativa a excepciones
 */
class PooFusionExc
{
   private:
      std::string _fichero = "";
      std::string _funcion = "";
      std::string _mensaje = "";

   public:
      PooFusionExc ( std::string nFun, std::string msg, std::string nFich = "" );
      PooFusionExc ( const PooFusionExc& orig );

      virtual ~PooFusionExc ( ) noexcept = default;

      std::string quePasa () const;
};

#endif /* POOFUSIONEXC_H */

