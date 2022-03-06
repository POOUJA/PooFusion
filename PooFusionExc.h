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
      PooFusionExc ( std::string nFich, std::string nFun, std::string msg );
      PooFusionExc ( const PooFusionExc& orig );
      virtual ~PooFusionExc ( );
      std::string quePasa () const;
};

#endif /* POOFUSIONEXC_H */