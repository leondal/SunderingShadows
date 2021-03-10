
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
    ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Inside the heart of the Kinnesaruda");
        set_long("
    You are on a balcony overlooking the main hall.  The balcony curves around the staircase to the east.  The grand staircase splits into two separate staircases about midlevel, and you stand at the mouth of the left portion.  
    The room is lit by candles, and a few paintings hang from the walls.  Hallways lead south from here, and east at the opposite side of the room.
");
       set_exits(([
       "south" : "/d/attaya/tower/hallc6",
       "east" : "/d/attaya/tower/hallc12",
       "staircase" : "/d/attaya/tower/staircase"
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
