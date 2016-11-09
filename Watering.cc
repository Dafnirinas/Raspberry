/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <Watering.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------

/*
 * Base interface for class WateringSystem
 */

WateringSystem::~WateringSystem()
{
}

void *
WateringSystem::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:WateringSystem:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

WateringSystem_ptr
WateringSystem::_narrow( CORBA::Object_ptr _obj )
{
  WateringSystem_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:WateringSystem:1.0" )))
      return _duplicate( (WateringSystem_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:WateringSystem:1.0") || _obj->_is_a_remote ("IDL:WateringSystem:1.0")) {
      _o = new WateringSystem_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

WateringSystem_ptr
WateringSystem::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_WateringSystem : public ::CORBA::StaticTypeInfo {
    typedef WateringSystem_ptr _MICO_T;
  public:
    ~_Marshaller_WateringSystem();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_WateringSystem::~_Marshaller_WateringSystem()
{
}

::CORBA::StaticValueType _Marshaller_WateringSystem::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_WateringSystem::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::WateringSystem::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_WateringSystem::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_WateringSystem::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_WateringSystem::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::WateringSystem::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_WateringSystem::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_WateringSystem;


/*
 * Stub interface for class WateringSystem
 */

WateringSystem_stub::~WateringSystem_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_WateringSystem::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:WateringSystem:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_WateringSystem *
POA_WateringSystem::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:WateringSystem:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_WateringSystem *) p;
  }
  return NULL;
}

WateringSystem_stub_clp::WateringSystem_stub_clp ()
{
}

WateringSystem_stub_clp::WateringSystem_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

WateringSystem_stub_clp::~WateringSystem_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean WateringSystem_stub::addSerialPort( const char* _par_name, CORBA::UShort _par_portNumber )
{
  CORBA::StaticAny _sa_name( CORBA::_stc_string, &_par_name );
  CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "addSerialPort" );
  __req.add_in_arg( &_sa_name );
  __req.add_in_arg( &_sa_portNumber );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
WateringSystem_stub_clp::addSerialPort( const char* _par_name, CORBA::UShort _par_portNumber )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->addSerialPort(_par_name, _par_portNumber);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::addSerialPort(_par_name, _par_portNumber);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean WateringSystem_stub::createEventChannel( const char* _par_id, const char* _par_kind )
{
  CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id );
  CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "createEventChannel" );
  __req.add_in_arg( &_sa_id );
  __req.add_in_arg( &_sa_kind );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
WateringSystem_stub_clp::createEventChannel( const char* _par_id, const char* _par_kind )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->createEventChannel(_par_id, _par_kind);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::createEventChannel(_par_id, _par_kind);
}

#endif // MICO_CONF_NO_POA

char* WateringSystem_stub::getEventChannelFactoryId()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getEventChannelFactoryId" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
WateringSystem_stub_clp::getEventChannelFactoryId()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getEventChannelFactoryId();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::getEventChannelFactoryId();
}

#endif // MICO_CONF_NO_POA

char* WateringSystem_stub::getEventChannelFactoryKind()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getEventChannelFactoryKind" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
WateringSystem_stub_clp::getEventChannelFactoryKind()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getEventChannelFactoryKind();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::getEventChannelFactoryKind();
}

#endif // MICO_CONF_NO_POA

char* WateringSystem_stub::getEventChannels()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getEventChannels" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
WateringSystem_stub_clp::getEventChannels()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getEventChannels();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::getEventChannels();
}

#endif // MICO_CONF_NO_POA

char* WateringSystem_stub::getDevices()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getDevices" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
WateringSystem_stub_clp::getDevices()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getDevices();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::getDevices();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean WateringSystem_stub::addPoint( const char* _par_id, const char* _par_kind )
{
  CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id );
  CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "addPoint" );
  __req.add_in_arg( &_sa_id );
  __req.add_in_arg( &_sa_kind );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
