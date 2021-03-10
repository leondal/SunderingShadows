#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"roadE3",
      "north" : TOWN+"stable",
      "west" : TOWN+"roadE1",
      "south" : TOWN+"build1"
    ] ));
}
