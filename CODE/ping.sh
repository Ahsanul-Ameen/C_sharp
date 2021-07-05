gcc -w spoof_icmp.c -o icmp_ping_spoof
sudo ./icmp_ping_spoof "$1" "$2" "$3"
# source ip
# dest ip
# npackets
