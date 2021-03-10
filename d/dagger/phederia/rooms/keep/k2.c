#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Gatehouse"
  );
  set_long(
  "Gatehouse\n"
  "  This is the entry passage to the rose colored keep inside the outer walls."
  "  The great doors that lead to the hedges hang on shattered hinges and dont look like they coould ever be used to block passage again."
  "  Shadows hang thick around this area and stone roof and walls seem to close in on you."
  "\n"
  );
  set_smell("default",
  "The scent of dried blood stings you."
  );
  set_listen("default",
  "You can hear the echoing sound of footsteps on stone above you."
  );
  set_items(([
  "doors":"The doors looked like they were never meant to be used at a real defense against an attack.   They must of fallen easily from the lack of real damage to them.",
  "shadows":"The shadows hold nothing but silence",
  "roof":"Shadowy blocks of the same pink stone as the walls and inner keep looks like dried blood in this dark area.",
  "floor":"Blood stains show where the first defenders or attackers of the keep must of died.",
  "blood stains":"The blood is hardly noticable against the rosey stones that look like blood themselves in the shadows here.",
  ]));
  set_exits(([
  "gates":ROOMS"h76.c",
  "west":KEEP"k35.c",
  ]));
}
