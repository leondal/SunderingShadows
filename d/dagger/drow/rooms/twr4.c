#include <std.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Gatetower, top floor");
    set_long(
	"%^BLUE%^You stand within an archer's gatetower. The "
	"gatetower stands two stories high and a ladder leads down through "
	"a hole in the floor of this room to the first level. There are "
	"arrow slits in the walls for the archers to shoot through. "
	"A few broken arrows and bows lay on the floor.%^RESET%^"
    );
    set_listen("default",
 	"You hear the sounds of the city rumble outside."
    );
    set_smell("default",
	"It smells of burning oil."
    );
    set_items(([
	"arrows":"Broken arrows discarded by a drow archer.",
	"bows":"Broken bows discarded by a drow archer.",
	"arrow":"There are many broken arrows here.",
	"bow":"There are many broken bows here.",
	"arrow slits":"These arrow slits provide the drow archers a means "
	"with which to fire at intruders to the city.",
	"slits":"There are arrow slits in the walls.",
	"slit":"There are many arrow slits here.",
	"ladder":"The ladder leads down to the first story of the gatehouse "
	"through a hole in the floor.",
	"hole":"There is an open hole in the floor with a ladder through "
	"it."
    ]));
    set_exits(([
	"down": RPATH "twr3"
    ]));
}
void reset() {
    ::reset();
    if(!present("drow")) {
	new( MPATH "drowa" )->move(TO);
	new( MPATH "drowa" )->move(TO);
        new( MPATH "drowa" )->move(TO);
	new( MPATH "drowa" )->move(TO);
    }
}
