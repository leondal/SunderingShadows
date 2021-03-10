#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"magic",
      "north" : TOWN+"roadW4",
      "south" : TOWN+"roadSW2"
    ] ));
}
