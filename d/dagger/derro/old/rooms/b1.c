#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create() {
  set_monsters( ({MON"derro1", MON"derro2" }), ({1,1}) );
  ::create();
  set_repop(75);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Hallway%^RESET%^"  );
  set_long(
  "%^RED%^Hallway%^RESET%^\n"
"  The massive hallway continues to the south and to the east. "
"It's lit with the same red glow that makes everything look like fresh
blood that prevades the rest of the halls. "
"The walls here are filled with empty weapons racks and there is a pile of small boulders in the corner.\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "boulders":"Rounded boulders all around the same size, look like catapult stones",
  "racks":"Massive weapon racks for weapons scaled to the size of the hall.",
  "weapon racks":"Massive weapon racks for weapons scaled to the size of the hall.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"b4",
  "south":ROOMS"b2",
  ]));
  new(OBJ"stone")->move(TO);
}
void reset(){
/* changed to use CROOM for control over longer reboots since they wander *Styx*  11/29/02
  object mon;
  ::reset();
  if(!present("derro warrior")){
  new(MON"derro1")->move(this_object());
  new(MON"derro2")->move(this_object());
  }
*/
}
