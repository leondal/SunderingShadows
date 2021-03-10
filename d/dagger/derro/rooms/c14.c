#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({MON"derro2", MON"derro1", MON"derro3"}),({1,1,1}));
  ::create();
  set_repop(60);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Bottom of a flight of stairs.%^RESET%^"  );
  set_long(
  "%^RED%^Bottom of a flight of stairs.%^RESET%^\n"
  "  You stand at the bottom of a wide set of stairs that leads up into the darkness.  There are numerous globes in the ceiling although they don't seem to offer anymore than one globe has been alone."
  "\n"
  );
  set_smell("default",
  "The heat here is tremendous as a steady gusts of warm wind come in from the north."
  );
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
  "north":ROOMS"c13",
  "up":ROOMS"b2",
  ]));
}
void reset(){
  ::reset();
/* changing to use CROOM for control over longer reboots *Styx*  11/29/02
  if(!present("derro warrior")){
  new(MON"derro1.c")->move(this_object());
  new(MON"derro2.c")->move(this_object());
  new(MON"derro3.c")->move(this_object());
  }
*/
}