WateringSystem_stub_clp::addPoint( const char* _par_id, const char* _par_kind )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->addPoint(_par_id, _par_kind);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::addPoint(_par_id, _par_kind);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::addDevice( const char* _par_id, const char* _par_kind, CORBA::UShort _par_pin, CORBA::UShort _par_type, CORBA::UShort _par_serialPort )
{
  CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id );
  CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind );
  CORBA::StaticAny _sa_pin( CORBA::_stc_ushort, &_par_pin );
  CORBA::StaticAny _sa_type( CORBA::_stc_ushort, &_par_type );
  CORBA::StaticAny _sa_serialPort( CORBA::_stc_ushort, &_par_serialPort );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "addDevice" );
  __req.add_in_arg( &_sa_id );
  __req.add_in_arg( &_sa_kind );
  __req.add_in_arg( &_sa_pin );
  __req.add_in_arg( &_sa_type );
  __req.add_in_arg( &_sa_serialPort );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::addDevice( const char* _par_id, const char* _par_kind, CORBA::UShort _par_pin, CORBA::UShort _par_type, CORBA::UShort _par_serialPort )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->addDevice(_par_id, _par_kind, _par_pin, _par_type, _par_serialPort);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::addDevice(_par_id, _par_kind, _par_pin, _par_type, _par_serialPort);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::deleteDevice( const char* _par_id )
{
  CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "deleteDevice" );
  __req.add_in_arg( &_sa_id );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::deleteDevice( const char* _par_id )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->deleteDevice(_par_id);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::deleteDevice(_par_id);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::connectToChannelStrategy( const char* _par_devId, const char* _par_devKind, const char* _par_chanId, const char* _par_chanKind, CORBA::UShort _par_role )
{
  CORBA::StaticAny _sa_devId( CORBA::_stc_string, &_par_devId );
  CORBA::StaticAny _sa_devKind( CORBA::_stc_string, &_par_devKind );
  CORBA::StaticAny _sa_chanId( CORBA::_stc_string, &_par_chanId );
  CORBA::StaticAny _sa_chanKind( CORBA::_stc_string, &_par_chanKind );
  CORBA::StaticAny _sa_role( CORBA::_stc_ushort, &_par_role );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "connectToChannelStrategy" );
  __req.add_in_arg( &_sa_devId );
  __req.add_in_arg( &_sa_devKind );
  __req.add_in_arg( &_sa_chanId );
  __req.add_in_arg( &_sa_chanKind );
  __req.add_in_arg( &_sa_role );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::connectToChannelStrategy( const char* _par_devId, const char* _par_devKind, const char* _par_chanId, const char* _par_chanKind, CORBA::UShort _par_role )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->connectToChannelStrategy(_par_devId, _par_devKind, _par_chanId, _par_chanKind, _par_role);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::connectToChannelStrategy(_par_devId, _par_devKind, _par_chanId, _par_chanKind, _par_role);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::sendMsgByStrOnPort( const char* _par_str, CORBA::UShort _par_portNumber )
{
  CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str );
  CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "sendMsgByStrOnPort" );
  __req.add_in_arg( &_sa_str );
  __req.add_in_arg( &_sa_portNumber );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::sendMsgByStrOnPort( const char* _par_str, CORBA::UShort _par_portNumber )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendMsgByStrOnPort(_par_str, _par_portNumber);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::sendMsgByStrOnPort(_par_str, _par_portNumber);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::sendMsgForStatusRequestByName( const char* _par_str )
{
  CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "sendMsgForStatusRequestByName" );
  __req.add_in_arg( &_sa_str );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::sendMsgForStatusRequestByName( const char* _par_str )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendMsgForStatusRequestByName(_par_str);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::sendMsgForStatusRequestByName(_par_str);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::sendMsgForSetParameterByName( const char* _par_str, CORBA::UShort _par_par )
{
  CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str );
  CORBA::StaticAny _sa_par( CORBA::_stc_ushort, &_par_par );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "sendMsgForSetParameterByName" );
  __req.add_in_arg( &_sa_str );
  __req.add_in_arg( &_sa_par );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::sendMsgForSetParameterByName( const char* _par_str, CORBA::UShort _par_par )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendMsgForSetParameterByName(_par_str, _par_par);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::sendMsgForSetParameterByName(_par_str, _par_par);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::sendMsgForAllStatusOnPort( CORBA::UShort _par_portNumber )
{
  CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "sendMsgForAllStatusOnPort" );
  __req.add_in_arg( &_sa_portNumber );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::sendMsgForAllStatusOnPort( CORBA::UShort _par_portNumber )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendMsgForAllStatusOnPort(_par_portNumber);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::sendMsgForAllStatusOnPort(_par_portNumber);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::sendMsgLoadDeviceConfigOnPort( CORBA::UShort _par_portNumber )
{
  CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "sendMsgLoadDeviceConfigOnPort" );
  __req.add_in_arg( &_sa_portNumber );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::sendMsgLoadDeviceConfigOnPort( CORBA::UShort _par_portNumber )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendMsgLoadDeviceConfigOnPort(_par_portNumber);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::sendMsgLoadDeviceConfigOnPort(_par_portNumber);
}

