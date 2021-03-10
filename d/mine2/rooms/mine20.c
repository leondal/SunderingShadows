#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
          ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^ORANGE%^ "
"This shaft is towards the middle of the mountain.  The room is very dark " 
"which makes it hard for most people to see in it.  There are many water puddles "
"that have been formed by driping water and the little stream running through "
"the shaft.  There are little pieces of rock, that look like they might have come "
"off the top of the room, durring a rock slide.");

     set_listen("default","You hear the sloshing of water.");
     set_smell("default","You smell fresh water.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine21",
       "north" : "/d/mine2/rooms/mine18",
    ] ));
    set_items(([
         "water" : "It appears to be fresh water, and you could probably drink it.",
         "puddles" : "The puddles are filled with dirty water.",
         "rock" : "The pieces of rock look like they have fallen off the ceiling durring a very wild rock slide.",
         "shaft" : "It is filled with water puddles, and rock that has fallen from the ceiling.",
         "drips" : "The drips are caused by water running through a small stream that goes through the mountain.",
         "darkness" : "It is so dark, that most people can't see.",
         "mountain" : "You are accaully about in the middle of it.",
         "ground" : "It is covered with rock.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
