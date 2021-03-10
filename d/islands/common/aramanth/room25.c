#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(ROCKY);
	set_travel(FRESH_BLAZE);
    set_short("%^GREEN%^The rugged terrain of %^WHITE%^A%^BOLD%^%^GREEN%^r%^BLACK%^a%^WHITE%^m%^GREEN%^a%^RESET%^n%^GREEN%^t%^BOLD%^h %^RESET%^%^GREEN%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^GREEN%^The rugged terrain of %^WHITE%^A%^BOLD%^%^GREEN%^r%^BLACK%^a%^WHITE%^m%^GREEN%^a%^RESET%^n%^GREEN%^t%^BOLD%^h %^RESET%^%^GREEN%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^GREEN%^The land here slopes downwards to a sandy beach to the southwest. A few grassy %^ORANGE%^plants%^GREEN%^ cling defiantly to the bare stone around you at this, the easternmost tip of the island. A rock %^ORANGE%^formation%^GREEN%^ that is built into a huge cliff to the north resembles a lion preparing to leap down upon you. A natural wall of rock forms a cliff to the west that runs for a good distance away from you. %^BLUE%^The ocean meets the land to the north, east, and southeast.
");
   set_listen("default", "The wind whistles through the arches and grottos!");
       set_exits(([
    "west" : "/d/islands/common/aramanth/room23",
       "southwest" : "/d/islands/common/aramanth/room24",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "plants" : "They are small grassy plants that cling to the rock with powerful roots and draw moisture from the air.",
    "formation" : "It looks like a giant lion peering hungrily down at you from nearly a hundred feet above.",
    "rocks" : "The rocks here are very jagged.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/bwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,6);
}
