
#include <std.h>
#include "../tunnel.h"

inherit MTUNNEL;

void create(){
  ::create();
  set_exits( ([ "northwest" : TUNNELS + "tun13" ,
	          "south" : TUNNELS + "tun11"]) );

 }
