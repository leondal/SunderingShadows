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
  set_short(  "%^RED%^Naturally formed lava cavern"  );
  set_long(
  "%^RED%^Naturally formed lava cavern.%^RESET%^\n"
  "  This huge curving room looks like it's formed of black, shiny volcanic glass."
  "  The heat is intense and as the passage slopes down sharply to the northeast you can see the start of lava pools whos glow gives the room a hellish aspect."
  "  You can see the lone corpse of a firegiant slumped near the west wall just south of where it turns to the northeast."
  "\n"
  );
  set_smell("default",
  "You smell charred flesh and brimstone."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor is natural obsidian, volcanic glass that is arrayed in natural swirs and paterns that are pleasing to the eye although hard on the footwear.  Blood from the giants corpse pools in a hollow near it.",
  "corpse":"It is a massive fire giant.   One of the biggest of his kind and he's been terribly mutilated with what appears to be teethmarks and burns.",
  "lava pools":"They glitter, swirl and bubble.   The heat from the is tremendous",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"It curves over your head in almost a perfect semicircle.  It's all polished black volcanic glass.",
  ]));
  set_exits(([
  "south":ROOMS"c7",
  "northeast":ROOMS"c10",
  ]));
}
