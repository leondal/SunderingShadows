#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("indoors",1);
  set_short(
  "Small house in the hamlet."
  );
  set_long(
  "Small house in the hamlet.\n"
  "  This small house is sparse but well built against the elements."
  "   A fireplace with mantle is in one corner with the basics of kitchen utensils."
  "   A ladder leads up to a loft where the masters bedroom is and a trapdoor leads down to the cellar."
  "  The house looks like a lot of love went into its construction and upkeep but now has been ransacked and abandoned."
  "\n"
  );
  set_smell("default",
  "Mold starts to grow in the corners where the rains has gotten in through the shattered shutters."
  );
  set_listen("default",
  "The door squeeks as the wind plays it back and forth on its broken hinges."
  );
  set_search("default","You find nothing but shattered crockery and debris.");
  set_search("fireplace","Its cold and lifeless.  No fires been here in awhile.");
  set_items(([
  "door":"Looks like it was kicked in.",
  "loft":"A second half story against the far wall from the door and above the fireplace, where the people who lived here slept.  A ladder leads up to it.",
  "shutters":"Broken with repeated banging against the walls by the wind.",
  "ceiling":"Looks like the house was well made by many hands.",
  "floor":"Looks like the house was well made by many hands.",
  "walls":"Looks like the house was well made by many hands.",
  "trapdoor":"open and leads down to a cellar under the house.",
  "ladder":"Leads up to a loft where the family must of slept.",
  "fireplace":"Its cold and hasnt been used in awhile.",
  "mantle":"Scattered fragments of old pottery and small knick knacks that were to worthless to be looted were smashed and left.",
  ]));
  set_exits(([
 "up":ROOMS"v57a.c",
  "down":ROOMS"v57b.c",
  "west":ROOMS"v8.c",
  ]));
}
