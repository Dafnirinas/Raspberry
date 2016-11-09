#ifndef PUSHSUPPLIER_IMPL_H
#define PUSHSUPPLIER_IMPL_H
#include <coss/CosEventComm.h>
#include <coss/CosNaming.h>

class PushSupplier_impl : virtual public POA_CosEventComm::PushSupplier
{
public:

    PushSupplier_impl();
    PushSupplier_impl(const char* devId, const char* devKind, const char* chanId, const char* chanKind, CosNaming::NamingContext_ptr nc);

    virtual void disconnect_push_supplier() {; }
};

#endif // PUSHSUPPLIER_IMPL_H
