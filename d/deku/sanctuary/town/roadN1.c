#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"pub1",
      "north" : TOWN+"roadN2",
      "south" : TOWN+"square"
    ] ));
}
