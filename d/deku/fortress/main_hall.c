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
burn marks and gouges.  The remains of a great oak door lies rotting
on the floor just within the entry, its five iron hinges corroded
and ripped asunder.  Throughout the chamber within are the decaying
remnants of fine furnishing that bear the unmistakable mark of 
elven craftsmanship.  Two doors are slightly ajar, opening into
a room to the east.  Many building stones lie scattered about.
KAYLA
    );
     set_smell("default","A faintly nauseating smell of death and decay hangs in the air");
    set_exits(([
       "south" : "/d/deku/fortress/foyer",
       "east" : "/d/deku/fortress/hallE1",
       "north" : "/d/deku/fortress/main_hall2"
    ] ));
    set_items(([
    ] ));
}
