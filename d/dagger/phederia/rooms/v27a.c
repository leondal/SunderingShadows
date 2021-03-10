#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("indoors",1);
  set_short(
  "Hayloft above the bloody barn."
  );
  set_long(
  "Hayloft above the bloody barn.\n"
  "  This is the large hayloft above the barn.  From up here you can see the blood, entrails and meat left to rot on the floor far below."
  "  All the mess is concentrated in the center of the building, as if the creatures involved were all lined up before being gutted."
  "\n"
  );
  set_smell("default",
  "The entrails and flesh are starting to rot and the smell of blood fills your nose."
  );
  set_listen("default",
  "You cant hear anything past the horrors which fill your sight."
  );
  set_items(([
  "blood":"Thick and black its clotted to the straw on the floor.",
  "flesh":"As you investigate a little closer you see flesh mixed in with the flesh.   And no farm animals have clear hairless skin like that.   Perhaps its where the villagers have all disapeared to.   But.  Where are their bones?",
  "entrails":"As you investigate a little closer you see flesh mixed in with the flesh.   And no farm animals have clear hairless skin like that.   Perhaps its where the villagers have all disapeared to.   But.  Where are their bones?",
  "hay":"Looks like they havent bothered to harvest this years hayfields.",
  ]));
  set_exits(([
  "down":ROOMS"v27.c",
  ]));
}
