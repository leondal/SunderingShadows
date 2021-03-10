#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "northwest" : CPATH+"cpath14",
      "east" : CPATH+"cpath16",
   ]) );
}
