#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("indoors",1);
  set_short(
  "Cellar"
  );
  set_long(
  "Cellar.\n"
  "  This dark cold cellar is used to store perishible goods and items that need to be kept out of the rain but still not used much."
  "  A few boxes of vegetables and simple farm equipment line the walls."
  "  Everything has been moved as if someone searched it."
  "\n"
  );
  set_smell("default",
  "You can smell mold settling into everything."
  );
  set_listen("default",
  "You can faintly hear the banging of the shutters upstairs."
  );
  set_items(([
  "boxes":"Lots of potatoes that seem to be going bad pretty quick.",
  "vegetables":"Lots of potatoes that seem to be going bad pretty quick.",
  "farm equipment":"Rakes, shovels, hoes simple stuff but of such weak construction as to be useless to you.",
  "walls":"Dark hard packed dirt forms the walls and floor.",
  "floor":"Dark hard packed dirt forms the floor and walls.",
  "ceiling":"You can see the support beams and the bottom of the wooden slats that make up the upstairs floor.",
  ]));
  set_exits(([
  "up":ROOMS"v58.c",
  ]));
}
