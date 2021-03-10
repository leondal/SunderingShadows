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
%^YELLOW%^Road through Echoes Mountains%^RESET%^
You are on a small ledge approximately 75 feet up the side of the cliff 
face.  The path continues to the east and the south here, as it passes a 
large dark cave which, no doubt, leads deep underground.  To the south, 
the path winds down a steep cliff, and to the east, the path is a bit 
more level.  A sad wind blows in from the northeast.
GRAYHAWK
    );

    set_items(([
        "road":"A road through Echoes Mountains.",
        "cave":"It looks to lead deep underground."
    ]));
 
    set_exits(([
        "south" : "/d/shadow/room/mountain/road5",
        "east" : "/d/shadow/room/mountain/road7",
        "northeast":"/d/magic/temples/akadi_path",
        "north" : "/d/shadow/room/mountain/cave01"
    ]));
   set_listen("default","It is quiet here, except for the wind.");

}

