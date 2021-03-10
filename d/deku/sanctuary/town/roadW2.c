#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"roadW1",
      "west" : TOWN+"roadW3"
    ] ));
}
