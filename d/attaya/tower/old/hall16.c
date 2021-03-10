
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Within the Kinnesaruda fortress.");
        set_long("
    This room seems to be a bedroom.  A few dressers lean against the walls, and a large bed sits in the center of the room.  The walls are made from the same green parchment that was in the preceding hallway.
    A glass sphere sits by the bed on the floor.
");
       set_exits(([
       "east" : "/d/attaya/tower/hall17",
]));
       set_items(([
    "ceiling" : "The ceiling is made from wooden panels in here.",
    "walls" : "Large sheets of green parchment cover the walls.",
    "floor" : "The floor is made from square wooden tiles.",
    "sphere" : "A remarkable crystal sphere lies by the bed on the floor.  It seems to have no purpose.",
    "bed" : "It is a twin size bed with white sheets and a blue comforter.",
    "dressers" : "They are about 6 feet tall and have 8 drawers each.",
]));
	
}
void reset(){
        ::reset();
    if(!present("banisher"))
     new("d/attaya/mon/banisher")->move(this_object());
}
