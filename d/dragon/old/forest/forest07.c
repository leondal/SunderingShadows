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
   A small clearing breaks the monotony of the surrounding trees.
   The ground here looks well traveled and many roads extend
   into the encircling forest.  In the center of the clearing
  looking completely out of place of the surrounding landscape 
  is a large rock formation.
GRAYHAWK
  );
  set_exits((["east":"/d/dragon/forest/forest10",
              "west":"/d/dragon/forest/forest06",
               "north":"/d/dragon/forest/forest08"]));
}
