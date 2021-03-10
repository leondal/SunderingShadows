#include <std.h>
#include "../../elfisland1.h"

inherit BCAMP;
void create() {
   ::create();
   set_exits( ([ 
      "southeast" : CAMP+"tent02", 
      "west" : CAMP+"tent01", 
      "north" : CAMP+"croad02",
      "south" : CPATH+"cpath12"
   ]) );
}
