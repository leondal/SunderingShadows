#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"rogue"}),({1}));
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_name("Village crossroads");
   set_short("Village crossroads");
   set_long("%^BOLD%^Village crossroads%^RESET%^\n"
"You have reached the crossroads of the village, with all sorts of shady figures brushing past you as they "
"carry on their way.  Little wooden shacks and rough buildings are scattered all around, some in better "
"repair than others.  Pathways run between the buildings, leading in several directions.  The "
"%^BLACK%^%^BOLD%^cobblestone road%^RESET%^ beneath your feet leads east, further into the village itself, "
"where you can see small gatherings of people here and there.  Southward, a %^ORANGE%^trail of dirt%^RESET%^ "
"breaks away, leading down toward the docks and the vast expanse of %^BLUE%^%^BOLD%^ocean%^RESET%^.  Another "
"rough trail leads away in the opposite direction, but it seems to have become overgrown by bushes and "
"trees.\n");
   set("night long","%^BOLD%^Village crossroads%^RESET%^\n"
"You have reached the crossroads of the village, with all sorts of shady figures brushing past you as they "
"slip through the %^BLACK%^%^BOLD%^night's shadows%^RESET%^.  Little wooden shacks and rough buildings are "
"scattered all around, some in better repair than others.  Pathways run between the buildings, leading in "
"several directions into %^BLUE%^darkness%^RESET%^.  The %^BLACK%^%^BOLD%^cobblestone road%^RESET%^ beneath "
"your feet leads east, further into the village itself, which is still not entirely deserted even at this "
"time of night.  Southward, a %^ORANGE%^trail of dirt%^RESET%^ breaks away, leading down toward the docks "
"and the vast expanse of %^BLUE%^%^BOLD%^ocean%^RESET%^.  Another rough trail leads away in the opposite "
"direction, but it seems to have become overgrown by bushes and trees.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","You can hear the distant, crashing waves of the ocean.");

   set_items(([
     ({"village","settlement","shacks","buildings"}):"All around you on each side, little wooden shacks and "
"rough buildings are scattered, with small paths running between them.",
     ({"trail","path","gravel","trails","paths"}):"Two rough trails lead away from this crossroads, one to "
"the north and one to the south.  The northern one appears to be overgrown, though the southern leads right "
"down to the ocean, where many boats sail in and out of the docks.",
     ({"road","crossroad","crossroads","cobblestones","cobblestone road"}):"Beneath your feet is a simple "
"road of %^BLACK%^%^BOLD%^cobblestones%^RESET%^, leading eastward into the village itself.",
     ({"ships","boats"}):"Occasionally a boat sails across the water, as it enters or leaves the docks.",
     ({"water","ocean","sea","waves"}):"Past the wooden boardwalk to the south, you can see the %^BLUE%^"
"%^BOLD%^waves %^RESET%^of the ocean, stretching as far as the eye can see to the south.",
     ({"boardwalk","dock","docks"}) : "Down the trail to the south is a long boardwalk of %^ORANGE%^wooden "
"planks%^RESET%^, spaced with several docks.",
    ]));

   set_exits(([
     "south":COVE"path4",
     "east":COVE"path6",
     "north":COVE"thief1"
   ]));
}
