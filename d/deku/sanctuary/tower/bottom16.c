#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "north" : TOWER+"bottom15",
      "southwest" : TOWER+"bottom20",
      "southeast" : TOWER+"bottom17",
   ]) );
}