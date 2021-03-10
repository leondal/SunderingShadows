#include <std.h>
#include "../../elfisland1.h"

inherit BCAMP;
void create() {
   ::create();
   set_exits( ([ 
      "southwest" : CAMP"croad04", 
      "southeast" : CAMP+"croad05", 
      "north" : CPATH+"cpath01",
   ]) );
}
