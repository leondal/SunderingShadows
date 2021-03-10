//leader2.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_short("A secret passageway");
   set_long(
      "This narrow passageway is clean and well-kept, seemingly in use "+
      "quite a bit.  The walls are made of smooth wooden boards fitted "+
      "together with tongue and groove.  The floor is the same stone as "+
      "most of the building and is covered by a long woven rug that helps "+
      "muffles the sound.  The hallway leads to the west, and there is a "+
      "door in the southern wall.  A few of the wall planks seem to be "+
      "spread a little far apart, perhaps from age."

   );
   set_items(([
      (({"wall","walls","planks","boards","wooden walls"})) : "The light "+
         "wood of the walls has been formed into tongue and groove planks, "+
         "most of which fit together well.  To the left of the door in the "+
         "southern wall, two planks seem especially ill-fitted, leaving what "+
         "seems to be a small crack.",
      (({"floor","rug","woven rug"})) : "The stone floor of the hallway has been "+
         "worn smooth by use.  A long woolen rug in a muted shade of %^ORANGE%^brown "+
         "%^RESET%^lines the entire hallway, masking sound from this room.",
      "crack" : "Just to the left of the door is a small crack left by the "+
         "tongue and groove planks.  A bit of firelight dances through the "+
         "opening.  If you were so inclined, you might be able to view the "+
         "other room."
      ]));
   set_smell("default","The hallway smells slightly musty.");
   set_listen("default","Sound in the hallway is muffled by the thick rug.");

   set_exits(([
      "south" : TROOMS"leader1",
      "west" : TROOMS"passage1"
      ]));
}

void init()
{
   ::init();
   add_action("view","view");
}

void view(string str)
{
   object *stuff;
   int i;
   stuff = all_living(find_object_or_load(TROOMS"leader1"));
   tell_object(TP,"%^RED%^You lean down and peer through the crack in the wall.");
   tell_room(ETP,"%^RED%^"+TPQCN+" leans down and peers intently at the wall.",TP);
   tell_object(TP,"A large office\n");
   for(i=0;i<sizeof(stuff);i++) {
      if(!stuff[i]->query_invis())
         tell_object(TP,stuff[i]->query_short());
   }
   return 1;
}
