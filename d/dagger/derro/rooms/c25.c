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
  set_short(  "%^RED%^Prison cells.%^RESET%^"  );
  set_long(
  "%^RED%^Prison cells.%^RESET%^\n"
  "  This room is divided by stone halfwalls into alcoves that are filled with manacles and chains of all sizes.    Looks like everything from a dragon to a dwarf could have been imprisoned here."
  );
  set_smell("default", "You get the occasional whiff of the scent of decaying flesh." );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "west":ROOMS"c21",
  ]));
}
void reset(){
  ::reset();
  if(!present("captive")){
  new(MON"captive")->move(TO);
  }
}
