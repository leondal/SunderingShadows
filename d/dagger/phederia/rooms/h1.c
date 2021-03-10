#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Path just before the hedge garden."
  );
  set_long(
  "Path just before the Hedge Garden.\n"
  "  Far beyond a mass of hedges you can see the walls and towers of a keep rise into the gloomy sky."
  "  The hedges looked like once a beautiful garden now choaked and overgrown with brambles that seem to quiver as you draw near."
  "  The sense of decay and rot hang heavy in the air as if something in it it poisoning the landscape."
  "\n"
  );
  set_smell("default",
  "You smell rotting vegitation."
  );
  set_listen("default",
  "The still dead air carries the faint sound of something screeching."
  );
  set_items(([
  "fortress":"A fortress is barely seen over the high walls of the hedges.   Once a beutiful rose colored quartz it looks now like granite with dried blood stains.",
  "hedges":"Once finely kept its now over grown and thick with thorny brambles.   They quiver when anything comes near almost reaching out for them.",
  "ground":"Once a cobbled path its now broken as the creeping roots from the hedges claw through it.",
  "ceiling":"You're outside.  Its called a sky.",
  "floor":"You're outside.   Its called the ground.",
  "sky":"A shadowy haze looms over the hedges.  Almost as if the world was trying to crush this damned place.",
  "brambles":"Thorny protrusions from the hedges seem withered and gray but seem to twitch as you draw close.",
  ]));
  set_exits(([
  "west":ROOMS"v20.c",
  "east":ROOMS"h4.c",
  ]));
}
