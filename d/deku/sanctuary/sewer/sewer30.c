#include <std.h>
#include "../dragon.h";

inherit "/std/vault";

void create() {
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
      " filled with many strange but interesting objects. This section of the"+
      " tunnel ends here. The walls are black and covered with disgusting"+
      " slime mold from the many decades of sewage that has flowed within here."
    );
    set_exits(([
       "down" : SEWER+"sewer41",
       "west" : SEWER+"sewer29"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary.",
    ] ));
    set_smell("default","The smell of stagnant water assaults your senses.");
    set_listen("default","There is only silence here.");
    set_terrain(SHALLOW_WATER);
    set_travel(SLICK_FLOOR);
    set_search("default","You search through the human waste and find a closed grate under the water.");
    set_open("grate", 0);
    set_locked("grate", 1);
    set_invis_exits(({"down"}));
    set_property("no teleport", 1);
    set_door("grate",SEWER+"sewer41","down",0);
    set_string("grate","open","The grate opens up, leading further into the sewers.");
    set_door_description("grate", "The grate is old and rusty. It is under the human waste and slime.");
}

