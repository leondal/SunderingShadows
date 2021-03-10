#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "south" : ROOMS + "tun07" ,
                "north" : ROOMS + "tun05"]) );

}
