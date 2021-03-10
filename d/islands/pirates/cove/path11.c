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
"This path leads in a northeastern direction, away from the small settlement a short distance away.  The "
"trail itself is little more than %^ORANGE%^dust%^RESET%^ and %^BLACK%^%^BOLD%^gravel%^RESET%^ here, rough "
"beneath your feet. It joins up with a cobblestone road just to the west, however, where a few shabby "
"buildings rise up to line it on either side.  At either side, the path is lined by %^GREEN%^light shrubbery"
"%^RESET%^, struggling to grow in the sandy soil.  Further north, the face of a great cliff reaches up "
"toward the %^CYAN%^%^BOLD%^sky%^RESET%^, while southward you can make out the great expanse of the %^BLUE%^"
"%^BOLD%^ocean's waves%^RESET%^.\n");
   set("night long","%^BOLD%^Rough trail%^RESET%^\n"
"This path leads in a northeastern direction, away from the small settlement a short distance away.  The "
"trail itself is little more than %^ORANGE%^dust%^RESET%^ and %^BLACK%^%^BOLD%^gravel%^RESET%^ here, rough "
"beneath your feet. It joins up with a cobblestone road just to the west, however, where a few shabby "
"buildings rise up to line it on either side.  At either side, the path is lined by %^GREEN%^light shrubbery"
"%^RESET%^, struggling to grow in the sandy soil.  Further north, the face of a great cliff overshadows you "
"as it reaches up toward the %^BLUE%^dark sky%^RESET%^, while southward you can make out the great expanse "
"of the %^BLUE%^%^BOLD%^ocean's waves%^RESET%^.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","You can hear the distant, crashing waves of the ocean.");

   set_items(([
     ({"village","settlement"}):"Just to the west, you can make out the buildings of a small settlement.",
     ({"trail","path","gravel"}):"The %^ORANGE%^dust%^RESET%^ and gravel upon the path crunches beneath your "
"feet.  It leads westward to what looks like a small village, and north toward the looming cliff-face.",
     ({"plants","shrubbery"}):"A few %^GREEN%^wiry plants%^RESET%^ line either side of the path, struggling "
"to grow in the sandy soil.",
     "cliff":"Far to the north rises the sheer face of a rocky cliff, overshadowing your steps.",
     ({"ships","boats"}):"Occasionally a boat sails across the water, as it enters or leaves the docks.",
     ({"water","ocean","sea","waves"}):"In the distance to the south, you can see the %^BLUE%^%^BOLD%^waves "
"%^RESET%^of the ocean, stretching as far as the eye can see."
    ]));

   set_exits(([
     "west":COVE"path10",
     "northeast":COVE"path12"
   ]));
}
