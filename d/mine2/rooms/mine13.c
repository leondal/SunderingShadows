#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
           ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^BLUE%^ "
"The shaft is filled with water.  The water goes up to your ankles, and makes "
"your feet start to tingle from the water.  There are several large rocks that "
"stand above the water, that you use like steping stones.  There are not to many "
"things that stand out, but you should probably take a closer look.  "
"");

     set_listen("default","You hear water draining.");
     set_smell("default","You you do not smell anything strange.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine12",
       "east" : "/d/mine2/rooms/mine14",
    ] ));
    set_items(([
         "cavern" : "It is small, and filled with water.",
         "water" : "It is up to your ankles, and draining slowly.",
         "marks" : "The marks are from picks  from earlier tried to get gold.",
         "shaft" : "It is small, and filled with water.",
         "gold" : "You can't not see any right off.",
         "rock" : "There is several rocks that are like steping stones.",
         "stones" : "They are accually little rocks.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
