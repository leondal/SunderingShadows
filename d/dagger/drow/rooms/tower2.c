#include <std.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(STAIRWAY);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BOLD%^%^BLACK%^Chamber of shadows%^RESET%^");
    set_long(
	"%^BOLD%^%^BLACK%^You stand in a room full of shadows. The only "
	"light source in the chamber is the %^YELLOW%^glowing "
	"light%^BLACK%^ coming from the hole in the floor. A staircase "
	"as black as the night itself leads up. The shadows seem to dance "
	"and move within the blackness of the chamber.%^RESET%^"
    );
    set_listen("default",
        "You hear a distant laughter."
    );
    set_items(([
	"shadows":"%^BOLD%^%^BLACK%^The shadows seem to be alive.%^RESET%^",
	"staircase":"%^BOLD%^%^BLACK%^The staircase appears to be made of "
	"shadows and leads upwards.%^RESET%^",
	"light":"%^YELLOW%^The light comes through the hole on the floor. "
	"%^RESET%^",
	"hole":"%^YELLOW%^The hole leads down to the chamber of the "
	"caern.%^RESET%^",
    ]));
    set_exits(([
	"down": RPATH "tower1",
	"up": RPATH "tower3"
    ]));
    add_pre_exit_function("up","block");
}
int block() {
    if(!TP) return 0;
    if(!userp(TP)) return 1;
    if(present("monk")) {
	message("info",
	    "%^BOLD%^%^BLACK%^The shadows seem to thicken and block your "
	    "your progress upwards.%^RESET%^"
	,TP);
	return 0;
    }
    return 1;
}
void reset() {
    ::reset();
    if(!present("monk")) {
	new( MPATH "smonk")->move(TO);
    }
}
