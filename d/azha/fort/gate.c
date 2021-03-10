//	The Gate to Azha Fort
//	Thorn@Shadowgate
//	12/18/95
//	Azha Area
//	gate.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  object ob;
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(0);
    set_short("The Gate to Azha Fort");
		set_long(
@THORN
You are now inside the gates of Azha Fort.  Looking around, you can see 
new stones mixed in with the ancient masonry of the old Azha Citadel, long
destroyed.  Now, Imperial troops keep a watch on the walls for bandits and
marauders, a far cry from the ancient glory that the older sections of the 
walls seem to indicate.  The Dark Tower sits in the northwest corner of the
walls, and the main keep is to the west.  The gate leads east, into the
town.  Access to the fort is completely forbidden due to renovations.
THORN
);
     set_exits(
	([ "south" : "/d/azha/town/fort5" ]));
//              (["northwest" : "/d/azha/fort/outtower",
//			"south" : "/d/azha/town/fort5",
//                "west" : "/d/azha/fort/keep"]) );
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "gate");
	AOVER->add_monster(TO, AMONDIR+"ibnpasha", 1);
	AOVER->add_monster(TO, AMONDIR+"sweeper", 1);
}

