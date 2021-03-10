#include <std.h>

inherit ROOM;

void create()
{
  ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
//   set_short("The Torm Graveyard Road");
   set_short("Path to Torm");
  set_long(
@THORN
%^CYAN%^You stand at a crossroads on the road to Torm. To the south a dark
forest looms. To the north, lies the Dagger road and to the southeast
Torm's boardwalks can be seen from here.  Here, the forest seems to be
lurking about the road as it comes almost to the road and some attempts
to clear it away seem to have been left to overgrow again.  A simple 
stone path leads deeper amongst the trees...
THORN
  );
  set_smell("default", "%^GREEN%^You can smell the thick scent of the evergreens.");
  set_listen("default", "%^BOLD%^%^BLUE%^You can only hear the wind in the trees.");
  set_items(([
  "road" : "It looks lonely and rarely traveled, no human footprints can be seen.",
  "trees" : "Many pines and evergreen trees grow thickly all around you.",
  ]));
  set_exits(([
  "northwest":"/d/dagger/Torm/road/path2",
  "temple":"/d/magic/temples/lysara/lysara",
  "east":"/d/dagger/Torm/road/path6"
  ]));
}
