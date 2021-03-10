#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Sleeping quarters");
   set_short("Sleeping quarters");
   set_long("%^BOLD%^Sleeping quarters%^RESET%^\n"
"This room is only short, but rather long, and quite deserted at the moment.  Along the length of the back "
"wall are spaced many rough beds and hammocks, probably where the crewmen of the ship sleep.  The floor, "
"walls and roof are all made of the same old %^ORANGE%^wood%^RESET%^, creaking as the boat rocks on the "
"water.  There are no windows anywhere in the room, leaving it very %^BLUE%^dark%^RESET%^ and "
"%^BLACK%^%^BOLD%^shadowy%^RESET%^ in here.  A large doorway leads out into the corridor.\n");
   set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
   set_listen("default","You hear the boards of the ship creak in an unsettling way.");
   set_items(([
     ({"floor","walls","roof","wood"}):"The floor, walls and roof are all made of the same old%^ORANGE%^ "
"wood%^RESET%^, that creaks as the ship moves.  The wood looks quite old, and is in desperate need of a "
"polish.",
     "doorway":"The single outlined doorway leads back out into the corridor.",
     "shadows":"The room is shrouded in %^BLACK%^%^BOLD%^shadow%^RESET%^, making it hard to distinguish "
"details of the area around you."
   ]));
   set_exits(([
     "east":COVE"boata05"
   ]));
}
