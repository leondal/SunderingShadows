#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({MON"derro1", MON"derro2" }), ({1,1}) );
  ::create();
  set_repop(75);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Guard room%^RESET%^\n"  );
  set_long(
  "%^RED%^Guard room.%^RESET%^\n"
"  The exit to the west has stone enbankments on both sides to offer cover to fire into the murder room."
"  Small boulders lay strewn about an otherwise featureless stone room."
  "\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "embankments":"The passageway west narrows to a easily defensible position that are only 12 feet wide as opposed to 25 like the rest of the halls.",
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "west":ROOMS"b4",
  ]));
}

