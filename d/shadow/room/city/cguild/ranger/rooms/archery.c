#include <std.h>
#include "../ranger.h"
inherit ROOM;

void create(){
   ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(GAME_TRACK);
   set_property("light",2);
   set_property("indoors",0);
   set_property("no teleport",1);
   set_name("A leaf-shrouded walkway");
   set_short("%^RESET%^%^GREEN%^A leaf-shrouded walkway%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^A leaf-shrouded walkway%^RESET%^\n"
"%^CYAN%^The great trunk of the %^ORANGE%^World Tree %^CYAN%^offers an opening here, where one can walk out "
"onto the flattened surface of a %^ORANGE%^thick branch%^CYAN%^.  %^BOLD%^%^WHITE%^Li%^YELLOW%^gh%^WHITE%^t "
"%^RESET%^%^CYAN%^filters down from above through the thick canopy of %^GREEN%^le%^BOLD%^a%^RESET%^%^GREEN%^"
"ves%^CYAN%^, shedding dappled patterns across the tree's bark.  Scattered among the leaves and branches to "
"the north are many shooting targets, forming the renowned archery range known as the %^BOLD%^%^GREEN%^'green "
"alley'%^RESET%^%^CYAN%^.  Some of the targets are securely affixed to tree limbs, while others are only "
"loosely held and sway back and forth in the %^BOLD%^wi%^WHITE%^n%^CYAN%^d%^RESET%^%^CYAN%^, providing moving "
"targets that are more difficult to hit.\n%^RESET%^");
   set_smell("default","The sweet smell of fresh air and greenery surrounds you.");
   set_listen("default","The breeze hums through the tree's canopy, punctuated by the occasional twang of a bowshot.");

   set_items(([
      "targets":"%^RESET%^%^CYAN%^Archery targets have been secured among the various %^ORANGE%^branches "
"%^CYAN%^to the north.  Some are close while others are distant, and they range from steady targets to mobile "
"ones that sway in the %^BOLD%^wi%^WHITE%^n%^CYAN%^d%^RESET%^%^CYAN%^, making them difficult to hit.%^RESET%^",
      ({"branch","branches","limbs","leaves","walkway","canopy"}):"%^RESET%^%^CYAN%^This walkway leads out "
"from an opening in the %^ORANGE%^World Tree%^CYAN%^ into the open air.  A single thick %^ORANGE%^branch "
"%^CYAN%^offers footing, while a canopy of %^GREN%^le%^BOLD%^a%^RESET%^%^GREEN%^ves %^CYAN%^and limbs sheds "
"dappled %^BOLD%^%^BLACK%^shadows %^RESET%^%^CYAN%^throughout the light that filters down from above.%^RESET%^",
   ]));

   set_exits(([
      "tree":RROOM"hall2",
      "north":RROOM"arch1",
   ]));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   write("You realize it's probably not a good idea to climb up there.");
   return 0;
}

void reset(){
    ::reset();
   if(!present("rhoc")) 
	find_object_or_load(RNPC"rhoc")->move(TO);
}
