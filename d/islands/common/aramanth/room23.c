#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(ROCKY);
	set_travel(LEDGE);
       set_short("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^RED%^Your footing here is very unsure as you climb from jagged boulder to jagged boulder over chasms deep enough to cause you severe agony if you were to slip into one. The entire area is grey from the shale of crumbling %^ORANGE%^formations%^RED%^. Some of the stone structures form arches and spindles far above you giving you the feeling of being inside a natural castle. A natural wall of rock forms a cliff to the south that runs for a good distance to the west.
");
  set_listen("default", "The wind whistles somewhere to the west.");
       set_exits(([
       "north" : "/d/islands/common/aramanth/room22",
      "west" : "/d/islands/common/aramanth/room19",
      "east" : "/d/islands/common/aramanth/room25",
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
  do_random_encounters(({"/d/islands/common/mon/bwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/necrophidius.c"}),30,4);
}
