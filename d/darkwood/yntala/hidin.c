#include <std.h>

#include "yntala.h"
inherit CROOM;

void create(){
::create();
  set_property("indoors",1);
  set_property("light",-1);
  set_property("no_teleport",1);
  set_travel(RUBBLE);
  set_terrain(ROCKY);
  set_name("%^RESET%^%^ORANGE%^Within an underground cavern");
  set_short("%^RESET%^%^ORANGE%^Within an underground cavern");
  set_long("%^RESET%^%^ORANGE%^This is a narrow, %^BOLD%^%^BLACK%^dark, %^RESET%^%^ORANGE%^cavern that twists"
" it's way beneath the earth's surface, and appears to have been made by natural causes.  No dig marks or signs"
" of shoring can be seen on the smooth walls.  %^BLUE%^Cold water %^ORANGE%^constantly drips from the high ceilings"
" whose lowest points are the only parts visible through the %^BOLD%^%^BLACK%^dark shadows %^RESET%^%^ORANGE%^that are"
" more than abundant down here.   The stagnate air leaves no room for growth, and the lack of any signs of life leads"
" one to believe that hanging around too long might not be such a good idea.  A %^BLUE%^cold, moist chill"
" %^ORANGE%^runs through the corridor, though it's origin is nearly impossible to detect.\n");
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
]));
   set_search("shadows","%^BOLD%^%^BLACK%^You sigh in relief as you search the shadows and find nothing.%^RESET%^");
}