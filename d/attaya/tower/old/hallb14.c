
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Hallway of arches");
        set_long("
    The tall hallway lined with arches ends against a stone fireplace here.  White wooden planks that start at the floor run up the walls, parallel with the hall.  The stones that make up the fireplace are painted white, and a copper gate blocks off the fireplace opening itself. 
    A smaller arch on the east wall leads into a grand room.
");
       set_exits(([
       "north" : "/d/attaya/tower/hallb13",
       "east" : "/d/attaya/tower/hallb15",
]));
       set_items(([
    "ceiling" : "The same wooden planks that make up the walls follow the curvature of the arches and wrap over the hallway, continuously to the other side!",
    "fireplace" : "The large fireplace takes up the entire southern wall.  It is built of white, painted stones, and sealed off with a copper gate.  The cindered remains of something lie inside.",
    "gate" : "A greenish copper gate is fastened securely to the fireplace over the opening.",
    "remains" : "It is hard to tell what blackened form lies within the ashes of the fireplace...  You think you can make out the outline of a few bones amidst the charred remains.",
    "floor" : "The floor here is made up of dark gray polished marble tiles.",
    "arches" : "The arches hold up a curved ceiling of long white wooden planks.  They protrude from the wall to a distance of about six inches.",
    "stones" : "The stones around the fireplace have been painted white.",
    "planks" : "The white wooden planks run from arch to arch parallel to the floor.  Their ends are hidden behind the arches, giving the illusion that they are continuous in length.",
    "tiles" : "They are marble tiles, dark gray in color.",
    "bones" : "You can only see the white edges beneath black ash and debris.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
