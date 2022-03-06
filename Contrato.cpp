/**
 * @file Contrato.cpp
 * @author algarcia
 *
 * @date 3 de abril de 2021, 12:14
 *
 * @brief Implementación de los métodos de la clase Contrato
 */

#include <ctime>

#include "Contrato.h"
#include "PooFusionExc.h"
#include "ConexionInternet.h"
#include "PaqueteDeCanales.h"

/**
 * Constructor parametrizado
 * @param nAbonado Persona a nombre de quien se hace el contrato
 * @post El nuevo contrato no tiene servicios aún, aunque sí está activo
 * @throw PooFusionExc Si se le pasa como parámetro nullptr
 */
Contrato::Contrato ( Persona* nAbonado ): _abonado ( nAbonado ),  _conexionInternet(false), _productos(MAX_PRODUCTOS,nullptr)
{
   if ( nAbonado == nullptr )
   {
      throw PooFusionExc ( "Contrato.cpp", "Contrato::Contrato"
                        , "El contrato ha de tener un abonado" );
   }

   // Toma la fecha actual para el contrato
   time_t ahora = std::time ( nullptr );

   struct tm* ahora2 = localtime ( &ahora );

   _fechaDeAlta = ( ahora2->tm_year + 1900 ) * 10000;
   _fechaDeAlta += ( ahora2->tm_mon + 1 ) * 100;
   _fechaDeAlta += ahora2->tm_mday;
}


/**
 * Constructor de copia
 * @param orig Contrato del que se copian los valores
 * @post El nuevo contrato tiene los mismos datos pero no copia los productos (por ahora)
 */
Contrato::Contrato ( const Contrato& orig ): _fechaDeAlta ( orig._fechaDeAlta )
                                  , _mesesPermanencia ( orig._mesesPermanencia )
                                  , _cuentaBancaria ( orig._cuentaBancaria )
                                  , _activo ( orig._activo )
                                  , _abonado ( orig._abonado )
                                  , _conexionInternet(false)
                                  , _productos(orig._productos)
{
    //ToDo por ahora no sabemos cómo copiar los productos según el tipo de cada uno...
}


/**
 * Destructor
 * @note Desvincula al abonado, pero NO lo destruye. Es una responsabilidad
 *       externa a esta clase
 */
Contrato::~Contrato ( )
{
   _abonado = nullptr;
    for (int i = 0; i < _productos.getNumElementos(); ++i) {
       Producto *aux=_productos.sacaElemento(0);
       delete aux;
    }
}


/**
 * Cambia la fecha de alta del contrato
 * @param fechaDeAlta Nueva fecha de alta (formato YYYYMMDD)
 * @post La fecha de alta del contrato cambia al valor pasado como parámetro
 * @return Una referencia al propio contrato
 */
Contrato& Contrato::setFechaDeAlta ( int fechaDeAlta )
{
   this->_fechaDeAlta = fechaDeAlta;

   return *this;
}


/**
 * Consulta de la fecha de alta del contrato
 * @return La fecha de alta del contrato en formato YYYYMMDD
 */
int Contrato::getFechaDeAlta ( ) const
{
   return _fechaDeAlta;
}

/**
 * Añade una Conexión de Internet al Contrato
 * @param ci Conexión que se añade
 * @post El contrato incluye un producto más
 * @throw PooFusionExc Si el contrato no permite más productos
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const ConexionInternet& ci )
{

    Producto *nuevo=new ConexionInternet(ci);

    try{
        _productos.addElemento(nuevo);
        _conexionInternet=true;
    }catch (std::length_error& e){
        delete nuevo;
        nuevo= nullptr;
        throw PooFusionExc("Contrato.cpp", "Contrato::addProducto", e.what());
    }

    return *this;
}


/**
 * Añade un canal al Contrato
 * @param c Canal de TV que se añade
 * @post El contrato incluye un canal más
 * @throw PooFusionExc Si el contrato no permite más canales
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const Canal& c )
{

   if (_conexionInternet==false) {
       throw PooFusionExc ( "Contrato.cpp", "Contrato::addProducto",
                           "No se puede añadir un canal sin disponer de conexión a internet" );
   }

   Producto* nuevo= new Canal(c);

   try{
       _productos.addElemento(nuevo);
   }catch (std::length_error& e){
       delete nuevo;
       nuevo=nullptr;
       throw PooFusionExc("Contrato.cpp","Contrato::addProducto", e.what());
   }

   return *this;
}
/**
 * Añade un paquete de canales al Contrato
 * @param pc Paquete de canales que se añade
 * @post El contrato incluye un producto más
 * @throw PooFusionExc Si el contrato no permite más productos
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const PaqueteDeCanales& pc )
{

    if (_conexionInternet==false) {
        throw PooFusionExc ( "Contrato.cpp", "Contrato::addProducto",
                            "No se puede añadir un PaqueteDeCanales sin disponer de conexión a internet" );
    }

    Producto* nuevo= new PaqueteDeCanales(pc);

    try{
        _productos.addElemento(nuevo);
    }catch (std::length_error& e){
        delete nuevo;
        nuevo=nullptr;
        throw PooFusionExc("Contrato.cpp","Contrato::addProducto", e.what());
    }

    return *this;
}

/**
 * Añade un producto al Contrato
 * @param p Producto que se añade
 * @post El contrato incluye un producto más
 * @throw PooFusionExc Si el contrato no permite más canales
 * @return Una referencia al objeto actual, para permitir encadenamiento de
 *         llamadas a métodos
 */
