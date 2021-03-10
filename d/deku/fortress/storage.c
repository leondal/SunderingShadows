#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Storage Room");
    set_long(
@KAYLA
%^YELLOW%^Storage Room%^RESET%^
Six large barrels stand on end in the middle of the room.  The
walls are lined by shelves holding several dozen sacks and ten
wooden casks.
KAYLA
    );
    set_smell("default","The smell of curing meat is strong.");
    set_exits(([
       "south" : "/d/deku/fortress/kitchen2",
       "down" : "/d/deku/fortress/wine"
    ] ));
    set_items(([
       "barrels" : "The barrels contains water or wine.",
       "sacks" : "The sacks hold barley, flour, oats and bran.",
       "casks" : "These casks hold mead, brandy, or beer.",
       "floor" : "The floor looks like it has scuff marks by the barrels."
    ] ));
}
