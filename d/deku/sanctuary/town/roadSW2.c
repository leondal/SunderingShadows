#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"bank",
      "north" : TOWN+"roadSW1",
      "west" : TOWN+"wshop",
      "south" : TOWN+"mshop"
    ] ));
}
