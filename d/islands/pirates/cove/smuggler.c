#include <std.h>
#include <daemons.h>
#include "../piratedefs.h"
inherit "/std/pstore";

#define MAX_ITEMS 10

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_owners(({"nienne"}));
   set_storage(STORAGE"sell");
   set_drop_storage(STORAGE"repairs"); //required?
   set_items_allowed(({"clothing","armor","jewelry","weapon"}) );
   set_name("The Treasure Chest");
   set_short("The Treasure Chest");
   set_long("%^BOLD%^The Treasure Chest%^RESET%^\n"
"A corridor from the %^BLUE%^curtain-veiled%^RESET%^ doorway leads into this little, dimly-lit room.  "
"There's not a single window to light the area, only one dull torch across the room that casts %^BLACK%^"
"%^BOLD%^shadows%^RESET%^ around you.  While it's a little dirty here, unlike most of the town, this "
"building has the appearance of being quite well made and maintained.  Not much seems to be available to buy "
"here, only a handful of select items.");
   set_smell("default","The room has a thick, musty smell to it.");
   set_listen("default","It's surprisingly quiet, in here from the street.");
   set_exits(([
     "south":COVE+"path10",
   ]));
   set_items(([
     ({"doorway","curtain"}): "The doorway is covered by a %^BLUE%^thick, heavy curtain%^RESET%^, that hides "
"the room inside from the street.",
     ({"light","torch"}): "Only a single dull torch is here to light the room, casting flickering %^BLACK%^%^BOLD%^shadows%^RESET%^ around you.",
   ]));
}

void reset() {
   ::reset();
   if(!present("shawologon")) 
	find_object_or_load(MON"shawologon")->move(TO);
}
