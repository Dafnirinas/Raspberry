#!/bin/bash
### BEGIN INIT INFO
# Provides:          wateringservice
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Example initscript
# Description:       This file should be used to construct scripts to be
#                    placed in /etc/init.d.
### END INIT INFO

#ADDR=inet:'uname -n':9001
ADDR=inet:127.0.0.1:9001
IMPLPLUSNADDR="-ORBImplRepoAddr $ADDR -ORBNamingAddr $ADDR"

echo "Starting BOA demon..."
micod --forward -ORBIIOPAddr $ADDR &
micod_pid=$!

trap "kill $mico_pid" 0
sleep 2

echo "Register POA Manager in NameService..."
imr create NameServiceWatering poa 'which nsd' \
IDL:omg.org/CosNaming/NamingContext:1.0#WateringPOA $IMPLPLUSNADDR &
POA_pid=$!

trap "kill $imr_pid" 0
sleep 2

echo "Register EventServiceFactory ..."
imr create Event "'which eventd' $IMPLPLUSNADDR" \
IDL:omg.org/SimpleEventChannelAdmin/WateringChannelFactory:1.0 $IMPLPLUSNADDR &
ChFactory_pid=$!

trap "kill $ChFactory_pid" 0
sleep 2

echo "Run EventService ..."
eventd $IMPLPLUSNADDR &
eventd_pid=$!

trap "kill $eventd_pid" 0
sleep 4

echo "Run Server..."
./main.cpp $IMPLPLUSNADDR
server_pid=$!
sleep 2
