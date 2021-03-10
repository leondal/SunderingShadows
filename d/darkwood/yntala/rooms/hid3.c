#include <std.h>
#include "../yntala.h"
inherit CROOM;

void create(){
::create();
  set_property("indoors",1);
  set_property("light",-1);
  set_property("no_teleport",1);
  set_travel(RUBBLE);
  set_terrain(ROCKY);
  set_name("%^RESET%^%^ORANGE%^The edge of an underground spring");
  set_short("%^RESET%^%^ORANGE%^The edge of an underground spring");
  set_long("%^RESET%^%^ORANGE%^This is a narrow, %^BOLD%^%^BLACK%^dark, %^RESET%^%^ORANGE%^cavern that abruptly ends"
" to the east.  Smooth cave walls arch up into a high ceiling, where you can"
" just make out the %^RESET%^faint glow %^ORANGE%^of hanging %^RESET%^stalactites, %^ORANGE%^giving hint as to "
" where the steady drip of %^BLUE%^cold water %^ORANGE%^comes from.  %^ORANGE%^The cavern floor"
" is really uneven and difficult to maneuver due to the many large, %^CYAN%^water-filled %^ORANGE%^holes and"
" abundance of large rocks and boulders laying about. Almost completely hidden by the %^BOLD%^%^BLACK%^shadows, "
"%^RESET%^%^ORANGE%^a gushing, underground %^CYAN%^waterfall %^ORANGE%^dives into a large pool of %^BLUE%^dark water"
" %^ORANGE%^at the caverns edge.\n");
  set_smell("default","%^ORANGE%^The caverns carry with them a light, musty smell along with the faint scent of bat guano.%^RESET%^");
  set_listen("default","%^CYAN%^The sound of dripping water echoes through the cavern.");
  set_items(([
     ({"floor","cave floor"}):"%^RESET%^%^ORANGE%^The cave floor is rocky and uneven. Puddles of water fill small holes in the %^BOLD%^%^BLACK%^rocks.%^RESET%^",
     ({"shadow","shadows"}):"%^BOLD%^%^BLACK%^Shadows line the edges of the cave, making it difficult to see what may be hiding there.",
      "cracks":"%^RESET%^Cracks line the floor and walls here, making a good place for small creatures to hide.",
      ({"puddles","puddles of water"}):"%^BLUE%^Puddles of stagnant, smelly water fill small holes in the cave floor.",
      "rocks":"%^RESET%^Rocks and large boulders of various sizes lay about the cave.",
      ({"walls","cave walls"}):"%^RESET%^%^BLUE%^The cavern walls are smooth to the touch.  Small %^RESET%^stalagnites %^RESET%^can be seen hanging from the ceiling.",
      "ceiling":"%^BOLD%^%^BLACK%^It is difficult to see the ceiling from here, and the %^RESET%^faint glow %^BOLD%^%^BLACK%^%^of %^RESET%^stalagnites %^BOLD%^%^BLACK%^can barely be made out.%^RESET%^",
      "water":"%^RESET%^%^CYAN%^The waters edge here is stagnate and unmoving, though appears to be fairly deep.%^RESET%^",
]));
   set_search("shadows","%^BOLD%^%^BLACK%^You sigh in relief as you search the shadows and find nothing.%^RESET%^");
   set_exits(([
        "pool":INRMS+"hid2",
        "west":INRMS+"hid4"
]));
}
