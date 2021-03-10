#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Wine Cellar");
    set_long(
@KAYLA
%^YELLOW%^Wine Cellar%^RESET%^
As you reach the bottom of the stairs, you find yourself in a 
wine cellar.  Large casks on their sides line the north, west
and south walls.  Against the east wall, just in front of the
steps, is a very large wine rack containing scores of wine 
bottles.  In the middle of the room, lying in a contorted shape, 
you see the remains of a human figure.
KAYLA
    );
    set_exits(([
       "up" : "/d/deku/fortress/storage"
    ] ));
    set_items(([
    ({"corpse","remains","human remains"}) : "%^YELLOW%^The remains "+
    "of what could have once been a human lay in the middle of "+
    "this room.  You can easily tell that this person met a horrible "+
    "fate.  The flesh has rotted away to reveal the bones.  "+
    "Almost all of them are fractured or completely broken and those "+
    "that remain intact have deep holes of varying sizes punched into "+
    "them.  You believe that someone probably shoved a pointed "+
    "object into them with a tremendous amount of force.%^RESET%^",
    ] ));
}
