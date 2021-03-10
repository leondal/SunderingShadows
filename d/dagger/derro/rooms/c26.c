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
  set_property("fill waterskin",1);
  set_short(  "%^RED%^Lavatory%^RESET%^"  );
  set_long(
  "%^RED%^Lavatory%^RESET%^\n"
  "  This room is bare and clean unlike the rest of the complex.  Two great holes from which a red glow and much heat wells up from are near the east wall while to the north a massive water cistern is built into the floor."
  "\n"
  );
  set_smell("default",  "You smell something cooking from the northwest."  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance."
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "cistern":"It's a bowl carved in the rock that is 10 feet across and deep.   It's hot to the touch as if the water was warmed elsewhere.",
  "holes":"These large holes lead down to chutes that open far below you in a pool of lava surrounded by rocky crags.",
  "crags":"Hmm.  Looks like there is an opening down there, wonder how you'd get down?",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",
  "chutes":"Smooth at the start but the walls they lead to would be easy enough descend.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "west":ROOMS"c23",
  "southwest":ROOMS"c24",
  ]));
  set_climb_exits(([
  "descend":({ROOMS"c39",20,100,100}),
  ]));
}
void init(){
  ::init();
  add_action("drink","drink");
}
int drink(string str){
  if((str=="water from cistern") || (str=="water")){
  if(!TP->add_quenched(50)) return notify_fail("You're already quenched!\n");
  write("You take a large drink from the cistern.");
  return 1;
}
}
