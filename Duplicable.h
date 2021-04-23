/** 
 * @file Duplicable.h
 * @author algarcia
 *
 * @date 18 de abril de 2021, 11:17
 * 
 * @brief Declaración de la interfaz Duplicable
 */

#ifndef DUPLICABLE_H
#define DUPLICABLE_H

/**
 * Interfaz para obligar a implementar un método para crear copias del propio
 * objeto
 */
class Duplicable
{
   public:
      virtual Duplicable* copia () const = 0;
      virtual ~Duplicable () = default;
};

#endif /* DUPLICABLE_H */

