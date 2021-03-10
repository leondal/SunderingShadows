#include <std.h>
#include "/d/dagger/drow/short.h"
//inherit ROOM;

inherit RPATH "brk1";

void create() {
    ::create();
/******************* inheriting from brk1 now *Styx* 5/26/06
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Drow soldier barrack");
    set_long(
	"%^BLACK%^%^BLUE%^This is a standard drow barrack. It is quite "
	"bare of furnishings as soldiers of the Drow Regime own very few "
	"possessions, and those few possessions they do own are usually "
	"kept with them. Other than four cots and foot lockers, "
	"the only other notable items in the room are some scattered "
	"broken weapons.%^RESET%^"
    );
    set_listen("default",
 	"You hear the occasional drow shout from a distance."
    );
    set_smell("default",
	"It smells foul here."
    );
*********************/
    set_exits(([
	"west": RPATH "city11"
    ]));
}
/**************
void reset() {
    ::reset();
    if(!present("drow")) {
	new( MPATH "drows" )->move(TO);
	new( MPATH "drows" )->move(TO);
	new( MPATH "drows" )->move(TO);
	new( MPATH "drowcap" )->move(TO);
    }
}
*************/