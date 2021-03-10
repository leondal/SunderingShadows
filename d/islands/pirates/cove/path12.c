#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Bridge across a narrow cleft");
   set_short("Bridge across a narrow cleft");
   set_long("%^BOLD%^Bridge across a narrow cleft%^RESET%^\n"
"The path leads up to a sturdy %^ORANGE%^wooden bridge%^RESET%^ here, which is obviously maintained on a "
"regular basis.  It crosses a great cleft, at the bottom of which you can see a slender river, winding down "
"toward the sea.  The trail on this side of the bridge is little more than %^ORANGE%^dust%^RESET%^ and "
"%^BLACK%^%^BOLD%^gravel%^RESET%^, rough beneath your feet.  It is lined by %^GREEN%^light shrubbery%^RESET%^"
", struggling to grow in the sandy soil, though upon the far side there's only stone and rock to mark the "
"upward trail.  Further north, the face of a great cliff reaches up toward the %^CYAN%^%^BOLD%^sky%^RESET%^, "
"while southward you can make out a small village, and the great expanse of the %^BLUE%^%^BOLD%^ocean's waves"
"%^RESET%^.\n");
   set("night long","%^BOLD%^Bridge across a narrow cleft%^RESET%^\n"
"The path leads up to a sturdy %^ORANGE%^wooden bridge%^RESET%^ here, which is obviously maintained on a "
"regular basis.  It crosses a great cleft, at the bottom of which you can see a slender river, winding down "
"toward the sea.  The trail on this side of the bridge is little more than %^ORANGE%^dust%^RESET%^ and "
"%^BLACK%^%^BOLD%^gravel%^RESET%^, rough beneath your feet.  It is lined by %^GREEN%^light shrubbery%^RESET%^"
", struggling to grow in the sandy soil, though upon the far side there's only stone and rock to mark the "
"upward trail.  Further north, the face of a great cliff overshadows you as it reaches up toward the %^BLUE%^"
"dark sky%^RESET%^, while southward you can make out a small village, and the great expanse of the %^BLUE%^"
"%^BOLD%^ocean's waves%^RESET%^.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","You can hear the distant, crashing waves of the ocean.");

   set_items(([
     ({"village","settlement"}):"Just to the west, you can make out the buildings of a small settlement.",
     ({"trail","path","gravel"}):"The %^ORANGE%^dust%^RESET%^ and gravel upon the path crunches beneath your "
"feet.  It leads westward to what looks like a small village, and north toward a sturdy %^ORANGE%^wooden "
"bridge%^RESET%^, and the looming cliff-face above.",
     ({"bridge","sturdy bridge"}):"A well-maintained %^ORANGE%^wooden bridge%^RESET%^ crosses the cleft in "
"the ground here, granting access to the other side of the path.",
     ({"plants","shrubbery"}):"A few %^GREEN%^wiry plants%^RESET%^ line either side of the path, struggling "
"to grow in the sandy soil.",
     "cliff":"Far to the north rises the sheer face of a rocky cliff, overshadowing your steps.",
     ({"ships","boats"}):"Occasionally a boat sails across the water, as it enters or leaves the docks.",
     ({"water","ocean","sea","waves"}):"In the distance to the south, you can see the %^BLUE%^%^BOLD%^waves "
"%^RESET%^of the ocean, stretching as far as the eye can see."
    ]));

   set_exits(([
     "southwest":COVE"path11",
     "north":COVE"path13"
   ]));
}
