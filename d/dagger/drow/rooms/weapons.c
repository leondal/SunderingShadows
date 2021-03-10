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
    set_short("%^BLUE%^Drow weaponsmiths%^RESET%^");
    set_long(
	"%^BLUE%^Here is the weaponsmith workshop. This place is not meant "
	"to conduct trade business but rather to forge the weapons and "
	"armours for the Drow Regime. There are various tools of forging "
	"scattered about the room.%^RESET%^"
    );
    set_listen("default",
	"You hear the clanging of weapons."
    );
    set_smell("default",
	"The smell of hot iron fills the air."
    );
    set_items(([
        "tools":"There are various tools of forging here -- all useless to "
	"you!"
    ]));
    set_exits(([
    	"south": RPATH "city14"
    ]));
}
void reset() {
    ::reset();
    if(!present("kraznoth")) {
        write("%^RED%^The weaponsmith enters the room and begins banging "
	"on a sword.%^RESET%^");
	new( MPATH "kraznoth")->move(TO);
    }
}
