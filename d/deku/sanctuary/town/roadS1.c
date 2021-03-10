#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"armorer",
      "north" : TOWN+"square",
      "west" : TOWN+"storage",
      "south" : TOWN+"roadS2"
    ] ));
}
      