#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Bunkhouse");
    set_long(
	"%^BLACK%^%^BLUE%^You enter the room and appear to be in a "
	"bunkhouse or sleeping quarters of some sort. Four cots are "
	"strewn around the room in a haphazard fashion. Other than "
	"the cots the room is bare and you suspect the occupants spend "
	"little time here other than to sleep.%^RESET%^"
    );
    set_listen("default",
 	"You hear the clanging of weapons and several drow shout occasionally."
    );
    set_smell("default",
   "There is a faint trace of sulfur in the room."
    );
    set_items(([
	"cots":"%^BOLD%^%^GREEN%^The cots are arranged in a careless "
	"manner and are strewn with furs.%^RESET%^",
	"furs":"%^MAGENTA%^The furs are from various animals and "
	"appear to provide warmth and comfort, but are worthless.%^RESET%^"
    ]));
    set_exits(([
	"south": RPATH "city35",
	"east": RPATH "elite4",
	"up": RPATH "elite6"
    ]));
}
