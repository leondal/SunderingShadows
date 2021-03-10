#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "northwest" : PATH+"path03",
      "west" : PATH+"path05" 
   ]) );
}
