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
    set_items(([
	"cot":"This is one of four cots in the room.",
	"cots":"The cots are covered with animal skins and furs.",
	"skins":"Various skins from slain animals, used to provide warmth.",
	"furs":"The furs are from various animals and are used to provide "
	"warmth.",
	"foot lockers":"The foot lockers contain drow wafers.",
	"foot locker":"The foot locker contains drow wafers.",
	"weapons":"All broken and useless.",
	"wafers":"A standard drow bisquit ration...very horrible tasting and "
	"most likely poisonious to non-drow races."
    ]));
*********************/
    set_exits(([
	"east": RPATH "city7"
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