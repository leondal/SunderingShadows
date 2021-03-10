#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "southwest" : TEST + "tun05" ,
                "north" : TEST + "tun03"]) );

}
