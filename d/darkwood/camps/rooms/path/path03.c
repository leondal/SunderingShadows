#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "west" : PATH+"path02",
      "southeast" : PATH+"path04"
   ]) );
}
