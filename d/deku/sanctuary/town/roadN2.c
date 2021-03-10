#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "south" : TOWN+"roadN1"
    ] ));
}
