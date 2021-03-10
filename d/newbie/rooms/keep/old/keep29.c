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
   set_short("Kitchen of a Ruined Keep");
   set_long(
   "You are standing in the kitchen of a ruined keep. It is a small section of the"+
   " full kitchen you realize, the rest of it must have been further north where"+
   " the ceiling collapsed. Nothing seems to be working, most everything is completely"+
   " smashed from the collapse, except for a few pots and pans, even some of those"+
   " are scratched and dented. A large cauldron has been set up in the middle of the"+
   " room, over a rather crude cooking fire. Some mud tracks lead out to the east,"+
   " but only a couple it looks like."
   );
   set_smell("default","The odor of spoiled food fills this room.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   "floor" : "The floor is covered in mud and muck and various discarded bits of food,"+
   " bone, and animal skins.",
   "ceiling" : "The ceiling is blackened with soot from the cooking fire.",
   "cauldron" : "A large cauldron is set up over a cooking fire in the center of the"+
   " room. The contents of the cauldron are none too appetizing, it appears to be a"+
   " stew of some sort. On a closer look you notice a rat head bob to the surface."+
   " You're not quite sure whether the rat climbed in and died from the food, or if"+
   " it was put in on purpose.",
   ({"fire","cooking fire"}) : "A cooking fire has been set up around the cauldron"+
   " in the center of the room, but it is not currently lit.",
   ({"pots","pans"}) : "There are a few dirty pots and pans that have been scattered"+
   " about the kitchen. Some of them have dents in them, and others are rather"+
   " scratched up, but most are still useable...or would be if they were clean, you're"+
   " not sure what's in some of them and you would really rather not find out.",
   ]));
   set_exits(([
   "east" : ROOMS+"keep30",
   "west" : ROOMS+"keep28",
   ]));
}

void reset()
{
   ::reset();
   if(!present("xvart") && !random(2)) {
      new(MONS+"xvarts")->move(TO);
      switch(random(2)) {
         case 0:
            new(MONS+"xvart")->move(TO);
            break;
         case 1:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
      }
   }
}
