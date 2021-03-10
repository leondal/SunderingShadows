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
  set_short(  "%^RED%^Great hallway%^RESET%^"  );
  set_long(
  "%^RED%^Great hallway %^RESET%^\n"
  "  This hall way is huge, spanning 25 feet across and high and stretching far into the distance, lit only with the red globes in the ceiling."
  "\n"
  );
  set_smell("default",
  "The heat blasts you as currents of air swirl through the halls."
  );
  set_listen("default",
  "A warm breeze from the north murmurs softly as it passes this hall."
  );
  set_items(([
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "north":ROOMS"c19",
  "south":ROOMS"c21",
  "east":ROOMS"c27",
  "northeast":ROOMS"c24",
  ]));
}

void init(){
  ::init();
  do_random_encounters(({ MON"derro1.c",MON"derro2.c",MON"derro3.c" }),50,1);
}
