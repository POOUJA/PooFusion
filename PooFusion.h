/** 
 * @file PooFusion.h
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:16
 * 
 * @brief Declaración del módulo PooFusion
 */

#ifndef POOFUSION_H
#define POOFUSION_H

#include <string>

/**
 * Espacio de nombres que aglutina estructuras y funciones relacionadas
 * con el proyecto PooFusion 
 */
namespace PooFusion
{
   /**
    * @brief Información sobre personas
    */
   struct Persona
   {
      std::string apeNom;   ///< Apellidos, nombre
      std::string nif;      ///< NIF (formato "XXXXXXXX-X")
   };
 
   /**
    * @brief Información sobre conexiones a Internet
    */
   struct ConexionInternet
   {
      std::string tipo;   ///< Tipo de conexión
      int velocidadMB;    ///< Velocidad máxima en MB
   };
 
   /**
    * @brief Información sobre canales de TV
    */
   struct Canal
   {
      std::string nombre;   ///< Nombre del canal
   };
   
   void mostrarPersona ( Persona& pParam );
   void mostrarConexion ( ConexionInternet& cParam );
   void mostrarCanal ( Canal& cParam );

};


#endif /* POOFUSION_H */

