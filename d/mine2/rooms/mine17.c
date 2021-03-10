
#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
          ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^RED%^ "
"As you enter the mine shaft, you notice that there are several bodies laying " 
"on the ground, it lookat as though a mad miner took his anger out on his fellow "
" buddies.  You see blood all over the room, and there is not a single piece of "
"gold in sight.  You fel very alone, and do not want to stay here long. "
"");

     set_listen("default","You hear people moaning.");
     set_smell("default","You smell the decay of the bodies.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine19",
       "west" : "/d/mine2/rooms/mine14",
       "south" : "/d/mine2/rooms/mine18",
    ] ));
    set_items(([
         "cavern" : "It is filled with dead bodies.",
         "bodies" : "They have been utterly destroyed by a minine pick.",
         "blood" : "The pools of blood make a small puddle in one side of the room.",
         "shaft" : "It filled with dead bodies.",
         "gold" : "There is not any gold in sight.",
         "adventurer" : "He is dead on the ground.",
         "body" : "There is one body that stands alone, and it looks like one of your fellow adventurers.",
         "ground" : "It is covered withp p bodies.",
    ] ));
set_max_mining(1);
set_chance(2);
set_max_find(2);
set_nugget( ([ "1":1, ]) );
}

