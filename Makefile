SRC=client.cpp\
corbainit.cpp\
eventchannelServer.cpp\
initserver.cpp\
main.cpp\
pullconsumer_impl.cpp\
pullsupplier_impl.cpp\
pushconsumer_impl.cpp\
pushsupplier_impl.cpp\
wateringsystem_impl.cpp\
Watering.cc

OBJS=client.o\
corbainit.o\
eventchannelServer.o\
initserver.o\
main.o\
pullconsumer_impl.o\
pullsupplier_impl.o\
pushconsumer_impl.o\
pushsupplier_impl.o\
wateringsystem_impl.o\
Watering.o

LIBS=-lmico2.3.13 \
-lmicoaux2.3.13 \
-lmicocoss2.3.13 \
-lmicoir2.3.13 \
-lserial \
-lpthread \
-ldl

wateringsystem: ${OBJS}
	/usr/local/bin/mico-c++ -g -o $@ $^ -L/usr/local/lib ${LIBS}

.cpp.o: 
	/usr/local/bin/mico-c++ -o $@ $< -c -g -I.

.cc.o:
	/usr/local/bin/mico-c++ -o $@ $< -c -g -I.