#endif // MICO_CONF_NO_POA

CORBA::Any* WateringSystem_stub::sendMsgForSaveDeviceConfigOnPort( CORBA::UShort _par_portNumber )
{
  CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );
  CORBA::StaticAny __res( CORBA::_stc_any );

  CORBA::StaticRequest __req( this, "sendMsgForSaveDeviceConfigOnPort" );
  __req.add_in_arg( &_sa_portNumber );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (CORBA::Any*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

CORBA::Any*
WateringSystem_stub_clp::sendMsgForSaveDeviceConfigOnPort( CORBA::UShort _par_portNumber )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      CORBA::Any* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendMsgForSaveDeviceConfigOnPort(_par_portNumber);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystem_stub::sendMsgForSaveDeviceConfigOnPort(_par_portNumber);
}

#endif // MICO_CONF_NO_POA

void WateringSystem_stub::poaManagerActivate()
{
  CORBA::StaticRequest __req( this, "poaManagerActivate" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
WateringSystem_stub_clp::poaManagerActivate()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->poaManagerActivate();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  WateringSystem_stub::poaManagerActivate();
}

#endif // MICO_CONF_NO_POA

void WateringSystem_stub::ORBRun()
{
  CORBA::StaticRequest __req( this, "ORBRun" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
WateringSystem_stub_clp::ORBRun()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->ORBRun();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  WateringSystem_stub::ORBRun();
}

#endif // MICO_CONF_NO_POA

void WateringSystem_stub::POADestroy()
{
  CORBA::StaticRequest __req( this, "POADestroy" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
WateringSystem_stub_clp::POADestroy()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystem * _myserv = POA_WateringSystem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->POADestroy();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  WateringSystem_stub::POADestroy();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class WateringSystems
 */

WateringSystems::~WateringSystems()
{
}

void *
WateringSystems::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:WateringSystems:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

WateringSystems_ptr
WateringSystems::_narrow( CORBA::Object_ptr _obj )
{
  WateringSystems_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:WateringSystems:1.0" )))
      return _duplicate( (WateringSystems_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:WateringSystems:1.0") || _obj->_is_a_remote ("IDL:WateringSystems:1.0")) {
      _o = new WateringSystems_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

WateringSystems_ptr
WateringSystems::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_WateringSystems : public ::CORBA::StaticTypeInfo {
    typedef WateringSystems_ptr _MICO_T;
  public:
    ~_Marshaller_WateringSystems();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_WateringSystems::~_Marshaller_WateringSystems()
{
}

::CORBA::StaticValueType _Marshaller_WateringSystems::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_WateringSystems::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::WateringSystems::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_WateringSystems::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_WateringSystems::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_WateringSystems::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::WateringSystems::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_WateringSystems::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_WateringSystems;


/*
 * Stub interface for class WateringSystems
 */

WateringSystems_stub::~WateringSystems_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_WateringSystems::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:WateringSystems:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_WateringSystems *
POA_WateringSystems::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:WateringSystems:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_WateringSystems *) p;
  }
  return NULL;
}

WateringSystems_stub_clp::WateringSystems_stub_clp ()
{
}

WateringSystems_stub_clp::WateringSystems_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

WateringSystems_stub_clp::~WateringSystems_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean WateringSystems_stub::create( const char* _par_wsName )
{
  CORBA::StaticAny _sa_wsName( CORBA::_stc_string, &_par_wsName );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "create" );
  __req.add_in_arg( &_sa_wsName );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
WateringSystems_stub_clp::create( const char* _par_wsName )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystems * _myserv = POA_WateringSystems::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->create(_par_wsName);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystems_stub::create(_par_wsName);
}

#endif // MICO_CONF_NO_POA

char* WateringSystems_stub::getFlowerStates()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getFlowerStates" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
WateringSystems_stub_clp::getFlowerStates()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystems * _myserv = POA_WateringSystems::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getFlowerStates();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystems_stub::getFlowerStates();
}

#endif // MICO_CONF_NO_POA

char* WateringSystems_stub::getWaterLvls()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getWaterLvls" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
WateringSystems_stub_clp::getWaterLvls()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_WateringSystems * _myserv = POA_WateringSystems::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getWaterLvls();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return WateringSystems_stub::getWaterLvls();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class Device
 */

Device::~Device()
{
}

void *
Device::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:Device:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

Device_ptr
Device::_narrow( CORBA::Object_ptr _obj )
{
  Device_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:Device:1.0" )))
      return _duplicate( (Device_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:Device:1.0") || _obj->_is_a_remote ("IDL:Device:1.0")) {
      _o = new Device_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

Device_ptr
Device::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_Device : public ::CORBA::StaticTypeInfo {
    typedef Device_ptr _MICO_T;
  public:
    ~_Marshaller_Device();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_Device::~_Marshaller_Device()
{
}

::CORBA::StaticValueType _Marshaller_Device::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_Device::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::Device::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_Device::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_Device::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_Device::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::Device::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_Device::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_Device;


/*
 * Stub interface for class Device
 */

Device_stub::~Device_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_Device::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:Device:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_Device *
POA_Device::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:Device:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_Device *) p;
  }
  return NULL;
}

Device_stub_clp::Device_stub_clp ()
{
}

Device_stub_clp::Device_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

Device_stub_clp::~Device_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

char* Device_stub::sendMessageByStr( const char* _par_str )
{
  CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str );
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "sendMessageByStr" );
  __req.add_in_arg( &_sa_str );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
Device_stub_clp::sendMessageByStr( const char* _par_str )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_Device * _myserv = POA_Device::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendMessageByStr(_par_str);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return Device_stub::sendMessageByStr(_par_str);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean Device_stub::addDevice( const char* _par_id, const char* _par_kind )
{
  CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id );
  CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "addDevice" );
  __req.add_in_arg( &_sa_id );
  __req.add_in_arg( &_sa_kind );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
Device_stub_clp::addDevice( const char* _par_id, const char* _par_kind )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_Device * _myserv = POA_Device::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->addDevice(_par_id, _par_kind);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return Device_stub::addDevice(_par_id, _par_kind);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean Device_stub::deleteDevice( const char* _par_id, const char* _par_kind )
{
  CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id );
  CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "deleteDevice" );
  __req.add_in_arg( &_sa_id );
  __req.add_in_arg( &_sa_kind );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
Device_stub_clp::deleteDevice( const char* _par_id, const char* _par_kind )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_Device * _myserv = POA_Device::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->deleteDevice(_par_id, _par_kind);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return Device_stub::deleteDevice(_par_id, _par_kind);
}

