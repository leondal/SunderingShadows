//Octothorpe (6/4/16)
//Shadow, Armor Shop

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
   set_short("%^RED%^Flugar's Armory%^RESET%^");
   set_long("%^RED%^Flugar's Armory\n"+
      "%^RESET%^This building is constructed out of well-worn "+
      "st%^BOLD%^o%^RESET%^ne and %^ORANGE%^timber %^RESET%^that "+
      "lends it an air of respectability and constancy. A broad "+
      "%^ORANGE%^oaken %^RESET%^counter sits near the eastern wall and is "+
      "covered with various pieces of armor that are being sold or "+
      "repaired. At intervals around the shop there are dozens of "+
      "stands outfitted in various types of armor, ranging from "+
      "%^ORANGE%^leather %^RESET%^to %^BOLD%^pl%^RESET%^a%^BOLD%^"+
      "te%^RESET%^. A doorway in the back corner of the shop leads "+
      "to forge shared with the neighboring weaponsmith.\n");
   set_items(([
      ({"stands","armor","leather","plate"}) : "%^ORANGE%^Wooden "+
         "%^RESET%^armor stands are found at intervals throughout "+
         "the store, displaying the various types of armor for sale. "+
         "Everything from finely crafted %^ORANGE%^leather %^RESET%^"+
         "armor to shin%^BOLD%^ey %^RESET%^suits of full plate armor "+
         "can be found.",
      ({"doorway","forge"}) : "An entrance to the forge shared "+
         "between the armory and the weaponsmith can be found in "+
         "the back corner of the room.",
      "counter" : "The broad counter is covered in armor in various "+
         "states of repair."
   ]));
   set_exits(([
      "northeast" : ROOMS"forge",
      "south" : ROOMS"shadwaya"
   ]));
   set_smell("default","The smell of fresh leather and polished steel "+
      "fills the air.");
   set_listen("default","You hear dull clanging coming form the forge.");
   if(!present("flugar"))
   {
      new(MON"flugar")->move(TO);
   }
}

void reset()
{
   ::reset();
   if(!present("flugar"))
   {
      new(MON"flugar")->move(TO);
   }
}