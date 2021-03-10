#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
    set_short("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^RED%^Several stalagtite like %^ORANGE%^formations%^ORANGE%^ rise from the beach here. They range in height from four to over thirty feet in height. Several of the tallest ones have collapsed and lie in round fragments against a cliff wall. You begin to realize that this whole island used to be a cave somehow. Coarse sand at your feet is mixed with gravel-like fragments and large stones alike. %^BLUE%^The ocean meets the land to the east.
");
   set_listen("default", "Waves break against the rocky beach with a crash.");
       set_exits(([
   "north" : "/d/islands/common/aramanth/room21",
   "south" : "/d/islands/common/aramanth/room23",
       "west" : "/d/islands/common/aramanth/room18",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "netting" : "It is heavily rusted and was probably a heavy duty cargo net of some kind.",
    "rocks" : "The rocks here are very jagged.",
    "formation" : "It looks almost perfectly like a sobbing boy if you look at it from just the right angle.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/rwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,3);
}
