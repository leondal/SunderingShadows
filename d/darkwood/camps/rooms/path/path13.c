#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path11", 
      "northwest" : TOWN+"road01"
   ]) );
}
