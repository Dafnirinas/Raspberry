#include "corbainit.h"

CorbaInit::CorbaInit(int argc, char *argv[])
{
    int arcCorba = argc - 1;
        char** argCorba = argv + 1;
    std::cout << arcCorba;
    for ( int k(0); k < arcCorba; ++k) std::cout << argCorba[k];
    orb = CORBA::ORB_init(argc, argv); // Initialization ORB

    nsobj = orb->resolve_initial_references("NameService"); // NamingService
    assert (! CORBA::is_nil(nsobj));

    nc =  CosNaming::NamingContext::_narrow(nsobj);

     if (CORBA::is_nil(nc)) {
         std::cerr << "Can't access the WateringService" << std::endl;
         exit(1);
     }
}

CorbaInit::~CorbaInit() {

}
