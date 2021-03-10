#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "southwest" : CPATH+"cpath17",
      "southeast" : CPATH+"cpath19",
   ]) );
}
