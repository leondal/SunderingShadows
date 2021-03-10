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
  set_short(  "%^RED%^Kitchen%^RESET%^"  );
  set_long(
  "%^RED%^Kitchen%^RESET%^\n"
  "  This kitchen is built on a massive scale."
  "  You're pretty sure a whole cow could fit in the oven and there are signs of recent work all around."
  "  Most of the pots and pans are giant sized but there are just as many recent additions that seem suited to human hands."
  "\n"
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
  "north":ROOMS"c22",
  "south":ROOMS"c24",
  "east":ROOMS"c26"
  ]));
  set_pre_exit_functions(({"north"}),({"exit_fun"}));
}

int exit_fun(){
  write("%^BOLD%^%^WHITE%^The door closes with a click behind you!");
  return 1;
}

void reset(){
  ::reset();
  if(!present("giants cook")){
  new(MON"cook.c")->move(TO);
  }
}
