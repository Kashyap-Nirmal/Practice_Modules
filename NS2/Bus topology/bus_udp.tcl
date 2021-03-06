set ns [new Simulator]
#define color for data flows
$ns color 1 Blue
$ns color 2 Red
 #open tracefiles
set tracefile1 [open bus_udp.tr w]
$ns trace-all $tracefile1
#open nam file
set namfile [open bus_udp.nam w]
$ns namtrace-all $namfile
#define the finish procedure
proc finish {} {
	global ns tracefile1 namfile
	$ns flush-trace
	close $tracefile1
	close $namfile
	exec nam bus_udp.nam &
	exit 0
	} 
#create six nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

#create links between the nodes
#$ns duplex-link $n0 $n0 2Mb 10ms RED
#$ns duplex-link $n1 $n0 2Mb 10ms RED
$ns simplex-link $n0 $n1 0.3Mb 10ms SFQ
$ns simplex-link $n1 $n0 0.3Mb 10ms SFQ
set lan [$ns newLan "$n1 $n2 $n3 $n4 $n5" 0.5Mb 20ms LL Queue/SFQ MAC/Csma/Ca Channel]

#Give node position
#$ns duplex-link-op $n0 $n0 orient right-down
#$ns duplex-link-op $n1 $n0 orient right-up
$ns simplex-link-op $n0 $n1 orient right
$ns simplex-link-op $n1 $n0 orient left

#set queue size of link(n0-n1) to 20
$ns queue-limit $n0 $n1 10

#Setup a UDP connection
set udp [new Agent/UDP]
$ns attach-agent $n3 $udp
set null [new Agent/Null]
$ns attach-agent $n4 $null
$ns connect $udp $null
$udp set fid_ 2
$udp set packet_size_ 1000

#Setup a CBR over UDP connection
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false

#scheduling the events
$ns at 0.1 "$cbr start"
$ns at 5.0 "$cbr stop"

 $ns at 5.5 "finish"
 $ns run
