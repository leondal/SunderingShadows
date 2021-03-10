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
   set_short("Hallway of a Ruined Keep");
   set_long(
   "You are standing in another hallway in the ruined keep. The wall to the north is"+
   " not entirely intact, and a few blocks appear to have been deliberately moved"+
   " further out of the way in order to widen the opening. From the smell of things,"+
   " something has been using the northern hole as a bathroom. The hallway continues"+
   " to the south."
   );
   set_smell("default","The room stinks of urine.");
   set_listen("default","Wind whistles through the hole in the wall.");
   set_items(([
   ({"hole","blocks","wall"}) : "The north wall already had several large cracks in"+
   " it and a few missing blocks, but it appears as though someone has deliberately"+
   " widened one of the sections in order to make a hole. From the smell of things,"+
   " whoever did it has been using the hole in the wall as a bathroom of sorts.",
   "floor" : "The floor is dusty here and rather wet near the opening in the northern"+
   " wall, but you don't really want to think about that. There isn't too much mud"+
   " here, with only a few faint tracks of dried mud leading to the south.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep29",
   "south" : ROOMS+"keep31",
   ]));
}

void reset()
{
   ::reset();
   if(!random(3)) return;
   if(!present("xvart")) {
      new(MONS+"xvart")->move(TO);
   }
}
