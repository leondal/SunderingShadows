
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Hallway of arches");
        set_long("
    A tall hallway lined with arches runs west and east.  White wooden planks that start at the floor run up the walls, parallel with the hall.  They start to bend over the roof about twelve feet above, and the ceiling's highest point is about sixteen feet above you. 
    A rather unimpressive door on the south wall is painted white like the walls.  It almost fails to catch your eye.
");
       set_exits(([
       "east" : "/d/attaya/tower/hallb3",
       "west" : "/d/attaya/tower/hallb12",
      "south" : "/d/attaya/tower/hallb10",
]));
       set_items(([
    "ceiling" : "The same wooden planks that make up the walls follow the curvature of the arches and wrap over the hallway, continuously to the other side!",
    "floor" : "The floor here is made up of dark gray polished marble tiles.",
    "door" : "It is a plain white wooden door.",
    "arches" : "The arches hold up a curved ceiling of long white wooden planks.  They protrude from the wall to a distance of about six inches.",
    "planks" : "The white wooden planks run from arch to arch parallel to the floor.  Their ends are hidden behind the arches, giving the illusion that they are continuous in length.",
    "tiles" : "They are marble tiles, dark gray in color.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
