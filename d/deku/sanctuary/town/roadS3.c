#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "exit" : PLAINS+"road35",
      "north" : TOWN+"roadS2",
      "west" : TOWN+"glazier",
    ] ));
}
