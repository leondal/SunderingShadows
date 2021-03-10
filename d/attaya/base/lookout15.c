
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("South Wall Fortress lookout.");
    set_long("
    You are high in the walls of the southern fortress, in a lookout designed to allow archers clear shots of the main hall.
    A wooden bench here is all that seperates the hallway you are standing in from a multi-story drop!  The walls around you glisten with a blueish moss.
");
    set_smell("default","The air smells of mildew and decay.");
    set_listen("default","The screaming wyverns can be heard from up here.");

    set_exits( ([
    "south" : "/d/attaya/base/lookout14",
        ]) );
    set_items(([
    "windows" : "The entire inner wall is made of glass to display the beautiful crystalline tower outside.",
    "pool" : "The reflecting pool is crystal clear and reflects the crystalline tower.",
    "walls" : "The walls are made from ancient bricks that crack and strain beneath the weight of the fortress...  They are covered by a blueish moss.",
    "moss" : "The soft bluish moss clings to the walls and seems to glisten.",
    ]));

}
void reset(){
   object mon;
   ::reset();

    if(!present("archer")) {
         mon = new("/d/attaya/mon/archer");
	mon->set_id( ({"archer", "guard"}) );
	mon->move(this_object());
   }

}
