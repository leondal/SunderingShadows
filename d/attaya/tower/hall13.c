
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Meetingplace");
        set_long("
    This is a meetingplace.  A long black table lies at the center of a large room with wood panel walls.  A dim light enters the room from a groove that runs around the wall just above the floor.  
    The ceiling is pitch black as no light hits it!
");
       set_exits(([
       "north" : "/d/attaya/tower/hall10",
]));
       set_items(([
    "ceiling" : "It is too dark to see.",
    "groove" : "The groove is cut into the wall all the way around the room only inches above the floor.",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.  It is stained with blood.",
    "sculptures" : "The polished silver sculptures are very tall and loom out over the hallway making partial arches above you.  They look like representations of a woman lunging forward, but the image is stretched out and very thin.",
    "walls" : "The walls are comprised of decorated tiles.",
     "bloodstain" : "The carpet beneath one of the sculptures is bloodstained.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void reset(){
        ::reset();
    if(!present("chair"))
     new("d/attaya/obj/chair")->move(this_object());
if(!present("chair 6"))
     new("d/attaya/obj/chair")->move(this_object());
      if(!present("chair 6"))
     new("d/attaya/obj/chair")->move(this_object());
      if(!present("chair 6"))
     new("d/attaya/obj/chair")->move(this_object());
      if(!present("chair 6"))
     new("d/attaya/obj/chair")->move(this_object());
      if(!present("chair 6"))
     new("d/attaya/obj/chair")->move(this_object());
      if(!present("table"))
     new("d/attaya/obj/table")->move(this_object());
}
