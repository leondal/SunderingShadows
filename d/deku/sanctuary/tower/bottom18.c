#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "northwest" : TOWER+"bottom17",
      "southeast" : TOWER+"bottom19",
   ]) );
}