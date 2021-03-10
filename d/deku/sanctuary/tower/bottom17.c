#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "northwest" : TOWER+"bottom16",
      "southeast" : TOWER+"bottom18",
   ]) );
}