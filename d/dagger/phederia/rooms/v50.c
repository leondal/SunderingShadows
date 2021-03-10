#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Vineyard."
  );
  set_long(
  "Vineyard.\n"
  "  Tall latices support grape vines that continue far into the distance."
  "  The vines look diseased and the grapes that hang off them bloated and rotting as if abandoned and left to rot in the sun."
  "\n"
  );
  set_smell("default",
  "The foul oder of rotting grapes fills the air."
  );
  set_listen("default",
  "No sounds get through the dense vines from the outside."
  );
  set_items(([
  "grap vines":"They strech off into the distance and look saddly neglected and sickly.",
  "grape vines":"They strech off into the distance and look saddly neglected and sickly.",
  "vines":"They strech off into the distance and look saddly neglected and sickly.",
  "latices":"Tall wooden latices designed to hold tha large grapes that grow in the sandy soil here.",
  "ground":"Sandy soil perfect for growing grapes and not much else.",
  "grapes":"Off color and starting to stink.  They should of been harvested long ago.",
  ]));
  set_exits(([
  "north":ROOMS"v46.c",
  "east":ROOMS"v51.c",
  ]));
}
