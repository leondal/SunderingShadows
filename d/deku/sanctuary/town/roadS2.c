#include <std.h>
#include "../dragon.h";

inherit ROAD;

void create() {
   ::create();
   set_exits(([
      "east" : TOWN+"hshop",
      "north" : TOWN+"roadS1",
       "south" : TOWN+"roadS3"
    ] ));
}
