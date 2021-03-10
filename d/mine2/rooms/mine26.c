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
"%^GREEN%^BOLD%^"
"As you enter, you notice all the plant life growing in this room.  "
"There are small bushes, trees, and fungi growing all over it.  " 
"There are a few places whereo some little gold chunks are sitting on the ground.  "
"There is some thing different about this room, than any other, and it is not " 
"the fact that there is accually life in here. "
"");

     set_listen("default","You hear something move.");
     set_smell("default","You smell fresh flowers.");

    set_exits(([
      "south" : "/d/mine2/rooms/mine21",


    ] ));
    set_items(([
         "cavern" : "It is filled with plant life.",
         "plants" : "There are several types of plants here, but the roses stand out the most.",
         "trees" : "The trees are about 6 feet high, and are in their blooming season.",
         "shaft" : "It filled with plant life.",
         "gold" : "There are just little gold chunks, nothing big enough to trade in.",
         "roses" : "There are sitting right by a beam of light is.",
         "beam" : "The beam is made out of light, and it is comming through a large hole.",
         "hole" : "The hole is quite large, and you could probably exit through it.", 
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
