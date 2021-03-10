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
%^RED%^You have climbed to the summit of a small peak. You can see tiny ribbons of the blue ocean through breaks in the numerous jagged peaks. The entire area is grey from the shale of crumbling %^WHITE%^formations. %^CYAN%^The o%^BOLD%^%^WHITE%^ce%^CYAN%^a%^RESET%^%^CYAN%^n c%^BOLD%^r%^WHITE%^a%^RESET%^sh%^BOLD%^e%^CYAN%^s %^RESET%^%^CYAN%^against %^RED%^rocks %^CYAN%^to the north of you.%^WHITE%^
");
   set_listen("default", "The waves strike against the jagged cliff!");
       set_exits(([
       "south" : "/d/islands/common/aramanth/room37",
      "west" : "/d/islands/common/aramanth/room32",
      "east" : "/d/islands/common/aramanth/room34",
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
  do_random_encounters(({"/d/islands/common/mon/necrophidius.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,4);
}