#endif // MICO_CONF_NO_POA

char* Device_stub::sendLineForStatusRequest()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "sendLineForStatusRequest" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
Device_stub_clp::sendLineForStatusRequest()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_Device * _myserv = POA_Device::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->sendLineForStatusRequest();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return Device_stub::sendLineForStatusRequest();
}

#endif // MICO_CONF_NO_POA

struct __tc_init_WATERING {
  __tc_init_WATERING()
  {
    _marshaller_WateringSystem = new _Marshaller_WateringSystem;
    _marshaller_WateringSystems = new _Marshaller_WateringSystems;
    _marshaller_Device = new _Marshaller_Device;
  }

  ~__tc_init_WATERING()
  {
    delete static_cast<_Marshaller_WateringSystem*>(_marshaller_WateringSystem);
    delete static_cast<_Marshaller_WateringSystems*>(_marshaller_WateringSystems);
    delete static_cast<_Marshaller_Device*>(_marshaller_Device);
  }
};

static __tc_init_WATERING __init_WATERING;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface WateringSystem
POA_WateringSystem::~POA_WateringSystem()
{
}

::WateringSystem_ptr
POA_WateringSystem::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::WateringSystem::_narrow (obj);
}

CORBA::Boolean
POA_WateringSystem::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:WateringSystem:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_WateringSystem::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:WateringSystem:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_WateringSystem::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:WateringSystem:1.0");
}

