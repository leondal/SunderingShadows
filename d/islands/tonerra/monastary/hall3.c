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
%^RESET%^This hall way is lit by dim %^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^l%^BOLD%^ic%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%^in%^RESET%^%^ORANGE%^g %^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^rc%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^WHITE%^. The dark stone
is worn from centuries of use. One of the %^BOLD%^%^BLACK%^bricks %^RESET%^on the east
wall is less dusty than the rest. The chants are loud here.
Your footsteps echo in the walkway. Worn %^MAGENTA%^tapestries%^WHITE%^
portraying %^BOLD%^%^GREEN%^lovely hills %^RESET%^and %^CYAN%^ancient places %^WHITE%^hang on the walls.
OLI
);

   set_smell("default","Incense is being burned all around.");
   set_listen("default","Your heavy footsteps echo no matter how carefully you walk. A mournful sobbing comes from behind the wall to the east.");

   set_exits(([
      "north":MONASTERY+"hall4",
      "south":MONASTERY+"hall2"
      ]));

   set_items((["brick":"This brick seems to be slightly worn with use, some of the mortar has crumbled."]));

}

void init(){
   ::init();
   do_random_encounters(({MON+"monk"}),50,4);

   add_action("push","push");
}

int push(string str){

   if(!str || str != "brick") return notify_fail("push what?\n");

   write("With effort you push the smoothed brick inward.");

   tell_room(TO,"A section of the wall to the east slides open.");

   add_exit(MONASTERY+"m4","east");
   return 1;
}


void reset(){
   ::reset();

   remove_exit("east");
}

