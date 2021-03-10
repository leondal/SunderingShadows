#include <std.h>

inherit ROOM;

void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(SHALLOW_WATER);
	set_travel(FRESH_BLAZE);
    set_short("%^BOLD%^%^CYAN%^A la%^WHITE%^g%^BLACK%^o%^RESET%^o%^CYAN%^n of %^WHITE%^c%^BOLD%^%^CYAN%^r%^WHITE%^y%^BLACK%^s%^CYAN%^t%^WHITE%^al %^BLACK%^c%^CYAN%^l%^WHITE%^e%^CYAN%^a%^RESET%^r %^CYAN%^water on %^ORANGE%^A%^BOLD%^r%^RESET%^%^ORANGE%^a%^BOLD%^m%^WHITE%^a%^ORANGE%^n%^BLACK%^t%^RESET%^%^ORANGE%^h %^BOLD%^I%^RESET%^%^ORANGE%^s%^BOLD%^l%^WHITE%^a%^BLACK%^n%^RESET%^%^ORANGE%^d.%^WHITE%^");
        set_long("%^BOLD%^%^CYAN%^A la%^WHITE%^g%^BLACK%^o%^RESET%^o%^CYAN%^n of %^WHITE%^c%^BOLD%^%^CYAN%^r%^WHITE%^y%^BLACK%^s%^CYAN%^t%^WHITE%^al %^BLACK%^c%^CYAN%^l%^WHITE%^e%^CYAN%^a%^RESET%^r %^CYAN%^water on %^ORANGE%^A%^BOLD%^r%^RESET%^%^ORANGE%^a%^BOLD%^m%^WHITE%^a%^ORANGE%^n%^BLACK%^t%^RESET%^%^ORANGE%^h %^BOLD%^I%^RESET%^%^ORANGE%^s%^BOLD%^l%^WHITE%^a%^BLACK%^n%^RESET%^%^ORANGE%^d.%^WHITE%^
%^CYAN%^You are standing in a small lagoon of crystal clear %^BOLD%^water %^RESET%^%^CYAN%^between Aramanth Island and a sandbar to the west.  A large rock %^RED%^f%^WHITE%^o%^RED%^rmat%^WHITE%^i%^RED%^on %^CYAN%^rises from the water just east of you and casts shadow over you.  The water is cool and refreshing as it flows past you.%^WHITE%^
");
   set_listen("default", "The ocean waves are somewhat relaxing as they lap against the sand..");
       set_exits(([
    "north" : "/d/islands/common/aramanth/room29",
    "south" : "/d/islands/common/aramanth/room35",
    "west" : "/d/islands/common/aramanth/room30",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "channel" : "The waters are very shallow, crystal clear, and move at a snail's pace.",
    "water" : "It is crystal clear.",
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
