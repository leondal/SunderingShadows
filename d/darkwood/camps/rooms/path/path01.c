#include "../../elfisland1.h"
inherit BPATH;
void create() {
   ::create();
   set_long(
      "%^RESET%^%^GREEN%^The four foot grass all around you is starting to split open on a little path"+
      " that heads into the forest that borders this side of the grassy plains. The oak trees before you stand very"+
      " tall and seem to part just a little for a tiny dirt trail that leads deeper into the forest."
   );
   set_exits( ([ 
      "north" : MEADOW+"plains9",
      "southeast" : PATH+"path02"
   ]) );
}
