#ifndef CORBAINIT_H
#define CORBAINIT_H
#include <coss/CosNaming.h>

class CorbaInit
{
public:
    CORBA::ORB_var orb; // ObjectRequestBroker
    CORBA::Object_var nsobj;    // Corba ссылка для Naming
        // Возможно преобразование в вектор для отделения NamingContext между RasberryPi
    CosNaming::NamingContext_var nc;  // NamingContext для Corba ссылки

    CorbaInit() {}
    CorbaInit(int argc, char *argv[]);

    CosNaming::NamingContext_ptr getNamingContext() { return nc._retn();}
    void run() { orb->run(); }

    virtual ~CorbaInit();

};

#endif // CORBAINIT_H
