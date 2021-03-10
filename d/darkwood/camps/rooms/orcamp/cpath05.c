#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "east" : CPATH+"cpath06",
      "west" : CPATH+"cpath04",
   ]) );
}