Contrato& Contrato::addProducto ( const Producto& p )
{

    //ToDo por ahora no tenemos una forma de saber si el producto es una ConexionInternet
    if (_conexionInternet==false) {
        throw PooFusionExc ( "Contrato.cpp", "Contrato::addProducto",
                            "No se puede añadir un producto sin disponer de conexión a internet" );
    }

    Producto* nuevo= new Producto(p);

    try{
        _productos.addElemento(nuevo);
    }catch (std::length_error& e){
        delete nuevo;
        nuevo=nullptr;
        throw PooFusionExc("Contrato.cpp","Contrato::addProducto", e.what());
    }

    return *this;
}


/**
 * Devuelve el i-esimo producto
 * @return Una referencia al producto del contrato
 */
Producto& Contrato::getProducto(int cual)
{
    try{
        return *_productos.getElemento(cual-1);
    }catch(std::out_of_range& e){
        throw PooFusionExc("Contrato.cpp","Contrato::getProducto",e.what());
    }
}

int Contrato::getNumProductos() const
{
    return _productos.getNumElementos();
}

/**
 * Asigna un nuevo abonado al contrato
 * @param abonado Nuevo abonado
 * @post El contrato cambia de abonado
 * @return Una referencia al propio contrato
 * @throw PooFusionExc Si el parámetro es nullptr
 * @note El abonado anterior NO se destruye. Es una responsabilidad externa a
 *       esta clase
 */
Contrato& Contrato::setAbonado ( Persona* abonado )
{
   if ( abonado == nullptr )
   {
      throw PooFusionExc ( "Contrato.cpp", "Contrato::setAbonado"
                        , "El contrato tiene que tener un abonado" );
   }

   this->_abonado = abonado;

   return *this;
}


/**
 * Consulta el abonado asociado al contrato
 * @return Un puntero al abonado
 */
Persona* Contrato::getAbonado ( ) const
{
   return _abonado;
}


/**
 * Cambia el estado del contrato (activo/inactivo)
 * @param activo Nuevo estado del contrato
 * @post El contrato cambia de estado según el parámetro que se le pasa
 * @return Una referencia al propio contrato
 */
Contrato& Contrato::setActivo ( bool activo )
{
   this->_activo = activo;

   return *this;
}


/**
 * Consulta si el contrato está activo
 * @retval true Si el contrato está activo
 * @retval false Si el contrato no está activo
 */
bool Contrato::estaActivo ( ) const
{
   return _activo;
}


/**
 * Cambia la cuenta bancaria asociada al contrato
 * @param cuentaBancaria Nueva cuenta bancaria (formato IBAN)
 * @post El contrato tiene una nueva cuenta de domiciliación
 * @return Una referencia al propio contrato
 * @throw PooFusionExc Si se le pasa como parámetro una cadena vacía
 */
Contrato& Contrato::setCuentaBancaria ( std::string cuentaBancaria )
{
   if ( cuentaBancaria == "" )
   {
      throw PooFusionExc ( "Contrato.cpp", "Contrato::setCuentaBancaria"
                        , "El contrato tiene que tener cuenta bancaria" );
   }

   this->_cuentaBancaria = cuentaBancaria;

   return *this;
}


/**
 * Consulta la cuenta bancaria asociada al contrato
 * @return La cuenta bancaria asociada al contrato (formato IBAN)
 */
std::string Contrato::getCuentaBancaria ( ) const
{
   return _cuentaBancaria;
}


/**
 * Cambia los meses de permanencia del contrato
 * @param mesesPermanencia Número de meses
 * @post La permanencia del contrato cambia según el parámetro
 * @return Una referencia al propio contrato
 * @throw PooFusionExc Si el número de meses es negativo
 */
Contrato& Contrato::setMesesPermanencia ( int mesesPermanencia )
{
   if ( mesesPermanencia < 0 )
   {
      throw PooFusionExc ( "Contrato.cpp", "Contrato::setMesesPermanencia"
                        , "El contrato no puede tener una permanencia negativa" );
   }

   this->_mesesPermanencia = mesesPermanencia;

   return *this;
}


/**
 * Consulta los meses de permanencia del contrato
 * @return Los meses de permanencia del contrato
 */
int Contrato::getMesesPermanencia ( ) const
{
   return _mesesPermanencia;
}

bool Contrato::tieneConexionInternet() const {
    return _conexionInternet;
}

