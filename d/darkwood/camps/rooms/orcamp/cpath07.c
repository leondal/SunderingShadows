#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "north" : CPATH+"cpath06",
      "southeast" : CPATH+"cpath08",
   ]) );
}
