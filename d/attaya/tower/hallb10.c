
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Mysterious passage within the Kinnesaruda fortress");
        set_long("
    This is a small brick passageway just wide enough for one person to walk through.  The walls are smooth and made from dark gray marble tiles as is the floor.
    The hallway curves to the east just south of here.
");
       set_exits(([
       "north" : "/d/attaya/tower/hallb11",
       "south" : "/d/attaya/tower/hallb9",
]));
       set_items(([
    "floor" : "It is made of dark gray marble tiles.",
    "walls" : "They are made of dark gray marble tiles.",
    "ceiling" : "It is made of white planks.",
]));
	
}
void reset(){
   ::reset();
   if(!present("banisher")) {
     new("d/attaya/mon/banisher")->move(this_object());
     new("d/attaya/mon/poltergeist")->move(this_object());
   }
}
