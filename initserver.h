#ifndef initserver_H
#define initserver_H
#include <CORBA.h>
#include <vector>
#include <corbainit.h>

class InitServer : public CorbaInit
{
    PortableServer::POAManager_var mgr;
public:
    CORBA::Object_var poaobj;   // Corba ссылка для POA manager
    PortableServer::POA_var poa;  // Corba ссылка для POA manager


    // Для масштабируемости системы необходимо распределять Объекты между серверами
    // Таким образом, Изначально будет один сервер, в дальнейшем он должен распределять нагрузку
    // между серверами потомками

public:
    InitServer() {}
    InitServer(int argc, char* argv[]);

    virtual ~InitServer();

void poaManagerActivate() { mgr->activate(); }
void destroy() { poa->destroy(TRUE, TRUE); }

};

#endif // initserver_H
