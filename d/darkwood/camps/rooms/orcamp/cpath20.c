#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "northwest" : CPATH+"cpath19",
      "east" : PATH+"path16",
   ]) );
}
