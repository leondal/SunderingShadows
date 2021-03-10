#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"square",
      "north" : TOWN+"hotel",
      "west" : TOWN+"roadW2",
    ] ));
}
