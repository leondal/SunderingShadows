#include <std.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Gatetower, bottom floor");
    set_long(
	"%^BLUE%^You stand within an archer's gatetower. The "
	"gatetower stands two stories high and a ladder leads up through "
	"a hole in the roof of this room to the second level. There are "
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
	"ladder":"The ladder leads up to the second story of the gatehouse "
	"through a hole in the ceiling.",
	"hole":"There is an open hole in the ceiling with a ladder through "
	"it."
    ]));
    set_exits(([
	"south": RPATH "city3",
	"up": RPATH "twr2"
    ]));
}
void reset() {
    ::reset();
    if(!present("drow")) {
	new( MPATH "drowa" )->move(TO);
	new( MPATH "drowa" )->move(TO);
    }
}
