#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "east" : TEST + "tun08" ,
                "north" : TEST + "tun06"]) );

}
