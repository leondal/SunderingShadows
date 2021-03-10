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
  Travelling on a lonely, errie forest road.
GRAYHAWK
  );
  set_exits((["north":"/d/dragon/forest/forest90",
               "south":"/d/dragon/forest/forest88"]));
}
