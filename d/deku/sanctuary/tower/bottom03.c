#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "east" : TOWER+"bottom04",
      "west" : TOWER+"bottom02",
   ]) );
}