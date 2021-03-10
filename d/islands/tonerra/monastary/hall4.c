         //hall2.c

#include <std.h>

#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;


void create(){
   ::create();
   set_properties((["indoors": 1,"light":0, "used sticks":1]));
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("%^RED%^Dark hallway into the monastery%^RESET%^");
   set_long(
@OLI
   %^RED%^Dark hallway into the monastery%^RESET%^
%^RESET%^This hall way is lit by dim %^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^l%^BOLD%^ic%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%^in%^RESET%^%^ORANGE%^g %^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^rc%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^WHITE%^. The %^BOLD%^%^BLACK%^dark stone%^RESET%^
is worn from centuries of use. The chants grow stronger towards
the north. Your footsteps echo in the walkway. Worn %^MAGENTA%^tapestries%^WHITE%^
portraying %^BOLD%^%^GREEN%^lovely hills %^RESET%^and %^CYAN%^ancient places %^WHITE%^hang on the walls.
OLI
);

   set_smell("default","Incense is being burned all around.");
   set_listen("default","Your heavy footsteps echo no matter how carefully you walk. A mournful sobbing comes from behind the wall to the east.");

   set_exits(([
      "north":MONASTERY+"hall5",
      "south":MONASTERY+"hall3"
      ]));
}

void init(){
   ::init();
   do_random_encounters(({MON+"monk"}),75,4);
}


