#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"roadW2",
      "west" : TOWN+"roadW4",
      "south" : TOWN+"magic"
    ] ));
}
