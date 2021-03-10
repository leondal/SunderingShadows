//Octothorpe (6/4/16)
//Shadow, Weapon Shop

#include <std.h>
#include "../defs.h"

inherit ROOM;

void create()
{
   ::create();
   set_indoors(1);
   set_light(2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("%^RED%^Valchor's Weaponsmithy%^RESET%^");
   set_long("%^RED%^Valchor's Weaponsmithy\n"+
      "%^RESET%^This building is constructed out of well-worn "+
      "st%^BOLD%^o%^RESET%^ne and %^ORANGE%^timber %^RESET%^that "+
      "lends it an air of respectability and constancy. A broad "+
      "%^ORANGE%^oaken %^RESET%^counter sits near the western wall and is "+
      "covered with various weapons that are being sold or "+
      "repaired. Throughout the shop there dozens of %^ORANGE%^wooden "+
      "%^RESET%^cases and stands displaying a multitude of weapons. "+
      "A doorway in the back corner of the shop leads "+
      "to forge shared with the neighboring armorsmith.\n");
   set_items(([
      ({"stands","cases"}) : "%^ORANGE%^Wooden %^RESET%^cases and "+
         "stands are found at intervals throughout the store, "+
         "displaying the various types of weapons for sale. "+
         "Everything from long swords to halberds can be found.",
      ({"doorway","forge"}) : "An entrance to the forge shared "+
         "between the armory and the weaponsmith can be found in "+
         "the back corner of the room.",
      "counter" : "The broad counter is covered in weapons in various "+
         "states of repair."
   ]));
   set_exits(([
      "northwest" : ROOMS"forge",
      "south" : ROOMS"shadwayb"
   ]));
   set_smell("default","The smell of freshly polished steel fills "+
      "the air.");
   set_listen("default","You hear dull clanging coming form the forge.");
   if(!present("valchor"))
   {
      new(MON"valchor")->move(TO);
   }
}

void reset()
{
   ::reset();
   if(!present("valchor"))
   {
      new(MON"valchor")->move(TO);
   }
}