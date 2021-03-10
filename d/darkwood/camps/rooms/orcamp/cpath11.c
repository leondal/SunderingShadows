#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_long(
      "%^RESET%^%^GREEN%^The tall lush grass reaches up all around you, but creates a little path"+
      " that heads into the forest that borders the beautiful meadows of this area. The oak trees before you stand very"+
      " tall and seem to part just a little for a tiny dirt trail that leads deeper into the forest."
   );
   set_exits( ([
      "northwest" : CPATH+"cpath10",
      "east" : MEADOW+"meadow15",
      "northeast" : MEADOW+"meadow14",
   ]) );
}
void reset(){
   ::reset();
    if(!present("sign"))
      new("/d/common/obj/areas/orcs_sign.c")->move(TO);
}
