/**
 * @file Contenedor.h
 * @author algarcia
 *
 * @date 16 de abril de 2021, 11:55
 *
 * @brief Plantilla de clase contenedora
 */

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <stdexcept>
#include <iostream>


/**
 * Contenedor gen�rico
 */
template<typename T>
class Contenedor
{
   public:
      static const int MAX_TAM = 100;   ///< Tama�o m�ximo del contenedor

   private:
      T _elementos[MAX_TAM];   ///< Espacio para alojar los elementos
      int _numElementos = 0;   ///< N�mero de elementos almacenados
      int _maxElementos = MAX_TAM;   ///< N�mero m�ximo de elementos que se van a almacenar
      T _vacio;   ///< Valor que se utiliza para las posiciones vac�as

      void compactar ( int inicio );

   public:
      Contenedor ( int tamMaximo, T vVacio = T() );
      Contenedor ( const Contenedor& orig );
      ~Contenedor ();
      Contenedor& addElemento ( const T& nE );
      T& getElemento ( unsigned int cual );
      T sacaElemento ( unsigned int cual );
      int getNumElementos () const;
      Contenedor& operator= ( const Contenedor& otro );
      void vaciar ();
};

/**
 * Compacta el almacenamiento desplazando los elementos a partir de la
 * posici�n que se indica
 * @param inicio Posici�n a partir de la cual se desplazan los elementos
 * @post El almacenamiento queda compactado
 */
template<typename T>
void Contenedor<T>::compactar ( int inicio )
{
   for ( int i = inicio; i < _numElementos; i++ )
   {
      _elementos[i] = _elementos[i+1];
   }

   _elementos[_numElementos] = _vacio;
}


/**
 * Constructor parametrizado
 * @param tamMaximo M�ximo n�mero de elementos que se van a almacenar
 * @param vVacio (opcional) Valor a utilizar en las posiciones vac�as
 * @throw std::invalid_argument Si el tama�o que se solicita es negativo o
 *        mayor que el m�ximo permitido
 */
template<typename T>
Contenedor<T>::Contenedor ( int tamMaximo, T vVacio ):
   _maxElementos ( tamMaximo ), _vacio ( vVacio )
{
   if ( ( tamMaximo < 1 ) || ( tamMaximo > MAX_TAM ) )
   {
      throw std::invalid_argument ( "[Contenedor]: el tama�o del nuevo"
                                    " contenedor NO es v�lido" );
   }

   for ( int i = 0; i < MAX_TAM; i++ )
   {
      _elementos[i] = _vacio;
   }
}


/**
 * Constructor de copia
 * @param orig Contenedor del que se copia el contenido
 * @post El contenedor almacena copias de los valores almacenados en el original
 */
template<typename T>
Contenedor<T>::Contenedor ( const Contenedor& orig ):
   _numElementos ( orig._numElementos )
   , _maxElementos ( orig._maxElementos )
   , _vacio ( orig._vacio )
{
   int i;

   for ( i = 0; i < _numElementos; i++ )
   {
      _elementos[i] = orig._elementos[i];
   }

   for ( ; i < MAX_TAM; i++ )
   {
      _elementos[i] = _vacio;
   }
}


/**
 * Destructor
 */
template<typename T>
Contenedor<T>::~Contenedor ()
{ }


/**
 * A�ade un nuevo elemento al contenedor
 * @param nE Nuevo elemento
 * @throw std::length_error Si se ha alcanzado el m�ximo n�mero de elementos
 *        almacenables
 * @return Una referencia al propio contenedor, para permitir encadenar llamadas
 *         a m�todos
 */
template<typename T>
Contenedor<T>& Contenedor<T>::addElemento ( const T& nE )
{
   if ( _numElementos == _maxElementos )
   {
      throw std::length_error ( "[Contenedor::addElemento]: espacio insuficiente" );
   }

   _elementos[_numElementos] = nE;
   _numElementos++;

   return *this;
}


/**
 * Consulta un elemento del contenedor
 * @param cual Ordinal de la posici�n que se quiere consultar (valores v�lidos
 *        en el rango [0..n�mero de elementos almacenados-1])
 * @return El elemento almacenado en la posici�n consultada
 * @throw std::out_of_range Si el valor del ordinal no es v�lido
 */
template<typename T>
T& Contenedor<T>::getElemento ( unsigned int cual )
{
   if ( cual >= _numElementos )
   {
      throw std::out_of_range ( "[Contenedor::getElemento]: �ndice incorrecto" );
   }

   return _elementos[cual];
}


/**
 * Saca un elemento del contenedor
 * @param cual Ordinal de la posici�n que se quiere vaciar (valores v�lidos
 *        en el rango [0..n�mero de elementos almacenados -1])
 * @return El elemento almacenado en la posici�n indicada
 * @post El contenedor tiene un elemento menos
 * @throw std::out_of_range Si el valor del ordinal no es v�lido
 */
template<typename T>
T Contenedor<T>::sacaElemento ( unsigned int cual )
{
   if ( cual >= _numElementos )
   {
      throw std::out_of_range ( "[Contenedor::getElemento]: �ndice incorrecto" );
   }

   T aDevolver = _elementos[cual];
   _elementos[cual] = _vacio;
   _numElementos--;
   compactar ( cual );

   return aDevolver;
}


/**
 * Consulta el n�mero de elementos almacenados
 * @return El n�mero de elementos almacenados
 */
template<typename T>
int Contenedor<T>::getNumElementos () const
{
   return _numElementos;
}


/**
 * Operador de asignaci�n
 * @param otro Contenedor del que se copia la informaci�n
 * @return Una referencia al propio contenedor, para permitir encadenamiento de
 *         asignaciones
 */
template<typename T>
Contenedor<T>& Contenedor<T>::operator= ( const Contenedor& otro )
{
   if ( this != &otro )
   {
      _numElementos = otro._numElementos;
      _maxElementos = otro._maxElementos;
      _vacio = otro._vacio;

      for ( int i = 0; i < _numElementos; i++ )
      {
         _elementos[i] = otro._elementos[i];
      }

      for ( int i = _numElementos; i < MAX_TAM; i++ )
      {
         _elementos[i] = _vacio;
      }
   }

   return *this;
}


/**
 * Vac�a el contenedor
 * @post El contenedor se queda sin elementos
 */
template<typename T>
void Contenedor<T>::vaciar ()
{
   for ( int i = 0; i < _numElementos; i++ )
   {
      _elementos[i] = _vacio;
   }

   _numElementos = 0;
}

#endif /* CONTENEDOR_H */
