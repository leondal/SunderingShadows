#include <std.h>
#include "../tormdefs.h"
inherit ROOM;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_short("South lighthouse walls");
  set_property("light",2);
  set_long(
  "On the walls leading to the south lighthouse.\n"
  "  The walls of Torm here begin to extend out into the Dagger Sea."
  "  South you can see the small huts of the fishermen on the rocky shores of the Dagger Sea, before the great sandy beachs start that lead off to the horizon."
  "  The Dagger Sea fills the skyline to the east and you can see the harbor stretch north of you, curving slighly to the east as it goes north to the far walls of the city."
  "  The docks and boardwalks can clearly be seen here with their ships and people doing business."
  "  Here the walls are thicker than the other places allowing a walkway atop them leading further east over onto the sea itself."
  );
  set("night long",
  "On the walls leading to the north lighthouse.\n"
  "A light fog has settled over most of the city at night, but it"+
  " doesn't reach up to the walls and from here you can see over the"+
  " rest of the city.  The walls of Torm begin to extend out into the"+
  " Dagger Sea here.  South you can see the small huts of the fishermen on the rocky"+
  " shores of the Dagger Sea, before the great sandy beaches start that lead off to the horizon."+
  "  The Dagger Sea fills the eastern sky line and it is covered in a thin layer of"+
  " low hanging fog until outside the rocky bay that Torm rests in."+
  "  The docks and boardwalks can be seen from here, but they are quiet and empty at night."+
  "  Here the walls are thicker than the other places allowing a walkway atop them leading further east over the sea itself."
  );
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","Far away the breakers pound on the docks.");
  set_items(([
  "harbor" : "The east side of Torm is open to the Dagger Sea, with many boardwalks and docks from the city going out into it.",
  "fog" : "A light fog has settled over the city of Torm, but it stays"+
  " close to the ground and you can see the tops of all the buildings"+
  " from here.",
  "walls" : "The walls are thicker here, made of sturdy stone blocks, but"+
  " they are a bit slick from the sea spray.",
  ({"huts","small huts"}) : "To the south you can see many small huts of the"+
  " fishermen who live there.",
  ({"sea","dagger sea","Dagger Sea"}) : "The Dagger Sea stretches out to the"+
  " horizon from here, a beautiful dark blue with white caps from crashing waves.",
  "harbor" : "The walls here stretch out over the sea itself, giving you a"+
  " better view of the busy harbor to the north. There are several ships"+
  " currently docked.",
  "docks" : "There are several ships docked at the harbor, waiting to do"+
  " business in Torm.",
  "boardwalks" : "The boardwalks extend over the edge of the sea around the"+
  " docks, they always seem to be busy with activity.",
  "ships" : "There are several ships docked at the harbor. They are large,"+
  " even though it's the Dagger Sea, it connects with the larger ocean and"+
  " most of the ships have traveled from more distance places.",
  ]));
  set_exits(([
  "west":TCITY+"c90",
  "east":TCITY+"c92",
  ]));
}
