#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
  room::create();
  set_property("light", 1);
  set_property("no castle",1);
  set_short("Eastern Forest");
  set_long(
@GRAYHAWK
  You arrive at the edge of the dark forest and before you lies
   the monumental Gray Mountains.  Many tales have been written
  about the dangers and treasures that lay within the mountains.
   Many have traveled, only a few have survived. The forest road
  ends at the foot of these mountains.
GRAYHAWK
  );
  set_exits((["south":"/d/dragon/forest/forest89"]));
}
