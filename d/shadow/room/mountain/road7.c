#include <std.h>
#include <objects.h>
inherit ROOM;

void create(){
    ::create();
   set_terrain(BARREN);
   set_travel(RUTTED_TRACK);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("At the edge of a canyon");
    set_long(
@GRAYHAWK
%^YELLOW%^At the edge of a canyon in the Echoes Mountains%^RESET%^
You are at the edge of a narrow, but deep canyon that blocks your 
progress further east.  Looking around, you can see some brush and scrub 
that are native to this elevation that have clumped together in a thick 
mat near the edge, obscuring your view a bit.  Mountains loom high above 
you on all sides.  You see a path that starts here and leads to the 
west, away from a dead end at the canyon edge.
GRAYHAWK
    );

    set_items(([
        "path": "A more of a badly paved road, it leads off to the west.",
        "brush": "On closer inspection, you can make out a path leading into the "
        "canyon to the south that had been obscured by the brush."
    ]));
 
    set_exits(([
        "south" : "/d/player_houses/rufus/cfloor",
        "west" : "/d/shadow/room/mountain/road6"
    ]));
   set_invis_exits(({ "south" }));
   set_pre_exit_functions( ({ "south" }), ({ "south" }) );
   set_listen("default","It is quiet here, except for the wind.");

}

int south() {
	write("You pass through the brush and down the obscured path "
		"to the canyon floor.");
	return 1;
}
