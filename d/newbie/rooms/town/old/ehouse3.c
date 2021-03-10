#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_property("no sticks",1);
        set_terrain(WOOD_BUILDING);
        set_travel(PAVED_ROAD);
        set_short("%^BOLD%^%^BLUE%^A nice but simple house");
        set_long(
@STYX
This is a small and plain but nice house.  It has a %^BOLD%^%^BLACK%^stove %^RESET%^for both cooking and heating in winter in one corner.  Nearby is a washbasin that sits on cabinets to store dishes.  A table and chairs to sit and eat at are also nearby and oil lamps hang on the walls for lighting.  There is a %^BOLD%^%^BLUE%^couch %^RESET%^and a few more comfortable looking chairs.  A small bedroom is in another corner with walls for privacy but you can see into it since the curtain used to cover the door is pulled aside.  A few sketches hang on the walls.    
STYX
        );
        set_smell("default","The house smells of wood and smoke.");
        set_listen("default","Little disturbs the quiet here.");
        set_items(([
        ({"chair","chairs"}) : "All the chairs are simple wooden ones but the ones near the sofa have nice cushions and arms on them.",
        "stove" : "A pile of wood sits next to it.",
        "cabinet" : "The cabinet has open shelves with dishes and cooking utensils and shelves behind doors for the linens.",
        "couch" : "%^BOLD%^%^BLUE%^The couch has a wooden frame but has nice thick cushions covered with a heavy but pretty blue fabric.",
        "bedroom" : "The bedroom has a dresser for a few clothes and a washbasin sitting on it.  It's barely large enough for the single bed and a curtain is used for a door.",
        "floor" : "The floor is simply wooden planks but it looks pretty clean.",
        ({"wall","walls"}) : "The walls are plain and have a few sketches hanging on them.",
        ({"lamps","lamp","oil lamps"}) : "Lamps that burn oil hang from the walls and ceiling for light.",
		"sketches" : "The sketches are collages of various fighting moves.  One shows a fighter parrying and his opponent rushing.  The lower corner reads - to Mortius, thanks for all the lessons.",
        ]));
        set_exits(([
        "west" : MAINTOWN"erstreet4",
        ]));
        set_door("blue door","/d/newbie/rooms/town/erstreet4","west",0);	    

}