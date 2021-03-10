#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
       set_short("%^RED%^The western point of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^RED%^The western point of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^ORANGE%^You stand at the westernmost point of Aramanth Island.  The %^WHITE%^clouds%^ORANGE%^ roll by at a lazy pace and suddenly you desire only solace here.  The soft sand is very fine and your feet sink deeply into it leaving irrecognizable footprints behind. %^BLUE%^The ocean surrounds you.%^RESET%^
");
   set_listen("default", "Waves gently break against the beach.");
       set_exits(([
    "east" : "/d/islands/common/aramanth/room2",
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
