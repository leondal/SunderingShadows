#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
       set_short("%^YELLOW%^T%^RESET%^%^ORANGE%^he eastern beach of %^WHITE%^A%^YELLOW%^r%^BLACK%^a%^WHITE%^m%^ORANGE%^a%^RESET%^n%^ORANGE%^t%^BOLD%^h %^RESET%^%^ORANGE%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^");
         set_long("%^YELLOW%^T%^RESET%^%^ORANGE%^he eastern beach of %^WHITE%^A%^YELLOW%^r%^BLACK%^a%^WHITE%^m%^ORANGE%^a%^RESET%^n%^ORANGE%^t%^BOLD%^h %^RESET%^%^ORANGE%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^
%^CYAN%^The waters of the %^BOLD%^o%^WHITE%^c%^RESET%^e%^BOLD%^a%^RESET%^%^CYAN%^n are moving in v%^BOLD%^i%^WHITE%^s%^RESET%^i%^BOLD%^b%^RESET%^l%^CYAN%^e %^BOLD%^cu%^RESET%^%^CYAN%^r%^BOLD%^r%^WHITE%^e%^CYAN%^n%^RESET%^%^CYAN%^ts from north to south. To the west, a jagged peak rises into a cloud of seaspray.%^WHITE%^
");
   set_listen("default", "The ocean waves are somewhat relaxing as they lap against the sand..");
       set_exits(([
    "west" : "/d/islands/common/aramanth/room33",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "rocks" : "The rocks here are very jagged.",
    "formation" : "It looks almost perfectly like a sobbing boy if you look at it from just the right angle.",
    "clouds" : "The clouds seem to take various shapes before your eyes.",
    "shapes" : "A slug on fire, A large blob, A fat lady coughing up a wicker chair, A dog with 3 legs, A glob, A table with some object stuck to the bottom of it, A dead squid, and A bunch of grapes.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/seadragon"}),35,1);
}
