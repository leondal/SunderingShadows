#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, second floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the second floor of the Chaos Tower.%^RESET%^
You can see four doors, one in each direction.
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. 
MELNMARN
);
    set_exits( ([
	"up"    : CHAOSDIR+"floor3.c",
	"down"  : CHAOSDIR+"floor1.c",
	"east"  : CHAOSDIR+"east2.c",
	"west"  : CHAOSDIR+"west2.c",
	"south" : CHAOSDIR+"south2.c",
	"north" : CHAOSDIR+"north2.c"
        ]) );
    set_door("north door",CHAOSDIR+"north2","north",0);
    set_door("south door",CHAOSDIR+"south2","south",0);
    set_door("east door",CHAOSDIR+"east2","east",0);
    set_door("west door",CHAOSDIR+"west2","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
}
