#include <std.h>
#include <objects.h>
inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("Road to the Mountains");
    set_long(
@GRAYHAWK
%^YELLOW%^Road to the mountains%^RESET%^
You are walking along an abandoned road.  There is nothing to the
sides of the road, only blackness, darkness, nothingness. The
air feels a little chilly, and directly toward the north are the
infamous Echoes Mountains.
GRAYHAWK
    );

    set_items(([
	"road":"A road through the void.",
	"void":"Darkness, total and complete."
	]));
 
    set_exits(([
        "southwest" : "/d/shadow/room/mountain/road3",
        "north" : "/d/shadow/room/mountain/road5"
   	]));
   set_listen("default","There is a deathly silence here.");

}
