BEGIN{
sent=0;
received=0;
drop++;
}
{
  if($1=="s")
   {
    sent++;
   }
  else if($1=="r")
   {
     received++;
   }
  else if($1=="d")
   {
     drop++;
   }	
}
END{
 printf " Packet Sent:%d",(received+drop);
 printf "\n Packet Received:%d",received;
 printf "\n Packet Delivery Ratio:%.2f\n",((received+drop)/received)*100;
 printf "\n Drop Packets:%d\n",drop;
	
}
