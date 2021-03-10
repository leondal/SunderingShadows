#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"roadW3",
      "north" : TOWN+"church",
      "west" : TOWN+"roadW5",
      "south" : TOWN+"roadSW1"
    ] ));
}
