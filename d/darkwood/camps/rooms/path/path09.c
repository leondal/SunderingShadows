#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "northeast" : PATH+"path07", 
      "west" : PATH+"path11" 
   ]) );
}
