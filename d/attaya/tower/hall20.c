
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Within the Kinnesaruda fortress.");
        set_long("
    This is a small study room.  A thick glass table sits between two marble benches.  You also have a sudden feeling of mortal dread.
    The walls are made from various tiles and are covered in places by pictures and green parchment.
");
       set_exits(([
       "west" : "/d/attaya/tower/hall19",
]));
       set_items(([
    "ceiling" : "The ceiling is made from wooden panels in here.",
    "walls" : "Large sheets of green parchment cover the walls.",
      "paintings" : "The paintings are all of distand lands.",
    "floor" : "The floor is made from square wooden tiles.",
]));
	
}
void reset(){
        ::reset();
    if(!present("io"))
     new("d/attaya/mon/poltergeist")->move(this_object());
     new("d/attaya/mon/poltergeist")->move(this_object());
     new("d/attaya/mon/poltergeist")->move(this_object());
     new("d/attaya/mon/poltergeist")->move(this_object());
     new("d/attaya/mon/poltergeist")->move(this_object());
    if(!present("bench"))
     new("d/attaya/obj/bench")->move(this_object());
    if(!present("bench"))
new("d/attaya/obj/bench")->move(this_object());
    if(!present("table"))
     new("d/attaya/obj/table2")->move(this_object());
    if(!present("io"))
     new("d/attaya/mon/io")->move(this_object());
}
