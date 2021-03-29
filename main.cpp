/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 29 de marzo de 2021, 17:57
 */

#include <cstdlib>
#include <string>

using namespace std;

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


/**
 * @brief Punto de inicio de la aplicación
 */
int main ( int argc, char** argv )
{
   // Creación de una variable de tipo Persona
   Persona p;

   // Asignación de valores a los campos
   p.apeNom = "García, Javier";
   p.nif = "12345678-K";

   // Creación de una variable de tipo ConexionInternet
   ConexionInternet c;

   // Asignación de valores a los campos
   c.tipo = "Fibra óptica";
   c.velocidadMB = 300;

   // Creación de una variable de tipo Canal
   Canal c2;

   // Asignación de valores a los campos
   c2.nombre = "Eurosport";

   return 0;
}

