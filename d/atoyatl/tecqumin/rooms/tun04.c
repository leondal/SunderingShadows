#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "southwest" : ROOMS + "tun05" ,
                "north" : ROOMS + "tun03"]) );

}
