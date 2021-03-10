//hall1.c

#include <std.h>

#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

int open;


void create(){
   ::create();
   set_properties((["indoors": 1,"light":0, "used sticks":1]));
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("%^RED%^Dark hallway into the monastery%^RESET%^");
   set_long(
@OLI
   %^RED%^Dark hallway into the monastery%^RESET%^
%^RESET%^This hall way is lit by dim %^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^l%^BOLD%^ic%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%^in%^RESET%^%^ORANGE%^g %^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^rc%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^WHITE%^. One of the
torches wobbles slightly in its holder. The %^BOLD%^%^BLACK%^dark stone %^RESET%^is worn
from centuries of use. The chants grow stronger towards
the northeast. Your footsteps echo in the walk way. Worn %^MAGENTA%^tapestries%^WHITE%^
portraying %^BOLD%^%^GREEN%^lovely hills %^RESET%^and %^CYAN%^ancient places %^WHITE%^hang on the walls.
OLI
);

   set_smell("default","Incense is being burned all around.");
   set_listen("default","Your heavy footsteps echo no matter how carefully you walk.");

   set_exits(([
      "northeast":MONASTERY+"hall2",
      "southwest":MONASTERY+"entrance"
      ]));

   set_items((["torch":"One of the torches is loose against the wall as if it could be pulled."]));
   set_invis_exits(({"southeast"}));
}

void init(){
   ::init();
   do_random_encounters(({MON+"monk"}),75,4);

   add_action("pull","pull");
}

void reset(){
   ::reset();

   remove_exit("southeast");
   open = 0;
}

int pull(string str){

   if(!str || str != "torch") return notify_fail("Pull what?\n");

   write("You pull with great effort and the torch slides down and then jumps back into place.");

   tell_room(TO,"Your hear a slight grinding as something seems to slide to the southeast.\n The hanging on that wall flutters a little as air seems to flow.");

   add_exit(MONASTERY+"stairs1","southeast");

   return 1;

}
