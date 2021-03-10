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
  set_short(  "%^RED%^Stairs leading down%^RESET%^"  );
  set_long(
  "%^RED%^Stairs leading down%^RESET%^\n"
"  You stand at the top of a wide set of stairs that leads down into darkness.   The light from the here doesnt reach very far down the stairs, but you can dimmly see another pool of red light at the bottom where the stairs end in a room.\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",
  "stairs":"Wide deep stairs.  It's hard to walk down them for the tallest of people and you can imagine the derro have a tough time going up and down stairs as tall as they are.",
  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "down":ROOMS"c14",
  "north":ROOMS"b1",
  ]));
}
  void init(){
  ::init();
  do_random_encounters(({
  MON"derro1.c",MON"derro2.c",MON"derro3.c"
  }),50,1);
}
