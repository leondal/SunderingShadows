#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create() {
  ::create();
  set_repop(50);
  set_monsters( ({ MON"derro1", MON"derro2"}), ({1,1}) );
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Great hallway%^RESET%^"  );
  set_long(
  "%^RED%^Great hallway %^RESET%^\n"
  "  This hall way is huge, spanning 25 feet across and high and stretching far into the distance, lit only with the red globes in the ceiling."
  );
  set_smell("default",  "The heat blasts you as currents of air swirl through the halls." );
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
  "northwest":ROOMS"c2",
  "southwest":ROOMS"c4",
  "east":ROOMS"c9",
  ]));
}

void reset(){ 
  ::reset();
/* changed to use CROOM since they wander)  *Styx*  11/27/02
  object mon;
  if(!present("derro warrior")){
  new(MON"derro1.c")->move(this_object());
  new(MON"derro2.c")->move(this_object());
  }
*/
}
