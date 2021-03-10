#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short( "%^RED%^Great hallway%^RESET%^"  );
  set_long(  "%^RED%^Great hallway %^RESET%^\n"
  "  This hall way is huge, spanning 25 feet across and high and stretching far into the distance, lit only with the red globes in the ceiling."
  "  The hall continues to the west but a rockfall has blocked it."
  );
  set_smell("default", "The heat blasts you as currents of air swirl through the halls." );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor, almost making it seem as if you're in some great hall above ground rather than far below it.",
  "rockfall":"Looks recent and it looks complete.  There is no way without the effort of hundreds of arms could this massive amount of rock be moved.   The ceiling and walls are cracked and look unstable around the area as well so this endeavor would be dangerous and foolhardy.",
  ]));
  set_exits(([
  "southeast":ROOMS"c2",
  ]));
}
