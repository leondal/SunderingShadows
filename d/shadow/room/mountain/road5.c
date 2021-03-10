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
You are on the edge of a large forest streching off to the south
as far as you can see.  To your north, a sheer cliff meets your
gaze.  Although steep, the path seems to be leading up the cliff
face.  The air feels a little chilly.
GRAYHAWK
    );

    set_items(([
	"road":"A road through the void.",
	"void":"Darkness, total and complete."
	]));
 
    set_exits(([
        "south" : "/d/shadow/room/mountain/road4",
        "north" : "/d/shadow/room/mountain/road6"
   	]));
   set_listen("default","There is a deathly silence here.");

}
