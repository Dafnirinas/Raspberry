#!/bin/bash
### BEGIN INIT INFO
# Provides:          wateringservice
# Required-Start:    $networking $setsrial $remote_fs $syslog
# Required-Stop:     $networking $setsrial $remote_fs $syslog
# Default-Start:     3 4 5
# Default-Stop:      0 1 2 6
# Short-Description: Watering flowers in your home
# Description:       This file should be used to construct scripts to be placed in /etc/init.d.
### END INIT INFO

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

SOURCECODEDIST=/home/pi/soft/MicoSer

ADDR=inet:`uname -n`:9001
#ADDR=inet:127.0.0.1:9001
IMPLPLUSNADDR="-ORBImplRepoAddr $ADDR -ORBNamingAddr $ADDR"

echo "Starting BOA demon..."
micod --forward -ORBIIOPAddr $ADDR &
micod_pid=$!

trap "kill $mico_pid" 0
sleep 2

echo "Register POA Manager in NameService..."
imr create WateringPOA poa `which nsd` \
IDL:omg.org/CosNaming/NamingContext:1.0#WateringPOA $IMPLPLUSNADDR &
POA_pid=$!

trap "kill $imr_pid" 0
sleep 2

echo "Register EventServiceFactory ..."
#imr create EventChannelFactory poa `which eventd` \
#IDL:omg.org/SimpleEventChannelAdmin/WateringChannelFactory:1.0 $IMPLPLUSNADDR &
#ChFactory_pid=$!

trap "kill $ChFactory_pid" 0
sleep 2

echo "Run EventService ..."
#eventd $IMPLPLUSNADDR &
eventd --regname EventChannelFactory &
eventd_pid=$!

trap "kill $eventd_pid" 0
sleep 4

echo "Run Server..."
echo 'set pagination off
set logging file debug_log.txt
set logging on
run > log.txt' > gdb_commands.txt
#sudo gdb -batch -x gdb_commands.txt wateringsystem $IMPLPLUSNADDR|tee debug_log.txt
echo ${SOURCECODEDIST}/wateringsystem $IMPLPLUSNADDR
${SOURCECODEDIST}/wateringsystem $IMPLPLUSNADDR
server_pid=$!
sleep 2
