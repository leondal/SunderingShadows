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
"%^BOLD%^"
"As you enter the room, you notice a small tree growing in the corner.  "
"The tree is about 9 feet tall, and is loosing it's leaves.  The room is very warm "
"but not to warm.  There is a small stream running down the center of the shaft "
"making the room look very calming.  There is not even a single rock or piece "
"of gold anywhere in this room.  You call this room the room of glory, because of "
"it's great buity. "
"");

     set_listen("default","You hear the stream girgle.");
     set_smell("default","You smell fresh the tree's perfurm.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine15",
    ] ));
    set_items(([
         "cavern" : "There is a large tree in the center of the room.",
         "tree" : "It stands tall, but it is loosing it's leaves.",
         "stream" : "The stream runs through the center of the room.",
         "shaft" : "It is very calm and peacefull.",
         "gold" : "There is not any gold in this room.",
         "leaves" : "They are starting to fall off of the tree.",
         "beam" : "The beam is made out of light, and it is comming through a large hole.",
         "rocks" : "There are not any rocks in the room.", 
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
