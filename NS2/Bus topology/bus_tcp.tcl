set ns [new Simulator]
#define color for data flows
$ns color 1 Blue
$ns color 2 Red

 #open tracefiles
set tracefile1 [open bus_tcp.tr w]
$ns trace-all $tracefile1
#open nam file
set namfile [open bus_tcp.nam w]
$ns namtrace-all $namfile
#define the finish procedure
proc finish {} {
	global ns tracefile1 namfile
	$ns flush-trace
	close $tracefile1
	close $namfile
	exec nam bus_tcp.nam &
	exit 0
	} 
#create six nodes
#set n0 [$ns node]
#set n1 [$ns node]
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

#create links between the nodes
#$ns duplex-link $n0 $n0 2Mb 10ms DropTail
#$ns duplex-link $n1 $n0 2Mb 10ms DropTail
$ns simplex-link $n0 $n1 0.3Mb 10ms DropTail
$ns simplex-link $n1 $n0 0.3Mb 10ms DropTail
set lan [$ns newLan "$n1 $n2 $n3 $n4 $n5" 0.5Mb 20ms LL Queue/DropTail MAC/Csma/Cd Channel]

#Give node position
#$ns duplex-link-op $n0 $n0 orient right-down
#$ns duplex-link-op $n1 $n0 orient right-up
$ns simplex-link-op $n0 $n1 orient right
$ns simplex-link-op $n1 $n0 orient left

#set queue size of link(n0-n1) to 10
$ns queue-limit $n0 $n1 10

#setup TCP connection
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set packet_size_ 1000

#set ftp over tcp connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp

#scheduling the events

$ns at 0.1 "$ftp start"
$ns at 5.0 "$ftp stop"

 $ns at 5.5 "finish"
 $ns run
