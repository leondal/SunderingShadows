#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "north" : CAMP+"croad01",
      "south" : CPATH+"cpath13",
   ]) );
}
