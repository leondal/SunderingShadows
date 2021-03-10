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
%^RED%^You are standing on a small stretch of beach with very coarse sand and gravel beneath your feet. The melodic crashing of the waves seems sorrowful, as if the sea were weeping and only you could hear. A few grassy plants cling to a natural stone %^ORANGE%^arch%^RED%^ that rises overhead. %^CYAN%^The ocean meets the land to the north and west.%^RESET%^");
   set_listen("default", "The waves crash sorrowfully against the rocky coastline!");
       set_exits(([
    "south" : "/d/islands/common/aramanth/room15",
       "east" : "/d/islands/common/aramanth/room17",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "arch" : "It is a natural stone formation that is extremely immense.",
    "plants" : "They are small grassy plants that cling to the rock with powerful roots and draw moisture from the air.",
    "formation" : "It looks like a giant lion peering hungrily down at you from nearly a hundred feet above you.",
    "rocks" : "The rocks here are very jagged.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/bwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,3);
}