CORBA::Object_ptr
POA_WateringSystem::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::WateringSystem_stub_clp (poa, obj);
}

bool
POA_WateringSystem::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 29)) {
    case 1:
      if( strcmp( __req->op_name(), "deleteDevice" ) == 0 ) {
        CORBA::String_var _par_id;
        CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id._for_demarshal() );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_id );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = deleteDevice( _par_id.inout() );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 6:
      if( strcmp( __req->op_name(), "createEventChannel" ) == 0 ) {
        CORBA::String_var _par_id;
        CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id._for_demarshal() );
        CORBA::String_var _par_kind;
        CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind._for_demarshal() );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_id );
        __req->add_in_arg( &_sa_kind );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = createEventChannel( _par_id.inout(), _par_kind.inout() );
        __req->write_results();
        return true;
      }
      break;
    case 7:
      if( strcmp( __req->op_name(), "sendMsgLoadDeviceConfigOnPort" ) == 0 ) {
        CORBA::UShort _par_portNumber;
        CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_portNumber );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendMsgLoadDeviceConfigOnPort( _par_portNumber );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 9:
      if( strcmp( __req->op_name(), "connectToChannelStrategy" ) == 0 ) {
        CORBA::String_var _par_devId;
        CORBA::StaticAny _sa_devId( CORBA::_stc_string, &_par_devId._for_demarshal() );
        CORBA::String_var _par_devKind;
        CORBA::StaticAny _sa_devKind( CORBA::_stc_string, &_par_devKind._for_demarshal() );
        CORBA::String_var _par_chanId;
        CORBA::StaticAny _sa_chanId( CORBA::_stc_string, &_par_chanId._for_demarshal() );
        CORBA::String_var _par_chanKind;
        CORBA::StaticAny _sa_chanKind( CORBA::_stc_string, &_par_chanKind._for_demarshal() );
        CORBA::UShort _par_role;
        CORBA::StaticAny _sa_role( CORBA::_stc_ushort, &_par_role );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_devId );
        __req->add_in_arg( &_sa_devKind );
        __req->add_in_arg( &_sa_chanId );
        __req->add_in_arg( &_sa_chanKind );
        __req->add_in_arg( &_sa_role );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = connectToChannelStrategy( _par_devId.inout(), _par_devKind.inout(), _par_chanId.inout(), _par_chanKind.inout(), _par_role );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      if( strcmp( __req->op_name(), "sendMsgForAllStatusOnPort" ) == 0 ) {
        CORBA::UShort _par_portNumber;
        CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_portNumber );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendMsgForAllStatusOnPort( _par_portNumber );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 13:
      if( strcmp( __req->op_name(), "sendMsgByStrOnPort" ) == 0 ) {
        CORBA::String_var _par_str;
        CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str._for_demarshal() );
        CORBA::UShort _par_portNumber;
        CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_str );
        __req->add_in_arg( &_sa_portNumber );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendMsgByStrOnPort( _par_str.inout(), _par_portNumber );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 14:
      if( strcmp( __req->op_name(), "ORBRun" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        ORBRun();
        __req->write_results();
        return true;
      }
      break;
    case 15:
      if( strcmp( __req->op_name(), "getEventChannelFactoryKind" ) == 0 ) {
        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getEventChannelFactoryKind();
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      break;
    case 16:
      if( strcmp( __req->op_name(), "sendMsgForSetParameterByName" ) == 0 ) {
        CORBA::String_var _par_str;
        CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str._for_demarshal() );
        CORBA::UShort _par_par;
        CORBA::StaticAny _sa_par( CORBA::_stc_ushort, &_par_par );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_str );
        __req->add_in_arg( &_sa_par );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendMsgForSetParameterByName( _par_str.inout(), _par_par );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      if( strcmp( __req->op_name(), "sendMsgForSaveDeviceConfigOnPort" ) == 0 ) {
        CORBA::UShort _par_portNumber;
        CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_portNumber );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendMsgForSaveDeviceConfigOnPort( _par_portNumber );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 18:
      if( strcmp( __req->op_name(), "POADestroy" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        POADestroy();
        __req->write_results();
        return true;
      }
      break;
    case 19:
      if( strcmp( __req->op_name(), "addSerialPort" ) == 0 ) {
        CORBA::String_var _par_name;
        CORBA::StaticAny _sa_name( CORBA::_stc_string, &_par_name._for_demarshal() );
        CORBA::UShort _par_portNumber;
        CORBA::StaticAny _sa_portNumber( CORBA::_stc_ushort, &_par_portNumber );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_name );
        __req->add_in_arg( &_sa_portNumber );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = addSerialPort( _par_name.inout(), _par_portNumber );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "addDevice" ) == 0 ) {
        CORBA::String_var _par_id;
        CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id._for_demarshal() );
        CORBA::String_var _par_kind;
        CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind._for_demarshal() );
        CORBA::UShort _par_pin;
        CORBA::StaticAny _sa_pin( CORBA::_stc_ushort, &_par_pin );
        CORBA::UShort _par_type;
        CORBA::StaticAny _sa_type( CORBA::_stc_ushort, &_par_type );
        CORBA::UShort _par_serialPort;
        CORBA::StaticAny _sa_serialPort( CORBA::_stc_ushort, &_par_serialPort );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_id );
        __req->add_in_arg( &_sa_kind );
        __req->add_in_arg( &_sa_pin );
        __req->add_in_arg( &_sa_type );
        __req->add_in_arg( &_sa_serialPort );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = addDevice( _par_id.inout(), _par_kind.inout(), _par_pin, _par_type, _par_serialPort );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 21:
      if( strcmp( __req->op_name(), "getEventChannels" ) == 0 ) {
        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getEventChannels();
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      break;
    case 23:
      if( strcmp( __req->op_name(), "addPoint" ) == 0 ) {
        CORBA::String_var _par_id;
        CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id._for_demarshal() );
        CORBA::String_var _par_kind;
        CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind._for_demarshal() );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_id );
        __req->add_in_arg( &_sa_kind );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = addPoint( _par_id.inout(), _par_kind.inout() );
        __req->write_results();
        return true;
      }
      break;
    case 25:
      if( strcmp( __req->op_name(), "sendMsgForStatusRequestByName" ) == 0 ) {
        CORBA::String_var _par_str;
        CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str._for_demarshal() );

        CORBA::Any* _res;
        CORBA::StaticAny __res( CORBA::_stc_any );
        __req->add_in_arg( &_sa_str );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendMsgForStatusRequestByName( _par_str.inout() );
        __res.value( CORBA::_stc_any, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 28:
      if( strcmp( __req->op_name(), "getEventChannelFactoryId" ) == 0 ) {
        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getEventChannelFactoryId();
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "getDevices" ) == 0 ) {
        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getDevices();
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "poaManagerActivate" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        poaManagerActivate();
        __req->write_results();
        return true;
      }
      break;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_WateringSystem::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface WateringSystems
