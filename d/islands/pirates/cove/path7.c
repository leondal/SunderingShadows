#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_name("Road through the village");
   set_short("Road through the village");
   set_long("%^BOLD%^Road through the village%^RESET%^\n"
"Little wooden shacks and rough buildings are scattered along either side of the road as you pass by here, "
"some in better repair than others.  Pathways run between the buildings, leading in several directions.  All "
"sorts of shady figures brush past you as they carry on their way.  The %^BLACK%^%^BOLD%^cobblestone road "
"%^RESET%^beneath your feet leads east, further into the village itself, and west to a small crossroads.  To "
"the north and south, two bars stand facing each other across the street, both filling the air with the "
"raucous sounds of drinking and merriment from within.\n");
   set("night long","%^BOLD%^Road through the village%^RESET%^\n"
"Little wooden shacks and rough buildings are scattered along either side of the road as you pass by here, "
"some in better repair than others.  Pathways run between the buildings, leading in several directions into "
"%^BLUE%^darkness%^RESET%^.  All sorts of shady figures brush past you as they slip through the %^BLACK%^"
"%^BOLD%^night's shadows%^RESET%^.  The %^BLACK%^%^BOLD%^cobblestone road %^RESET%^beneath your feet leads "
"east, further into the village itself, and west to a small crossroads.  To the north and south,%^YELLOW%^ "
"light%^RESET%^ is shed upon the street from two bars standing across from each other, both filling the air "
"with the raucous sounds of drinking and merriment from within.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","The murmur and bustle of the village surrounds you.");

   set_items(([
     ({"village","settlement","shacks","buildings"}):"All around you on each side, little wooden shacks and "
"rough buildings are scattered, with small paths running between them.  Two particular ones stand out here, "
"rowdy bars filled with patrons.  One is placed on either side of the street.",
     ({"road","cobblestones","cobblestone road"}):"Beneath your feet is a simple road of %^BLACK%^%^BOLD%^"
"cobblestones%^RESET%^, leading eastward into the village itself.",
     "bars":"Upon both the north and south sides of the street are two bars, filling the street with the "
"sounds of drunkenness and revelry from within.  A sign over the northern doorway reads%^WHITE%^%^BOLD%^ "
"'The Lazy Sailor Tavern'%^RESET%^, and one over the southern doorway reads %^WHITE%^%^BOLD%^'Seaman's Fare "
"Inn'%^RESET%^.",
    ]));

   set_exits(([
     "west":COVE"path6",
     "east":COVE"path8",
     "north":COVE"bar1",
     "south":COVE"bar2"
   ]));
}
