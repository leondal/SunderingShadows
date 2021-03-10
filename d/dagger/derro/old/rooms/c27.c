#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({MON"derro1.c", MON"derro2.c", MON"derro3.c"}), ({1,1,1,}) );
  ::create();
  set_repop(60);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Empty hall%^RESET%^"  );
  set_long(
  "%^RED%^Empty hall%^RESET%^\n"
  "  This great empty room looks like it's used for combat practice.   Huge gashes and holes are in the walls and floor where they have been hit with tremendous force."
  "\n"
  );
  set_smell("default",  "You get the occasional whiff of the scent of decaying flesh."  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "holes":"Smashed in the regular stone work of the walls and floor they give the room a well used look.",
  "water":"Warm clean water swirls in the cistern from a crack in the wall and drains out of the side and across the floor to the holes.",
  "walls":"Massive carved walls with many scratches and holes smashed into them.",
  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "west":ROOMS"c20",
  ]));
}

/* changed to be controlled by CROOM for longer reboots & control of max #'s *Styx*  11/28/02
This was bad because it didn't call ::reset() anyway
void reset(){
  object mon;
  if(!present("derro warrior")){
  new(MON"derro1.c")->move(this_object());
  new(MON"derro2.c")->move(this_object());
  new(MON"derro3.c")->move(this_object());
  }
}
*/