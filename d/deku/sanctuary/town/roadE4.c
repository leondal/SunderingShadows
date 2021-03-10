#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
     // "exit" : FOREST+"forest01",
      "west" : TOWN+"roadE3",
    ] ));
}
      