POA_WateringSystems::~POA_WateringSystems()
{
}

::WateringSystems_ptr
POA_WateringSystems::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::WateringSystems::_narrow (obj);
}

CORBA::Boolean
POA_WateringSystems::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:WateringSystems:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_WateringSystems::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:WateringSystems:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_WateringSystems::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:WateringSystems:1.0");
}

CORBA::Object_ptr
POA_WateringSystems::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::WateringSystems_stub_clp (poa, obj);
}

bool
POA_WateringSystems::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "create" ) == 0 ) {
      CORBA::String_var _par_wsName;
      CORBA::StaticAny _sa_wsName( CORBA::_stc_string, &_par_wsName._for_demarshal() );

      CORBA::Boolean _res;
      CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
      __req->add_in_arg( &_sa_wsName );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = create( _par_wsName.inout() );
      __req->write_results();
      return true;
    }
    if( strcmp( __req->op_name(), "getFlowerStates" ) == 0 ) {
      char* _res;
      CORBA::StaticAny __res( CORBA::_stc_string, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = getFlowerStates();
      __req->write_results();
      CORBA::string_free( _res );
      return true;
    }
    if( strcmp( __req->op_name(), "getWaterLvls" ) == 0 ) {
      char* _res;
      CORBA::StaticAny __res( CORBA::_stc_string, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = getWaterLvls();
      __req->write_results();
      CORBA::string_free( _res );
      return true;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_WateringSystems::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface Device
POA_Device::~POA_Device()
{
}

::Device_ptr
POA_Device::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::Device::_narrow (obj);
}

CORBA::Boolean
POA_Device::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:Device:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_Device::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:Device:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_Device::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:Device:1.0");
}

CORBA::Object_ptr
POA_Device::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::Device_stub_clp (poa, obj);
}

