#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "west" : TEST + "tun20" ,
                "northeast" : TEST + "tun18"]) );

}
