#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "south" : "/d/shadow/room/mountain/cave26",
      "east" : TUNNEL+"tunnel02"
   ]) );
}
