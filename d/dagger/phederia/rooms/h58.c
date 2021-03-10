#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "%^BOLD%^%^BLACK%^In the Hedge Garden."
  );
  set_long(
  "%^BOLD%^%^BLACK%^In the Hedge Garden.\n"
 "%^RESET%^%^GREEN%^"
  "   You stand deep in the hedge gardens."
  "  Far beyond a mass of hedges you can see the walls and towers of a fortress rise into the gloomy sky."
  "  The hedges looked like once a beautiful garden now choaked and overgrown with brambles that seem to quiver as you draw near."
  "  The sense of decay and rot hang heavy in the air as if something in it was poisoning the landscape."
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
  "sky":"A greyness has cloaked the skies above you seeming to try to flatten this damned place.",
  "floor":"You're outside.   Its called the ground.",
  "brambles":"Thorny protrusions from the hedges seem withered and gray but seem to twitch as you draw close.",
  ]));
  set_exits(([
  "north":ROOMS"h57.c",
  "southeast":ROOMS"h59.c",
  ]));
}
void init(){
  ::init();
  do_random_encounters(({MON"ape.c"}),15,4);
}
