/* 
 * File:   Contenedor.h
 * Author: algarcia
 *
 * Created on 16 de abril de 2021, 11:55
 */

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <stdexcept>
#include <iostream>


/**
 * Contenedor
 */
template<typename tipo>
class Contenedor
{
   public:
      static const int MAX_TAM = 100;

   private:
      tipo* _elementos[MAX_TAM];
      int _numElementos = 0;
      int _maxElementos = MAX_TAM;

      void compactar ( int inicio );

   public:
      Contenedor ( int tamMaximo );
      Contenedor ( const Contenedor& orig );
      ~Contenedor ();
      void addElemento ( tipo* nE );
      void addElemento ( tipo& nE );
      tipo* getElemento ( int cual );
      tipo* sacaElemento ( int cual );
      void borraElemento ( int cual );
      int getNumElementos () const;
      Contenedor& operator= ( const Contenedor& otro );
      void borrarTodo ();
      void nullify ();
};

template<typename tipo>
void Contenedor<tipo>::compactar ( int inicio )
{
   for ( int i = inicio; i < _numElementos; i++ )
   {
      _elementos[i] = _elementos[i+1];
   }
   
   _elementos[_numElementos] = nullptr;
}

template<typename tipo>
Contenedor<tipo>::Contenedor ( int tamMaximo ): _maxElementos ( tamMaximo )
{
   if ( ( tamMaximo < 1 ) || ( tamMaximo > MAX_TAM ) )
   {
      throw std::invalid_argument ( "[Contenedor]: el tamaño del nuevo"
                                    " contenedor NO es válido" );
   }

   for ( int i = 0; i < MAX_TAM; i++ )
   {
      _elementos[i] = nullptr;
   }
}

template<typename tipo>
Contenedor<tipo>::Contenedor ( const Contenedor& orig ):
                                            _numElementos ( orig._numElementos )
                                          , _maxElementos ( orig._maxElementos )
{
   // ¡Ojo! este constructor de copia es válido para agregaciones, no para
   // composiciones
   int i;

   std::cerr << "Creando una copia en modo agregación" << std::endl;

   for ( i = 0; i < _numElementos; i++ )
   {
      _elementos[i] = orig._elementos[i];
   }
   
   for ( ; i < MAX_TAM; i++ )
   {
      _elementos[i] = nullptr;
   }
}

template<typename tipo>
Contenedor<tipo>::~Contenedor ()
{
   if ( _numElementos > 0 )
   {
      std::cerr << "[Contenedor] Se está intentando destruir un contenedor que"
                << " no está vacío" << std::endl;
   }
}

template<typename tipo>
void Contenedor<tipo>::addElemento ( tipo* nE )
{
   if ( _numElementos == _maxElementos )
   {
      throw std::length_error ( "[Contenedor::addElemento]: espacio insuficiente" );
   }
   
   _elementos[_numElementos] = nE;
   _numElementos++;
}

template<typename tipo>
void Contenedor<tipo>::addElemento ( tipo& nE )
{
   addElemento ( &nE );
}

template<typename tipo>
tipo* Contenedor<tipo>::getElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[Contenedor::getElemento]: índice incorrecto" );
   }
   
   return _elementos[cual];
}

template<typename tipo>
tipo* Contenedor<tipo>::sacaElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[Contenedor::getElemento]: índice incorrecto" );
   }

   tipo* aDevolver = _elementos[cual];
   _elementos[cual] = nullptr;
   _numElementos--;
   compactar ( cual );

   return aDevolver;   
}

template<typename tipo>
void Contenedor<tipo>::borraElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[Contenedor::getElemento]: índice incorrecto" );
   }

   delete _elementos[cual];
   _elementos[cual] = nullptr;
   _numElementos--;
   compactar ( cual );
}

template<typename tipo>
int Contenedor<tipo>::getNumElementos () const
{
   return _numElementos;
}

template<typename tipo>
Contenedor<tipo>& Contenedor<tipo>::operator= ( const Contenedor& otro )
{
   // ¡Ojo si se utiliza el contenedor para una composición!
   // En ese caso, este operador de asignación no vale
   
   std::cerr << "Asignando en modo agregación" << std::endl;
   if ( this != &otro )
   {
      nullify ();
      
      for ( int i = 0; i < otro._numElementos; i++ )
      {
         _elementos[i] = otro._elementos[i];
      }
      _numElementos = otro._numElementos;
      _maxElementos = otro._maxElementos;
   }
   
   return *this;
}


template<typename tipo>
void Contenedor<tipo>::borrarTodo ()
{
   for ( int i = 0; i < _numElementos; i++ )
   {
      delete _elementos[i];
      _elementos[i] = 0;
   }
   
   _numElementos = 0;
}

template<typename tipo>
void Contenedor<tipo>::nullify ()
{
   for ( int i = 0; i < _numElementos; i++ )
   {
      _elementos[i] = nullptr;
   }
   
   _numElementos = 0;
}

#endif /* CONTENEDOR_H */

