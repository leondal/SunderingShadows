#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path06", 
      "northwest" : PATH+"path08",
      "southwest" : PATH+"path09" 
   ]) );
}
