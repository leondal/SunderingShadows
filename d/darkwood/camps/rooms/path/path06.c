#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_exits( ([ 
      "east" : PATH+"path05", 
      "west" : PATH+"path07" 
   ]) );
}
