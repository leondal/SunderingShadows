#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path04", 
      "west" : PATH+"path06" 
   ]) );
}
