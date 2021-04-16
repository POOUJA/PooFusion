/* 
 * File:   Contenedores.h
 * Author: algarcia
 *
 * Created on 16 de abril de 2021, 11:55
 */

#ifndef CONTENEDORES_H
#define CONTENEDORES_H

#include <stdexcept>


/**
 * Contenedor aplicando composición
 */
template<typename tipo>
class ContenedorC
{
   public:
      static const int MAX_TAM = 100;

   private:
      tipo* _elementos[MAX_TAM];
      int _numElementos = 0;

      void compactar ( int inicio );

   public:
      ContenedorC ();
      ContenedorC ( const ContenedorC& orig );
      ~ContenedorC ();
      void addElemento ( tipo* nE );
      void addElemento ( tipo& nE );
      tipo* getElemento ( int cual );
      tipo* sacaElemento ( int cual );
      void borraElemento ( int cual );
      int getNumElementos () const;
      ContenedorC& operator= ( ContenedorC& otro );
};

template<typename tipo>
void ContenedorC<tipo>::compactar ( int inicio )
{
   for ( int i = inicio; i < _numElementos; i++ )
   {
      _elementos[i] = _elementos[i+1];
   }
   
   _elementos[_numElementos] = nullptr;
}

template<typename tipo>
ContenedorC<tipo>::ContenedorC ()
{
   for ( int i = 0; i < MAX_TAM; i++ )
   {
      _elementos[i] = nullptr;
   }
}

template<typename tipo>
ContenedorC<tipo>::ContenedorC ( const ContenedorC& orig ):
                                            _numElementos ( orig._numElementos )
{
   int i;

   for ( i = 0; i < _numElementos; i++ )
   {
      _elementos[i] = new tipo ( *orig._elementos[i] );
   }
   
   for ( ; i < MAX_TAM; i++ )
   {
      _elementos[i] = nullptr;
   }
}

template<typename tipo>
ContenedorC<tipo>::~ContenedorC ()
{
   for ( int i = 0; i < _numElementos; i++ )
   {
      delete _elementos[i];
      _elementos[i] = nullptr;
   }
}

template<typename tipo>
void ContenedorC<tipo>::addElemento ( tipo* nE )
{
   if ( _numElementos == MAX_TAM )
   {
      throw std::length_error ( "[ContenedorC::addElemento]: espacio insuficiente" );
   }
   
   _elementos[_numElementos] = new tipo ( *nE );
   _numElementos++;
}

template<typename tipo>
void ContenedorC<tipo>::addElemento ( tipo& nE )
{
   addElemento ( &nE );
}

template<typename tipo>
tipo* ContenedorC<tipo>::getElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[ContenedorC::getElemento]: índice incorrecto" );
   }
   
   return _elementos[cual];
}

template<typename tipo>
tipo* ContenedorC<tipo>::sacaElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[ContenedorC::getElemento]: índice incorrecto" );
   }

   tipo* aDevolver = _elementos[cual];
   _elementos[cual] = nullptr;
   _numElementos--;
   compactar ( cual );

   return aDevolver;   
}

template<typename tipo>
void ContenedorC<tipo>::borraElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[ContenedorC::getElemento]: índice incorrecto" );
   }

   delete _elementos[cual];
   _elementos[cual] = nullptr;
   _numElementos--;
   compactar ( cual );
}

template<typename tipo>
int ContenedorC<tipo>::getNumElementos () const
{
   return _numElementos;
}



/**
 * Contenedor aplicando agregación
 */
template<typename tipo>
class ContenedorA
{
   public:
      static const int MAX_TAM = 100;

   private:
      tipo* _elementos[MAX_TAM];
      int _numElementos = 0;

      void compactar ( int inicio );

   public:
      ContenedorA ();
      ContenedorA ( const ContenedorA& orig );
      ~ContenedorA ();
      void addElemento ( tipo* nE );
      void addElemento ( tipo& nE );
      tipo* getElemento ( int cual );
      tipo* sacaElemento ( int cual );
      void borraElemento ( int cual );
      int getNumElementos () const;
};

template<typename tipo>
void ContenedorA<tipo>::compactar ( int inicio )
{
   for ( int i = inicio; i < _numElementos; i++ )
   {
      _elementos[i] = _elementos[i+1];
   }
   
   _elementos[_numElementos] = nullptr;
}

template<typename tipo>
ContenedorA<tipo>::ContenedorA ()
{
   for ( int i = 0; i < MAX_TAM; i++ )
   {
      _elementos[i] = nullptr;
   }
}

template<typename tipo>
ContenedorA<tipo>::ContenedorA ( const ContenedorA& orig ):
                                            _numElementos ( orig._numElementos )
{
   int i;

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
ContenedorA<tipo>::~ContenedorA ()
{
   for ( int i = 0; i < _numElementos; i++ )
   {
      _elementos[i] = nullptr;
   }
}

template<typename tipo>
void ContenedorA<tipo>::addElemento ( tipo* nE )
{
   if ( _numElementos == MAX_TAM )
   {
      throw std::length_error ( "[ContenedorC::addElemento]: espacio insuficiente" );
   }
   
   _elementos[_numElementos] = nE;
   _numElementos++;
}

template<typename tipo>
void ContenedorA<tipo>::addElemento ( tipo& nE )
{
   addElemento ( &nE );
}

template<typename tipo>
tipo* ContenedorA<tipo>::getElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[ContenedorC::getElemento]: índice incorrecto" );
   }
   
   return _elementos[cual];
}

template<typename tipo>
tipo* ContenedorA<tipo>::sacaElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[ContenedorC::getElemento]: índice incorrecto" );
   }

   tipo* aDevolver = _elementos[cual];
   _elementos[cual] = nullptr;
   _numElementos--;
   compactar ( cual );

   return aDevolver;   
}

template<typename tipo>
void ContenedorA<tipo>::borraElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[ContenedorC::getElemento]: índice incorrecto" );
   }

   _elementos[cual] = nullptr;
   _numElementos--;
   compactar ( cual );
}

template<typename tipo>
int ContenedorA<tipo>::getNumElementos () const
{
   return _numElementos;
}

#endif /* CONTENEDORES_H */

