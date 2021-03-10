#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({MON"derro1", MON"derro2", MON"derro3" }), ({1,1,1}) );
  ::create();
  set_repop(75);
   set_travel(PAVED_ROAD);
   set_terrain(BUILT_TUNNEL);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Murder room%^RESET%^"  );
  set_long(
  "%^RED%^Murder room%^RESET%^ \n"
"  The passageways to the north, east and west all look to be cover points for fire to be directed into this room."
"  The room is bare other than the massive doorway with a open metal gate to the southeast."
  "\n"
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

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "north":ROOMS"b3",
  "east":ROOMS"b5",
  "west":ROOMS"b1",
  "southeast":ROOMS"b6",
  ]));
}
