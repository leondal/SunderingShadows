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
  set_short(  "%^RED%^Barracks%^RESET%^"  );
  set_long(
  "%^RED%^Barracks%^RESET%^\n"
  "  This massive room continues far off to the north and appears to be the living quarters for numerous huge creatures.   Great curtains partition off the room and behind them lay individual beds and great chests."
  "  Everything seems to have been rummaged through already although little seems to have been taken with it being to large to move.\n"
  );
  set_smell("default", "You get the occasional whiff of the scent of decaying flesh." );
  set_listen("default",
  "Hot air rushes by from the north filling the room with the low murmur of shifting curtains."
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "curtains":"Woven of some rough cloth these are large enough to cover most human sized huts.   The material is coarse and worthless and its great size makes it impossible to move.",
  "chests":"Immense and filled with useless items.  Everything is covered in filth and mangled, so even if it once had value it no longer does.",
  "beds":"25 feet long and constructed of stone with great masses of hides and dirty clothes draped over them.  They crawl with lice and other pests.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "north":ROOMS"c16",
  "west":ROOMS"c12",
  ]));
}
void init(){
  ::init();
  do_random_encounters(({  MON"derro1.c",MON"derro2.c",MON"derro3.c"  }),50,1);
}
