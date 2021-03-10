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
  set_short(  "%^RED%^Guard room%^RESET%^"  );
  set_long(
  "%^RED%^Guard room.%^RESET%^\n"
  "  The exit to the south is narrower than the rest of the passage with stone enbankments to offer those in this room cover from fire to the south."
  "  Small boulders lay strewn about and other than that the room is featurless."
  "\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "embankments":"The passageway south narrows to a easily defensible position that are only 12 feet wide as opposed to 25 like the rest of the halls.",
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "boulders":"Look like catapult stones.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "south":ROOMS"b4",
  ]));
  new(OBJ"stone")->move(TO);
}
