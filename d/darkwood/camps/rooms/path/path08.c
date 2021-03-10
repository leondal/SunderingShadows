#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "southeast" : PATH+"path07", 
      "west" : PATH+"path10" 
   ]) );
}
