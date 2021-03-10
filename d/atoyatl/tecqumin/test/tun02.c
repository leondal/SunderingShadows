#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "south" : TEST + "tun03" ,
                "north" : TEST + "tun01"]) );

}
