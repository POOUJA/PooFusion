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

#include "PaqueteDeCanales.h"
#include "ConexionInternet.h"

/**
 * Los objetos de esta clase representan personas físicas
 */
class Persona
{
   private:
      std::string _apeNom = "";   ///< Apellidos, nombre
      std::string _nif = "";      ///< NIF (formato "XXXXXXXX-X")
      PaqueteDeCanales* _miPaquete = nullptr;   ///< Paquete de canales contratado
      ConexionInternet* _miConexion = nullptr;   ///< Conexión contratada

   public:
      Persona () = default;
      Persona ( std::string nApeNom, std::string nNIF );
      Persona ( const Persona& orig );
      ~Persona ();
      void setNif ( std::string nNif );
      std::string getNif ( ) const;
      void setApeNom ( std::string nApeNom );
      std::string getApeNom ( ) const;
      ConexionInternet* setConexion ( ConexionInternet* nuevaC );
      ConexionInternet* getConexion ( ) const;
      PaqueteDeCanales* setPaqueteC ( PaqueteDeCanales* nuevoPC );
      PaqueteDeCanales* getPaqueteC ( ) const;
      Persona& operator= ( const Persona& otro );
};

#endif /* PERSONA_H */

