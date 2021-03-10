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
"%^BOLD%^MAGENTA%^ "
"This mine shaft is very cold.  There are many iceicles hanging from the "
"top of the room.  There is a stream that runs through the room, but it "
"for some reason is not frozen.  There are many rocks on the ground that look "
"like they are from when the miners chiped them off the walls.  There is a "
"larger rock in the center of the room.");

     set_listen("default","You hear ice cracking.");

     set_smell("default","You smell frozen things.");
    set_exits(([
       "north" : "/d/mine2/rooms/mine6",
       "south" : "/d/mine2/rooms/mine7",
        "down" : "/d/mine2/rooms/mine8",
       "west" : "/d/mine2/rooms/mine4",
    ] ));
    set_items(([
         "cavern" : "It is farly small, and is very cold.",
         "cold" : "It is caused by low tempratures.",
         "marks" : "The marks are from picks  from earlier tried to get gold.",
         "shaft" : "It is very cold, and many things are frozen.",
         "gold" : "You do not see any right now",
         "rock" : "There are several pieces of chiped rock on the ground.",
         "ground" : "it is covered with chiped rock.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
