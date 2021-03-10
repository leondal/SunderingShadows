#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "east" : CPATH+"cpath05",
      "west" : CPATH+"cpath03",
   ]) );
}
