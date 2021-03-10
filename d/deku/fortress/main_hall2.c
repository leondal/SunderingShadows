#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(RUBBLE);
    set_short("Main hall of the Fortress");
    set_long(
@KAYLA
%^YELLOW%^Main hall of the Fortress%^RESET%^
The entrance arch to this room is heavily charred and pitted with
burn marks and gouges. Throughout the chamber are the decaying
remnants of fine furnishing that bear the unmistakable mark of 
elven craftsmanship.  There is one door slightly ajar, opening into
a hallway to the west.  Many building stones lie scattered about.
KAYLA
    );
     set_smell("default","A faintly nauseating smell of death and decay hangs in the air");
    set_exits(([
       "south" : "/d/deku/fortress/main_hall",
       "west" : "/d/deku/fortress/hallW1",
       "north" : "/d/deku/fortress/hallN1"
    ] ));
    set_items(([
    ] ));
}
