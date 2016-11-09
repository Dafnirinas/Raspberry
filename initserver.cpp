#include "initserver.h"

InitServer::InitServer(int argc, char *argv[]):CorbaInit(argc,argv)
{
    poaobj = orb->resolve_initial_references("RootPOA"); // POA Manager
    poa = PortableServer::POA::_narrow(poaobj);
    mgr = poa->the_POAManager();
}

InitServer::~InitServer() {

}

/*
CORBA::Boolean InitServer::addPoint(char* id, char* kind)
{
    CosNaming::Name* nextPoint = new CosNaming::Name();
    (*nextPoint).length(1);
    (*nextPoint)[0].id = CORBA::string_dup(id);
    (*nextPoint)[0].kind = CORBA::string_dup(kind);

    nc->rebind(*nextPoint, ref);
//    NS.push_back(nextPoint);
    return true;
}*/

/*
CORBA::Boolean InitServer::addImplObject(WateringSystems_impl* waterSystems)
{
    oid = poa->activate_object(waterSystems);
    ref = poa->id_to_reference(oid.in());
}*/
