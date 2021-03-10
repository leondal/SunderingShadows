#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "northwest" : TOWER+"bottom18",
      "southwest" : TOWER+"bottom23",
      "stairs" : TOWER+"prison01",
   ]) );
}