bool
POA_Device::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 7)) {
    case 3:
      if( strcmp( __req->op_name(), "deleteDevice" ) == 0 ) {
        CORBA::String_var _par_id;
        CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id._for_demarshal() );
        CORBA::String_var _par_kind;
        CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind._for_demarshal() );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_id );
        __req->add_in_arg( &_sa_kind );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = deleteDevice( _par_id.inout(), _par_kind.inout() );
        __req->write_results();
        return true;
      }
      break;
    case 5:
      if( strcmp( __req->op_name(), "sendLineForStatusRequest" ) == 0 ) {
        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendLineForStatusRequest();
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      break;
    case 6:
      if( strcmp( __req->op_name(), "sendMessageByStr" ) == 0 ) {
        CORBA::String_var _par_str;
        CORBA::StaticAny _sa_str( CORBA::_stc_string, &_par_str._for_demarshal() );

        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->add_in_arg( &_sa_str );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = sendMessageByStr( _par_str.inout() );
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "addDevice" ) == 0 ) {
        CORBA::String_var _par_id;
        CORBA::StaticAny _sa_id( CORBA::_stc_string, &_par_id._for_demarshal() );
        CORBA::String_var _par_kind;
        CORBA::StaticAny _sa_kind( CORBA::_stc_string, &_par_kind._for_demarshal() );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_id );
        __req->add_in_arg( &_sa_kind );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = addDevice( _par_id.inout(), _par_kind.inout() );
        __req->write_results();
        return true;
      }
      break;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_Device::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

