#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(ROCKY);
	set_travel(FRESH_BLAZE);
       set_short("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^RED%^You stand at the base of an enormous cliff. A ladder has been lowered over the side and seems to be the only way up to a large plateau that is nearly as high as this entire island is wide. The island grows rocky again to the south. %^CYAN%^The o%^BOLD%^%^WHITE%^ce%^RESET%^%^CYAN%^a%^BOLD%^n %^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^p%^CYAN%^rout%^RESET%^%^CYAN%^s en%^WHITE%^d%^BOLD%^%^CYAN%^le%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^s%^RESET%^%^CYAN%^ly %^BOLD%^%^WHITE%^b%^RESET%^%^CYAN%^e%^BOLD%^fo%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^e %^RESET%^%^CYAN%^y%^BOLD%^ou%^RESET%^%^ORANGE%^. A small sandbar lies to the southwest. ");
   set_listen("default", "Waves break against the rocky beach with a crash.");
       set_exits(([
   "up" : "/d/islands/common/aramanth/room12",
       "south" : "/d/islands/common/aramanth/room14",
       "southwest" : "/d/islands/common/aramanth/room29",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "netting" : "It is heavily rusted and was probably a heavy duty cargo net of some kind.",
    "rocks" : "The rocks here are very jagged.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/gwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,3);
}
