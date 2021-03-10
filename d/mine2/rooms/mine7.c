#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^CYAN%^ "
"This shaft is half filled with water.  You have to stand tall so that you "
"do not go under the water.  There is some type of whirlpool that you need "
"to stay away from, or else you may die.  There is some kind of animal that "
"is swiming in the water, but you do not want to get to close, or else it " 
"may bite you.");

     set_listen("default","You hear a whirlpool.");
     set_smell("default","You smell fish.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine5",
       "south" : "/d/mine2/rooms/mine12",
    ] ));
    set_items(([
         "cavern" : "It is filled with water.",
         "water" : "It is very deep, and you have to stand up tall, so that you do not go under.",
         "whirlpool" : "The whirlpool is in the far corner, and is VERY dangeroud if you get close to it.",
         "shaft" : "It is filled with water.",
         "gold" : "The water id to deep to tell if there is gold in this room.",
         "pool" : "It is dangerous.",
         "ground" : "You can not see thr ground because water convers it.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
