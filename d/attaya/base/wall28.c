
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Inside the walls of the Tower of the Black Dawn.");
     set_long("
    This is the southwest guard tower.  Benches are built into all four walls, and fireing slits have been cut in the floor and the walls.  An empty weapon rack is built into the north wall.
");
    set_smell("default","There is a strange odor in the air, almost like some sort of spice.");
    set_listen("default","Your footsteps echo loudly through the halls.");

    set_exits( ([
    "down" : "/d/attaya/base/wall22",
        ]) );
    set_items(([
    "windows" : "The entire inner wall is made of glass to display the beautiful crystalline tower outside.",
    "pool" : "The reflecting pool is crystal clear and reflects the crystalline tower."
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
