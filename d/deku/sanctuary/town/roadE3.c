#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"roadE4",
      "north" : TOWN+"build2",
      "west" : TOWN+"roadE2",
    ] ));
}
