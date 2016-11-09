#ifndef PULLSUPPLIER_IMPL_H
#define PULLSUPPLIER_IMPL_H
#include <coss/CosEventComm.h>
#include <coss/CosNaming.h>

class PullSupplier_impl : virtual public POA_CosEventComm::PullSupplier
{
public:

    PullSupplier_impl();
    PullSupplier_impl(const char* devId, const char* devKind, const char* chanId, const char* chanKind, CosNaming::NamingContext_ptr nc);

    virtual CORBA::Any* pull();
    virtual CORBA::Any* try_pull( CORBA::Boolean_out has_event );
    virtual void disconnect_pull_supplier();
};

#endif // PULLSUPPLIER_IMPL_H
