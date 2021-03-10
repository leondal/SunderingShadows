#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "northwest" : ROOMS + "tun16" ,
                "north" : ROOMS + "tun14"]) );

}
