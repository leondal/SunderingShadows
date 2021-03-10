#include <std.h>
#include "../../elfisland1.h"

inherit BPATH;

void create() {
   ::create();
   set_exits( ([ 
      "west" : PATH+"path15",
      "east" : TOWN+"road13",
   ]) );
}
