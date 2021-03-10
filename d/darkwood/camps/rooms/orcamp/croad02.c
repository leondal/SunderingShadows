#include "../../elfisland1.h"
inherit BCAMP;
void create() {
   ::create();
   set_exits( ([ 
      "northeast" : CAMP+"croad05", 
      "northwest" : CAMP+"croad04", 
      "north" : CAMP+"croad03",
      "south" : CAMP+"croad01",
   ]) );
}
