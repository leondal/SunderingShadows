#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "southwest" : ROOMS + "tun14" ,
                "north" : ROOMS + "tun12"]) );

}
