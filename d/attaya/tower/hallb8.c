
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
   ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Mysterious passage within the Kinnesaruda fortress");
        set_long("
    This is a small brick passageway just wide enough for one person to walk through.  The walls are smooth and made from dark gray marble tiles as is the floor.  A small room lies to the north.  The doorway is marked with blood and strange symbols.
    The hallway turns here and becomes quite narrow to the west.  You have to really squeeze to get through there.
");
       set_exits(([
       "north" : "/d/attaya/tower/hallb6",
       "west" : "/d/attaya/tower/hallb7",
]));
       set_items(([
    "floor" : "It is made of dark gray marble tiles.",
    "doorway" : "The sturdy pine frame stands here almost uselessly.  It barely fits the hallway, and you can reach your hand through the gaping hole between the frame and the wall.  Several strange symbols are carved in the frame.",
    "symbols" : "You have seen them on the attire of the Kinnesaruda Warlocks!",
    "blood" : "The blood is here as a warning.",
    "walls" : "They are made of dark gray marble tiles.",
    "ceiling" : "It is made of white planks.",
]));

}
void reset(){
        ::reset();
    if(!present("warlock") && !random(3)) {
      new("d/attaya/mon/warlock")->move(this_object());
      new("d/attaya/mon/poltergeist")->move(this_object());
    }
}
