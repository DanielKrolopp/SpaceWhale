#! /bin/bash

PASS=$1
INPUT=$2
ITERS=$3
IP_START="192.168.100.101"
IP_MIDDLE="192.168.100.102"
IP_END="192.168.100.103"

echo "Copying executables to hosts..."
sshpass -p $PASS scp targets/start sw@$IP_START:~
sshpass -p $PASS scp targets/middle sw@$IP_MIDDLE:~
sshpass -p $PASS scp targets/end sw@$IP_END:~

echo "Booting pipeline..."
sshpass -p $PASS ssh sw@$IP_END "./end $ITERS" & 
sshpass -p $PASS ssh sw@$IP_MIDDLE "./middle $ITERS $IP_END" &
sshpass -p $PASS ssh sw@$IP_START "./start $ITERS $INPUT $IP_MIDDLE" &

