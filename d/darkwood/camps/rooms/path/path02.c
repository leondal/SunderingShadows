#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "northwest" : PATH+"path01",
      "east" : PATH+"path03"
   ]) );
}
