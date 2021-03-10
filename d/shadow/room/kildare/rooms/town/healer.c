#include <std.h>
#include "../../kildare.h"

inherit HEALER;

void create()
{
   ::create();
   set_light(3);
   set_property("training",1);
   set_indoors(1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("The Village Apothecary");
   set_long(
@CIRCE
%^RESET%^%^ORANGE%^The Village Apothecary
%^RESET%^MAGENTA%^A simple stone building like all the others in the town, 
this one is set apart by the strange objects and scents inside.
Along the eastern wall, a wooden bookcase reaches from floor 
to ceiling, covered with random herbs, vials, and oddities.  The 
room is warmed by a fireplace just beside the bookcase, over which 
a black cauldron boils and bubbles.  A small square table sits in 
the middle of the floor on a threadbare %^ORANGE%^brown rug%^MAGENTA%^, braced by two 
wooden chairs.  Three more chairs stand to the west of the door 
against the wall, padded to provide some amount of comfort for those 
awaiting news of the sick and injured.  A %^YELLOW%^yellow curtain %^RESET%^%^MAGENTA%^is pulled 
back on the western wall, revealing two small cots.  A matching curtain 
covers the southern wall, presumably where the healer himself sleeps.%^RESET%^
CIRCE
        );
   set_smell("default","The scent of various herbs is mixed with"+
      " the stew brewing in the cauldron.");
   set_listen("default","The crackle of the fire creates a soothing atmosphere.");
   set_items(([
      (({"stone","building","room"})) : "The dark gray stone "+
      "of the surrounding mountainside has been used to build "+
      "this simple square room.",
      (({"bookcase","herbs","vials","oddities","objects"})) : "%^MAGENTA%^The "+
      "wooden bookcase holds many different dried herbs used in "+
      "healing the sick and injured.  Vials with strange substances "+
      "floating inside stand alongside mosses, leaves, and jarred "+
      "items better left unsaid.  Only a person skilled in the art "+
      "of medicine would know what most of these are used for.",
      (({"fireplace","fire place"})) : "The stone in the fireplace matches "+
      "the rest of the room, blending in completely.  A roaring fire "+
      "keeps the room toasty so that patients do not become further ill.",
      (({"kettle","cauldron","black cauldron"})) : "%^BOLD%^%^BLACK%^The black "+
      "iron cauldron hangs suspended by an iron hook driven into the "+
      "chimney.  Surprisingly, a stew - not a remedy - seems to be "+
      "boiling inside.",
      (({"table","square table","small table"})) : "The wooden table atop "+
      "the brown rug seems worn, but sturdy.  It is spotless and well-polished, "+
      "a testament to the apothecary's practice.  Two chairs are pushed "+
      "under it for the healer and his patient to use.",
      (({"chairs","chair","padded chairs"})) : "The ladder backed chairs "+
      "stand near the doorway against the wall.  They look quite old and "+
      "worn, but have obviously been well-cared-for.  Thin blue cushions "+
      "are placed on each seat, filled with wool to help ease the wait for "+
      "family and friends.",
      (({"curtain","curtains","yellow curtain"})) : "%^YELLOW%^The pale yellow "+
      "curtain along the western wall is pulled back at the moment to reveal two "+
      "low cots.  They must be used for patients who must stay awhile, or perhaps "+
      "for a family member as well.  A matching curtain stretches across the "+
      "southern portion of the room, blocking it from view."
      ]));

   set_exits(([
      "north" : TROOMS"path10"
      ]));
   set_name("Samson");
}

void reset()
{
        ::reset();
        if(!present("samson")) {
                new(MON"samson.c")->move(TO);
        }
}
