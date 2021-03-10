#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path08", 
      "west" : PATH+"path12" 
   ]) );
}
