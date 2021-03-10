#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "southeast" : CPATH+"cpath11",
      "west" : CPATH+"cpath09",
   ]) );
}
