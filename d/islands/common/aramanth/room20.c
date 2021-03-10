#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
    set_short("%^ORANGE%^The rugged terrain of %^WHITE%^A%^BOLD%^%^ORANGE%^r%^BLACK%^a%^WHITE%^m%^ORANGE%^a%^RESET%^n%^ORANGE%^t%^BOLD%^h %^RESET%^%^ORANGE%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^ORANGE%^The rugged terrain of %^WHITE%^A%^BOLD%^%^ORANGE%^r%^BLACK%^a%^WHITE%^m%^ORANGE%^a%^RESET%^n%^ORANGE%^t%^BOLD%^h %^RESET%^%^ORANGE%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^ORANGE%^You are on a sandy beach. The soft sand is very fine and your feet sink deeply into it leaving irrecognizable footprints behind. Further movement to the west is rendered impossible by a several hundred foot cliff. The cliff curves around the beach and rises to a summit just north of your current position. %^BLUE%^The ocean meets the land here at the beach.
");
   set_listen("default", "Waves gently break against the beach.");
       set_exits(([
    "east" : "/d/islands/common/aramanth/room24",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "rocks" : "The rocks here are very jagged.",
    "formation" : "It looks almost perfectly like a sobbing boy if you look at it from just the right angle.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/bwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,3);
}
