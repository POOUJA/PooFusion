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
      std::string apeNom = "";   ///< Apellidos, nombre
      std::string nif = "";      ///< NIF (formato "XXXXXXXX-X")
};

#endif /* PERSONA_H */

