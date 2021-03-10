
#include <std.h>
#include "../tunnel.h"

inherit HTUNNEL;

void create(){
  ::create();
  set_exits( ([ "north" : TUNNELS + "tun12" ,
	          "south" : TUNNELS + "tun10"]) );

 }
