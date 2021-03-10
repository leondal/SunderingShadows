#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit BTUNNEL;


void create() {
  ::create();


  set_exits( ([ "north" : TUNNELS + "d_cauldron" ,
	          "southwest" : TUNNELS + "tun21",]) );
  set_door("door",TUNNELS+"d_cauldron","north",0); 

}

