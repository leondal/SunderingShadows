
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
    ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Inside the heart of the Kinnesaruda");
        set_long("
    You are on a balcony overlooking the main hall.  The balcony curves around the staircase in the center of the room.  The grand staircase splits into two separate staircases about midlevel, and you stand at the mouth of the right portion.  
The room is lit by candles, and a few paintings hang from the walls.  Hallways lead east and west from here.
");
       set_exits(([
       "west" : "/d/attaya/tower/hallc11",
       "east" : "/d/attaya/tower/hallc13",
]));
       set_items(([
    "ceiling" : "It is a vaulted plaster ceiling!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "candles" : "red candles hang in holders that jut from the walls like hands.  They have hardly burned down meaning that they were probably lit recently.",
    "paintings" : "The paintings are portraits of people.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
