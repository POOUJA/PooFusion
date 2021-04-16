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
 * Contenedor genérico
 */
template<typename tipo>
class Contenedor
{
   public:
      static const int MAX_TAM = 100;   ///< Tamaño máximo del contenedor

   private:
      tipo _elementos[MAX_TAM];   ///< Espacio para alojar los elementos
      int _numElementos = 0;   ///< Número de elementos almacenados
      int _maxElementos = MAX_TAM;   ///< Número máximo de elementos que se van a almacenar
      tipo _vacio;   ///< Valor que se utiliza para las posiciones vacías

      void compactar ( int inicio );

   public:
      Contenedor ( int tamMaximo, tipo vVacio );
      Contenedor ( const Contenedor& orig );
      ~Contenedor ();
      void addElemento ( tipo nE );
      tipo& getElemento ( int cual );
      tipo sacaElemento ( int cual );
      int getNumElementos () const;
      Contenedor& operator= ( const Contenedor& otro );
};

/**
 * Compacta el almacenamiento desplazando los elementos a partir de la
 * posición que se indica
 * @param inicio Posición a partir de la cual se desplazan los elementos
 * @post El almacenamiento queda compactado
 */
template<typename tipo>
void Contenedor<tipo>::compactar ( int inicio )
{
   for ( int i = inicio; i < _numElementos; i++ )
   {
      _elementos[i] = _elementos[i+1];
   }
   
   _elementos[_numElementos] = _vacio;
}


/**
 * Constructor parametrizado
 * @param tamMaximo Máximo número de elementos que se van a almacenar
 * @param vVacio Valor a utilizar en las posiciones vacías
 * @throw std::invalid_argument Si el tamaño que se solicita es negativo o
 *        mayor que el máximo permitido
 */
template<typename tipo>
Contenedor<tipo>::Contenedor ( int tamMaximo, tipo vVacio ):
                             _maxElementos ( tamMaximo ), _vacio ( vVacio )
{
   if ( ( tamMaximo < 1 ) || ( tamMaximo > MAX_TAM ) )
   {
      throw std::invalid_argument ( "[Contenedor]: el tamaño del nuevo"
                                    " contenedor NO es válido" );
   }
}


/**
 * Constructor de copia
 * @param orig Contenedor del que se copia el contenido
 * @post El contenedor almacena copias de los valores almacenados en el original
 */
template<typename tipo>
Contenedor<tipo>::Contenedor ( const Contenedor& orig ):
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
template<typename tipo>
Contenedor<tipo>::~Contenedor ()
{ }


/**
 * Añade un nuevo elemento al contenedor
 * @param nE Nuevo elemento
 * @throw std::length_error Si se ha alcanzado el máximo número de elementos
 *        almacenables
 */
template<typename tipo>
void Contenedor<tipo>::addElemento ( tipo nE )
{
   if ( _numElementos == _maxElementos )
   {
      throw std::length_error ( "[Contenedor::addElemento]: espacio insuficiente" );
   }
   
   _elementos[_numElementos] = nE;
   _numElementos++;
}


/**
 * Consulta un elemento del contenedor
 * @param cual Ordinal de la posición que se quiere consultar (valores válidos
 *        en el rango [0..número de elementos almacenados-1])
 * @return El elemento almacenado en la posición consultada
 * @throw std::out_of_range Si el valor del ordinal no es válido
 */
template<typename tipo>
tipo& Contenedor<tipo>::getElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[Contenedor::getElemento]: índice incorrecto" );
   }
   
   return _elementos[cual];
}


/**
 * Saca un elemento del contenedor
 * @param cual Ordinal de la posición que se quiere vaciar (valores válidos
 *        en el rango [0..número de elementos almacenados -1])
 * @return El elemento almacenado en la posición indicada
 * @post El contenedor tiene un elemento menos
 * @throw std::out_of_range Si el valor del ordinal no es válido
 */
template<typename tipo>
tipo Contenedor<tipo>::sacaElemento ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numElementos ) )
   {
      throw std::out_of_range ( "[Contenedor::getElemento]: índice incorrecto" );
   }

   tipo aDevolver = _elementos[cual];
   _elementos[cual] = _vacio;
   _numElementos--;
   compactar ( cual );

   return aDevolver;
}


/**
 * Consulta el número de elementos almacenados
 * @return El número de elementos almacenados
 */
template<typename tipo>
int Contenedor<tipo>::getNumElementos () const
{
   return _numElementos;
}


/**
 * Operador de asignación
 * @param otro Contenedor del que se copia la información
 * @return Una referencia al propio contenedor, para permitir encadenamiento de
 *         asignaciones
 */
template<typename tipo>
Contenedor<tipo>& Contenedor<tipo>::operator= ( const Contenedor& otro )
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

#endif /* CONTENEDOR_H */

