#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "west" : CPATH+"cpath15",
      "south" : CPATH+"cpath17",
   ]) );
}
