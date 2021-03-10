#include <std.h>
#include "../../elfisland1.h"

inherit BPATH;

void create() {
   ::create();
   set_exits( ([ 
      "southeast" : PATH+"path15",
      "west" : CPATH+"cpath20",
   ]) );
}
