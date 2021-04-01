/** 
 * @file MiExcepcion.h
 * @author algarcia
 *
 * @date 31 de marzo de 2021, 18:08
 * 
 * @brief Declaración de la clase MiExcepcion
 */

#ifndef MIEXCEPCION_H
#define MIEXCEPCION_H

#include <string>

/**
 * Los objetos de esta clase guardan información relativa a excepciones
 */
class MiExcepcion
{
   private:
      std::string _fichero = "";
      std::string _funcion = "";
      std::string _mensaje = "";

   public:
      MiExcepcion ( std::string nFich, std::string nFun, std::string msg );
      MiExcepcion ( const MiExcepcion& orig );
      virtual ~MiExcepcion ( );
      std::string quePasa () const;
};

#endif /* MIEXCEPCION_H */

