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
%^RED%^Tall rock formations surround you. The entire area is grey from the shale of crumbling formations. Some of the stone structures form arches and spindles far above you giving you the feeling of being inside a natural castle. A natural wall of rock forms a cliff to the south that runs for a good distance to the east. %^BLUE%^The ocean meets the land to the north.
");
   set_listen("default", "You hear an almost musical whistling!");
       set_exits(([
       "west" : "/d/shadow/virtual/sea/aramanth.dock",
       "east" : "/d/islands/common/aramanth/room7",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "rocks" : "The rocks here are very jagged.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/bwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,3);
}
