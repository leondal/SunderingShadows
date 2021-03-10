#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_property("no teleport", 1);
   set_short("%^RED%^The Seneca Armory");
   set_long(
@DESC
%^BOLD%^The Seneca Armor Exchange.%^RESET%^

It is quite hot in here. The walls and roof are made from 
stamped metals that have been riveted to a wooden support 
frame. A large metal table stands at the center of the room 
and various mails and plates hang as samples along the walls.  
The rear of the store is separated by a large counter. Seneca 
is known for armors of fine quality and superb craftsmanship.
DESC
   );
   set_smell("default","You can smell the metallic ash from the smelting room.");
   set_listen("default","Every sound echoes in this metal room. ");
   set_exits(([
      "out" : "/d/attaya/seneca/armoryard",
      "east" : "/d/attaya/seneca/armor2",
   ]));
   set_door("door", "/d/attaya/seneca/armoryard", "out", 0);
   set_open("door", 0);
   set_items(([
      "walls" : "The walls are made of thin stamped iron plates bolted to a wooden skeletal structure that is exposed to the inside of the building.  Upon the walls hang samples of armor.",
      "mails" : "They are large rectangles of armor grade metal mesh.",
      "plates" : "Thick metal plates for heavy armors hang on the walls.",
      "table" : "It is a large demonstration table.  The surface is seared in a few places.",
      "floor" : "The floor is covered with metal filings.",
      "counter" : "The counter has shelves on the opposite side and a smooth stone base over cedar base.",
   ] ));
}

void reset() {
   ::reset();
   if(!present("angus"))
      new("/d/attaya/seneca/mon/armorer.c")->move(TO);
}
