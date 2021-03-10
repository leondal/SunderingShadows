#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Rough trail");
   set_short("Rough trail");
   set_long("%^BOLD%^Rough trail%^RESET%^\n"
"This path leads northward away from the docks, toward a small settlement a short distance away.  The trail "
"itself is little more than %^ORANGE%^dust%^RESET%^ and %^BLACK%^%^BOLD%^gravel%^RESET%^ here, rough beneath "
"your feet.  At either side, the path is lined by %^GREEN%^light shrubbery%^RESET%^, struggling to grow in "
"the sandy soil.  To the south, you can see a %^ORANGE%^wooden boardwalk%^RESET%^, spaced with several "
"docks, and the great expanse of the %^BLUE%^%^BOLD%^ocean's waves%^RESET%^ past it.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","You can hear the distant, crashing waves of the ocean.");

   set_items(([
     ({"village","settlement"}):"Further northward, you can make out the buildings of a small settlement.",
     ({"trail","path","gravel"}):"The %^ORANGE%^dust%^RESET%^ and gravel upon the path crunches beneath your "
"feet.  It leads northward to what looks like a small village, and southward back toward the docks.",
     ({"plants","shrubbery"}):"A few %^GREEN%^wiry plants%^RESET%^ line either side of the path, struggling "
"to grow in the sandy soil.",
     ({"ships","boats"}):"Occasionally a boat sails across the water, as it enters or leaves the docks.",
     ({"water","ocean","sea","waves"}):"Past the wooden boardwalk, you can see the %^BLUE%^%^BOLD%^waves "
"%^RESET%^of the ocean, stretching as far as the eye can see to the south.",
     ({"boardwalk","dock","docks"}) : "Just to the south is a long boardwalk of %^ORANGE%^wooden planks"
"%^RESET%^, spaced with several docks.",
    ]));

   set_exits(([
     "southwest":COVE"path1",
     "north":COVE"path3"
   ]));
}
