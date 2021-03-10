#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
 "Kitchen"
  );
  set_long(
  "Kitchen.\n"
  "  This massive room once busteled with activity at nearly any hour of the day before the keep fell."
  "  Huge ovens and grills line the walls and a massive firepit is in the center of the room."
  "  Dirty utensils are strewn across the tables with knives being driven into the cutting boards."
  "  A great wooden door to the south has been hacked to splinters and you can see a great hall leading south, while to the west a passage leads off into a smaller dark room."
  "\n"
  );
  set_smell("default",
  "The stink of burning bread fills the room."
  );
  set_listen("default",
  "The fire in the pit crackles as it burns down the logs."
  );
  set_items(([
  "ovens":"Great stone ovens are blackened by the heat they once contained.  The fires have run down long ago and they're cold now, the current occupants not seeming to need them.",
  "firepit":"This is the only thing the current occupiers seem to use anymore.  A great iron rod hangs over it, empty for now.",
  "grills":"Great steel grills hang over the edges of stones and the firepit.  Food is crusted to them and you wonder if anyone could ever eat of them again.",
  "utensils":"Spoons, whisks and a myriad of other common kitchen items lay scattered about in disaray.",
  "knives":"Blakened warped knives lay dirty and rusting around the tables and driven into things.",
  "cutting boards":"You just dont want to know what scraps of flesh are still clinging to them.",
  ]));
  set_exits(([
  "west":KEEP"k26.c",
  "south":KEEP"k34.c",
  ]));
}
