
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 1, "indoors" : 1 ]) );
    set_short("Inside the walls of the South Wall Fortress.");
    set_long("
    The dust hangs heavy in the air in here.  The dark, gloomy, undecorated tunnel better fits the Kinnesaruda than the magnificent tower!
    The cobwebs in here form natural tapestries.  The bricks are old, cracked, and worn, and there is a shriveled black mass of rot and decay on the floor at your feet...  It used to be a carpet!
");
    set_smell("default","The air smells of mildew and decay.");
    set_listen("default","Your footsteps echo loudly through the halls.");

    set_exits( ([
    "west" : "/d/attaya/base/lookout7",
    "east" : "/d/attaya/base/lookout9",
        ]) );
    set_items(([
    "windows" : "The entire inner wall is made of glass to display the beautiful crystalline tower outside.",
    "walls" : "The walls are built of ancient stone bricks that crumblke and crack now beneath the weight of the fortress.",
    "floor" : "The floor, made of granite tiles, is covered by rotten decaing masses of black carpet.",
    "carpet" : "It is completely decayed.",
    "pool" : "The reflecting pool is crystal clear and reflects the crystalline tower."
    ]));

}
void reset(){
   object mon;
   ::reset();

    if(!present("warrior")) {
         mon = new("/d/attaya/mon/uwarrior");
	mon->move(this_object());
   }

}
