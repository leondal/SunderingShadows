#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "northwest" : TEST + "tun16" ,
                "north" : TEST + "tun14"]) );

}
