#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({ MON"derro1", MON"derro2" }), ({1, 1}) );
  ::create();
  set_repop(60);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Great hallway%^RESET%^"  );
  set_long(
  "%^RED%^Great hallway %^RESET%^\n"
  "  This hall way is huge, spanning 25 feet across and high and stretching far into the distance, lit only with the red globes in the ceiling."
  "\n"
  );
  set_smell("default",  "The heat blasts you as currents of air swirl through the halls."  );
  set_listen("default",
  "A warm breeze from the west murmurs softly as it passes this hall."
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"c19",
  "west":ROOMS"c13",
  ]));
}
void reset(){
  ::reset();
/* changing to use CROOM for control over longer reboots *Styx*  11/28/02
  if(!present("derro warrior")){
  new(MON"derro1.c")->move(this_object());
  new(MON"derro2.c")->move(this_object());
  }
*/
}
