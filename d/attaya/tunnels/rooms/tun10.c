
#include <std.h>
#include "../tunnel.h"

inherit HTUNNEL;

void create(){
  ::create();
  set_exits( ([ "north" : TUNNELS + "tun11" ,
	          "southwest" : TUNNELS + "tun02"]) );

 }
