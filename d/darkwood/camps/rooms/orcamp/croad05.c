#include "../../elfisland1.h"
inherit BCAMP;
void create() {
   ::create();
   set_exits( ([ 
      "southwest" : CAMP"croad02", 
      "east" : CAMP+"tent04", 
      "northwest" : CAMP+"croad06",
   
   ]) );
}
