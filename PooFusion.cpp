/**
 * @file PooFusion.cpp
 * @author algarcia
 *
 * @date 30 de marzo de 2021, 17:19
 *
 * @brief Implementación de las funciones del módulo PooFusion
 */

#include "PooFusion.h"

#include <iostream>

/**
 * @brief Muestra por la consola estándar la información de una persona
 * @param pParam Persona de la que se muestra la información
 */
void PooFusion::mostrarPersona ( Persona& pParam )
{
   std::cout << "Persona con NIF " << pParam.nif
             << ". Apellidos y nombre: " << pParam.apeNom << std::endl;
}

/**
 * @brief Muestra por la consola estándar la información de una conexión a Internet
 * @param cParam Conexión de la que se muestra la información
 */
void PooFusion::mostrarConexion ( ConexionInternet& cParam )
{
   std::cout << "Conexión a Internet de tipo " << cParam.tipo
             << " y " << cParam.velocidadMB << " MB de velocidad" << std::endl;
}

/**
 * @brief Muestra por la consola estándar la información de un canal de TV
 * @param cParam Canal del que se muestra la información
 */
void PooFusion::mostrarCanal ( Canal& cParam )
{
   std::cout << "Canal de televisión " << cParam.nombre << std::endl;
}

