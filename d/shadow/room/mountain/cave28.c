//cave28.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(
      ""+TO->query_long()+"The tunnel splits here, with a second "+
      "passageway leading to the east while the main one continues "+
      "north and south.\n"
    );
    set_exits(([
        "south" : ROOMS"cave29",
        "east":   ROOMS"cave34",
        "north" : ROOMS"cave27"
   	]));
}
