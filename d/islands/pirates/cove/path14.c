#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Rocky trail");
   set_short("Rocky trail");
   set_long("%^BOLD%^Rocky trail%^RESET%^\n"
"The stony path ends at a dark hole in the cliffside, leading into a %^BLACK%^%^BOLD%^dark tunnel%^RESET%^.  "
"The trail here is hard and %^BLACK%^%^BOLD%^rocky%^RESET%^, part of the cliff itself, and is set on a "
"slight incline, leading back south toward a well-maintained %^ORANGE%^wooden bridge%^RESET%^.  Rising above "
"you, the sharp face of the cliff reaches up toward the %^CYAN%^%^BOLD%^sky%^RESET%^, while southward you "
"can just make out a small village, and the great expanse of the %^BLUE%^%^BOLD%^ocean's waves%^RESET%^.\n");
   set("night long","%^BOLD%^Rocky trail%^RESET%^\n"
"The stony path ends at a dark hole in the cliffside, leading into a %^BLACK%^%^BOLD%^dark tunnel%^RESET%^.  "
"The trail here is hard and %^BLACK%^%^BOLD%^rocky%^RESET%^, part of the cliff itself, and is set on a "
"slight incline, leading back south toward a well-maintained %^ORANGE%^wooden bridge%^RESET%^.  Rising above "
"you, the sharp face of the cliff overshadows your steps as it reaches up toward the %^BLUE%^dark sky"
"%^RESET%^, while southward you can just make out a small village, and the great expanse of the %^BLUE%^"
"%^BOLD%^ocean's waves%^RESET%^.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","You can hear the distant, crashing waves of the ocean.");

   set_items(([
     ({"village","settlement"}):"Far to the southwest, you can just see the outline of a small settlement.",
     ({"trail","path","rocks","stones"}):"The trail here is almost part of the cliff itself, hard and "
"%^BLACK%^%^BOLD%^rocky%^RESET%^ beneath your feet.  It ascends on a slight incline to the north, into the "
"mouth of a %^BLACK%^%^BOLD%^dark tunnel%^RESET%^.",
     "cliff":"The trail here seems almost part of the cliff itself, which rises sharply to overshadow your "
"steps.",
     ({"ships","boats"}):"Occasionally a boat sails across the water, as it enters or leaves the docks.",
     ({"water","ocean","sea","waves"}):"In the distance to the south, you can see the %^BLUE%^%^BOLD%^waves "
"%^RESET%^of the ocean, stretching as far as the eye can see."
    ]));

   set_exits(([
     "south":COVE"path13",
     "up":CAVES"cave16"
   ]));
}
