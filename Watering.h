/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __WATERING_H__
#define __WATERING_H__




class WateringSystem;
typedef WateringSystem *WateringSystem_ptr;
typedef WateringSystem_ptr WateringSystemRef;
typedef ObjVar< WateringSystem > WateringSystem_var;
typedef ObjOut< WateringSystem > WateringSystem_out;

class WateringSystems;
typedef WateringSystems *WateringSystems_ptr;
typedef WateringSystems_ptr WateringSystemsRef;
typedef ObjVar< WateringSystems > WateringSystems_var;
typedef ObjOut< WateringSystems > WateringSystems_out;

class Device;
typedef Device *Device_ptr;
typedef Device_ptr DeviceRef;
typedef ObjVar< Device > Device_var;
typedef ObjOut< Device > Device_out;




/*
 * Base class and common definitions for interface WateringSystem
 */

class WateringSystem : 
  virtual public CORBA::Object
{
  public:
    virtual ~WateringSystem();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef WateringSystem_ptr _ptr_type;
    typedef WateringSystem_var _var_type;
    #endif

    static WateringSystem_ptr _narrow( CORBA::Object_ptr obj );
    static WateringSystem_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static WateringSystem_ptr _duplicate( WateringSystem_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static WateringSystem_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean addSerialPort( const char* name, CORBA::UShort portNumber ) = 0;
    virtual CORBA::Boolean createEventChannel( const char* id, const char* kind ) = 0;
    virtual char* getEventChannelFactoryId() = 0;
    virtual char* getEventChannelFactoryKind() = 0;
    virtual char* getEventChannels() = 0;
    virtual char* getDevices() = 0;
    virtual CORBA::Boolean addPoint( const char* id, const char* kind ) = 0;
    virtual CORBA::Any* addDevice( const char* id, const char* kind, CORBA::UShort pin, CORBA::UShort type, CORBA::UShort serialPort ) = 0;
    virtual CORBA::Any* deleteDevice( const char* id ) = 0;
    virtual CORBA::Any* connectToChannelStrategy( const char* devId, const char* devKind, const char* chanId, const char* chanKind, CORBA::UShort role ) = 0;
    virtual CORBA::Any* sendMsgByStrOnPort( const char* str, CORBA::UShort portNumber ) = 0;
    virtual CORBA::Any* sendMsgForStatusRequestByName( const char* str ) = 0;
    virtual CORBA::Any* sendMsgForSetParameterByName( const char* str, CORBA::UShort par ) = 0;
    virtual CORBA::Any* sendMsgForAllStatusOnPort( CORBA::UShort portNumber ) = 0;
    virtual CORBA::Any* sendMsgLoadDeviceConfigOnPort( CORBA::UShort portNumber ) = 0;
    virtual CORBA::Any* sendMsgForSaveDeviceConfigOnPort( CORBA::UShort portNumber ) = 0;
    virtual void poaManagerActivate() = 0;
    virtual void ORBRun() = 0;
    virtual void POADestroy() = 0;

  protected:
    WateringSystem() {};
  private:
    WateringSystem( const WateringSystem& );
    void operator=( const WateringSystem& );
};

// Stub for interface WateringSystem
class WateringSystem_stub:
  virtual public WateringSystem
{
  public:
    virtual ~WateringSystem_stub();
    CORBA::Boolean addSerialPort( const char* name, CORBA::UShort portNumber );
    CORBA::Boolean createEventChannel( const char* id, const char* kind );
    char* getEventChannelFactoryId();
    char* getEventChannelFactoryKind();
    char* getEventChannels();
    char* getDevices();
    CORBA::Boolean addPoint( const char* id, const char* kind );
    CORBA::Any* addDevice( const char* id, const char* kind, CORBA::UShort pin, CORBA::UShort type, CORBA::UShort serialPort );
    CORBA::Any* deleteDevice( const char* id );
    CORBA::Any* connectToChannelStrategy( const char* devId, const char* devKind, const char* chanId, const char* chanKind, CORBA::UShort role );
    CORBA::Any* sendMsgByStrOnPort( const char* str, CORBA::UShort portNumber );
    CORBA::Any* sendMsgForStatusRequestByName( const char* str );
    CORBA::Any* sendMsgForSetParameterByName( const char* str, CORBA::UShort par );
    CORBA::Any* sendMsgForAllStatusOnPort( CORBA::UShort portNumber );
    CORBA::Any* sendMsgLoadDeviceConfigOnPort( CORBA::UShort portNumber );
    CORBA::Any* sendMsgForSaveDeviceConfigOnPort( CORBA::UShort portNumber );
    void poaManagerActivate();
    void ORBRun();
    void POADestroy();

  private:
    void operator=( const WateringSystem_stub& );
};

#ifndef MICO_CONF_NO_POA

class WateringSystem_stub_clp :
  virtual public WateringSystem_stub,
  virtual public PortableServer::StubBase
{
  public:
    WateringSystem_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~WateringSystem_stub_clp ();
    CORBA::Boolean addSerialPort( const char* name, CORBA::UShort portNumber );
    CORBA::Boolean createEventChannel( const char* id, const char* kind );
    char* getEventChannelFactoryId();
    char* getEventChannelFactoryKind();
    char* getEventChannels();
    char* getDevices();
    CORBA::Boolean addPoint( const char* id, const char* kind );
    CORBA::Any* addDevice( const char* id, const char* kind, CORBA::UShort pin, CORBA::UShort type, CORBA::UShort serialPort );
    CORBA::Any* deleteDevice( const char* id );
    CORBA::Any* connectToChannelStrategy( const char* devId, const char* devKind, const char* chanId, const char* chanKind, CORBA::UShort role );
    CORBA::Any* sendMsgByStrOnPort( const char* str, CORBA::UShort portNumber );
    CORBA::Any* sendMsgForStatusRequestByName( const char* str );
    CORBA::Any* sendMsgForSetParameterByName( const char* str, CORBA::UShort par );
    CORBA::Any* sendMsgForAllStatusOnPort( CORBA::UShort portNumber );
    CORBA::Any* sendMsgLoadDeviceConfigOnPort( CORBA::UShort portNumber );
    CORBA::Any* sendMsgForSaveDeviceConfigOnPort( CORBA::UShort portNumber );
    void poaManagerActivate();
    void ORBRun();
    void POADestroy();

  protected:
    WateringSystem_stub_clp ();
  private:
    void operator=( const WateringSystem_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface WateringSystems
 */

class WateringSystems : 
  virtual public CORBA::Object
{
  public:
    virtual ~WateringSystems();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef WateringSystems_ptr _ptr_type;
    typedef WateringSystems_var _var_type;
    #endif

    static WateringSystems_ptr _narrow( CORBA::Object_ptr obj );
    static WateringSystems_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static WateringSystems_ptr _duplicate( WateringSystems_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static WateringSystems_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean create( const char* wsName ) = 0;
    virtual char* getFlowerStates() = 0;
    virtual char* getWaterLvls() = 0;

  protected:
    WateringSystems() {};
  private:
    WateringSystems( const WateringSystems& );
    void operator=( const WateringSystems& );
};

// Stub for interface WateringSystems
class WateringSystems_stub:
  virtual public WateringSystems
{
  public:
    virtual ~WateringSystems_stub();
    CORBA::Boolean create( const char* wsName );
    char* getFlowerStates();
    char* getWaterLvls();

  private:
    void operator=( const WateringSystems_stub& );
};

#ifndef MICO_CONF_NO_POA

class WateringSystems_stub_clp :
  virtual public WateringSystems_stub,
  virtual public PortableServer::StubBase
{
  public:
    WateringSystems_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~WateringSystems_stub_clp ();
    CORBA::Boolean create( const char* wsName );
    char* getFlowerStates();
    char* getWaterLvls();

  protected:
    WateringSystems_stub_clp ();
  private:
    void operator=( const WateringSystems_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface Device
 */

class Device : 
  virtual public CORBA::Object
{
  public:
    virtual ~Device();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef Device_ptr _ptr_type;
    typedef Device_var _var_type;
    #endif

    static Device_ptr _narrow( CORBA::Object_ptr obj );
    static Device_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static Device_ptr _duplicate( Device_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static Device_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* sendMessageByStr( const char* str ) = 0;
    virtual CORBA::Boolean addDevice( const char* id, const char* kind ) = 0;
    virtual CORBA::Boolean deleteDevice( const char* id, const char* kind ) = 0;
    virtual char* sendLineForStatusRequest() = 0;

  protected:
    Device() {};
  private:
    Device( const Device& );
    void operator=( const Device& );
};

// Stub for interface Device
class Device_stub:
  virtual public Device
{
  public:
    virtual ~Device_stub();
    char* sendMessageByStr( const char* str );
    CORBA::Boolean addDevice( const char* id, const char* kind );
    CORBA::Boolean deleteDevice( const char* id, const char* kind );
    char* sendLineForStatusRequest();

  private:
    void operator=( const Device_stub& );
};

#ifndef MICO_CONF_NO_POA

class Device_stub_clp :
  virtual public Device_stub,
  virtual public PortableServer::StubBase
{
  public:
    Device_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~Device_stub_clp ();
    char* sendMessageByStr( const char* str );
    CORBA::Boolean addDevice( const char* id, const char* kind );
    CORBA::Boolean deleteDevice( const char* id, const char* kind );
    char* sendLineForStatusRequest();

  protected:
    Device_stub_clp ();
  private:
    void operator=( const Device_stub_clp & );
};

#endif // MICO_CONF_NO_POA

#ifndef MICO_CONF_NO_POA

class POA_WateringSystem : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~POA_WateringSystem ();
    WateringSystem_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static POA_WateringSystem * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual CORBA::Boolean addSerialPort( const char* name, CORBA::UShort portNumber ) = 0;
    virtual CORBA::Boolean createEventChannel( const char* id, const char* kind ) = 0;
    virtual char* getEventChannelFactoryId() = 0;
    virtual char* getEventChannelFactoryKind() = 0;
    virtual char* getEventChannels() = 0;
    virtual char* getDevices() = 0;
    virtual CORBA::Boolean addPoint( const char* id, const char* kind ) = 0;
    virtual CORBA::Any* addDevice( const char* id, const char* kind, CORBA::UShort pin, CORBA::UShort type, CORBA::UShort serialPort ) = 0;
    virtual CORBA::Any* deleteDevice( const char* id ) = 0;
    virtual CORBA::Any* connectToChannelStrategy( const char* devId, const char* devKind, const char* chanId, const char* chanKind, CORBA::UShort role ) = 0;
    virtual CORBA::Any* sendMsgByStrOnPort( const char* str, CORBA::UShort portNumber ) = 0;
    virtual CORBA::Any* sendMsgForStatusRequestByName( const char* str ) = 0;
    virtual CORBA::Any* sendMsgForSetParameterByName( const char* str, CORBA::UShort par ) = 0;
    virtual CORBA::Any* sendMsgForAllStatusOnPort( CORBA::UShort portNumber ) = 0;
    virtual CORBA::Any* sendMsgLoadDeviceConfigOnPort( CORBA::UShort portNumber ) = 0;
    virtual CORBA::Any* sendMsgForSaveDeviceConfigOnPort( CORBA::UShort portNumber ) = 0;
    virtual void poaManagerActivate() = 0;
    virtual void ORBRun() = 0;
    virtual void POADestroy() = 0;

  protected:
    POA_WateringSystem () {};

  private:
    POA_WateringSystem (const POA_WateringSystem &);
    void operator= (const POA_WateringSystem &);
};

class POA_WateringSystems : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~POA_WateringSystems ();
    WateringSystems_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static POA_WateringSystems * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual CORBA::Boolean create( const char* wsName ) = 0;
    virtual char* getFlowerStates() = 0;
    virtual char* getWaterLvls() = 0;

  protected:
    POA_WateringSystems () {};

  private:
    POA_WateringSystems (const POA_WateringSystems &);
    void operator= (const POA_WateringSystems &);
};

class POA_Device : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~POA_Device ();
    Device_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static POA_Device * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual char* sendMessageByStr( const char* str ) = 0;
    virtual CORBA::Boolean addDevice( const char* id, const char* kind ) = 0;
    virtual CORBA::Boolean deleteDevice( const char* id, const char* kind ) = 0;
    virtual char* sendLineForStatusRequest() = 0;

  protected:
    POA_Device () {};

  private:
    POA_Device (const POA_Device &);
    void operator= (const POA_Device &);
};

#endif // MICO_CONF_NO_POA

extern CORBA::StaticTypeInfo *_marshaller_WateringSystem;

extern CORBA::StaticTypeInfo *_marshaller_WateringSystems;

extern CORBA::StaticTypeInfo *_marshaller_Device;

#endif
