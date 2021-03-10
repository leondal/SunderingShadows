#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "east" : TOWER+"bottom14",
      "south" : TOWER+"bottom16",
   ]) );
}