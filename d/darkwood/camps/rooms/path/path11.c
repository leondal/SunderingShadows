#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path09", 
      "west" : PATH+"path13" 
   ]) );
}
