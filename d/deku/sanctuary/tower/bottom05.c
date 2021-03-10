#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "north" : TOWER+"bottom06",
      "west" : TOWER+"bottom04",
   ]) );
}