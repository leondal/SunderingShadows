
#include <std.h>
#include "../dragon.h";

inherit BBOTTOM;

void create() {
   ::create();
   set_exits( ([
      "west" : TOWER+"bottom12",
      "south" : TOWER+"bottom10",
   ]) );
}