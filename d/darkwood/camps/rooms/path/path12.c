#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path10",
      "southwest" : TOWN+"road01"
   ]) );
}
