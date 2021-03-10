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
"%^BOLD%^ORANGE%^ "
"This mine shaft is very cold and odd.  There are many things in this room " 
"that do not fit together.  One thing is why water is dripping from the top "
"of the room, but when it hits the floor, it vanishes!  Another things is the "
"reason that you see gold for on second, then it's just gone!  You do not feel "
"like you are still alive even!");

     set_listen("default","You hear a strange echo.");
     set_smell("default","You smell something odd.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine21",
       "out" : "/d/shadow/room/grassland/grass1.c",
    ] ));
 set_invis_exits( ({"out"}) );
    set_items(([
         "room" : "It is very small, and has a small hole, that could be an exit out.",
         "out" : "It is a way to get out of the mine!",
         "exit out" : "It is a way to get out of the mine!.",
         "hole" : "The hole apears to be an exit out.",
         "shaft" : "It is very small, and there is a small hole which could be a way out of the mine!",
         "gold" : "There is no gold that you notice right off.",
         "exit" : "The exit leads out of the mine!",
         "ground" : "There is a hole at one end.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
