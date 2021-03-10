#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A secret passage");
   set_long(
   "You are standing in a secret passage. There really isn't much to this room, it"+
   " is covered in dust and no one else has probably set foot in here for some time."+
   " There is a faded and worn rug laid out across the floor, probably to muffle"+
   " the footsteps of anyone walking around back here. The passage continues to the"+
   " west and south."
   );
   set_smell("default","The passage is filled with dust.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
   "floor" : "The floor has a rug laid out across it and is covered in dust.",
   "rug" : "The rug appears faded and rather worn, it was probably placed here to"+
   " keep footsteps from echoing and giving the secret passage away. It extends"+
   " to the west and south.",
   ({"wall","walls"}) : "The walls are made of unremarkable stone blocks and appear"+
   " quite sturdy.",
   ]));
   set_exits(([
   "south" : ROOMS+"keep38",
   "west" : ROOMS+"keep41",
   ]));
}

void init()
{
   ::init();
   do_random_encounters(({MONS+"spider"}),40,1);
}
