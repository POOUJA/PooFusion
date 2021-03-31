/** 
 * @file Persona.h
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:46
 * 
 * @brief Declaración de la clase Persona
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

/**
 * Los objetos de esta clase representan personas físicas
 */
class Persona
{
   private:
      std::string _apeNom = "";   ///< Apellidos, nombre
      std::string _nif = "";      ///< NIF (formato "XXXXXXXX-X")

   public:
      Persona () = default;
      Persona ( std::string nApeNom, std::string nNIF );
      Persona ( const Persona& orig );
      void setNif ( std::string nNif );
      std::string getNif ( ) const;
      void setApeNom ( std::string nApeNom );
      std::string getApeNom ( ) const;
};

#endif /* PERSONA_H */

