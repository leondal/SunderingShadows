#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("indoors",1);
  set_short(
  "Bedroom loft."
  );
  set_long(
  "Bedroom loft.\n"
  "  This loft is above the fireplace below and against the far wall from the door that leads out."
  "  A large bed lays against the wall and clothes hang from the dresser and a broken wardrobe."
  "  Even the beds been ransacked, nothings been left alone."
  "\n"
  );
  set_smell("default",
  "A slight scent of mold hits you up here."
  );
  set_listen("default",
  "You can hear the hinges still from the door below."
  );
  set_items(([
  "bed":"This large bed looks like it slept the whole family that must of lived here.   At one time it was covered in a beuatiful quilt but now its in disaray with the stuffing pulled out when someone looked for valuables.",
  "dresser":"Poorly made but still servicable.  The dresser held only childrens clothes which are now scatered around the room.",
  "wardrobe":"One of the doors has been broken off as it was opened roughly.   Only the worthless clothes of the people who once lived here remain.",
  "clothes":"All worthless.   Once for the simple folk that lived and worked at this hamlet who had no real need for extravagance.",
  "walls":"Looks like the house was well made by many hands.",
  "floor":"Looks like the house was well made by many hands.",
  "ceiling":"Looks like the house was well made by many hands.",
  ]));
  set_exits(([
  "down":ROOMS"v59.c",
  ]));
}
