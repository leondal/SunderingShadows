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
GRAYHAWK
  );
  set_exits((["south":"/d/dragon/forest/forest07",
               "north":"/d/dragon/forest/forest09"]));
}
