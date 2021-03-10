#include <std.h>
#include "../../elfisland1.h"

inherit BPATH;

void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path14",
      "northwest" : PATH+"path16",
   ]) );
}
