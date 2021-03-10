#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "northeast" : TOWER+"bottom16",
      "northwest" : TOWER+"bottom21",
   ]) );
}