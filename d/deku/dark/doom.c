#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    set_short("Chamber of Doom");
    set_long(
@KAYLA
The winding of the narrow tunnel finally ends in a dark chamber.
A nameless sense of evil throbs somewhere within these slick, 
stony walls.  A thick layer of dust covers the floor, as if the
frightened creatures living in the tunnels know better than to 
come here.
KAYLA
    );
     set_smell("default","The air in this cavern is heavy and cold.");
    set_exits(([
       "east" : "/d/deku/dark/elf9"
    ] ));
    set_items(([
       "dust" : "The dust is thick within this cavern."
    ] ));
  	if(!present("naga") && !random(2)) {
  		new("/d/deku/monster/naga3")->move(TO);
  	}
}

void reset() {
  ::reset();
}
