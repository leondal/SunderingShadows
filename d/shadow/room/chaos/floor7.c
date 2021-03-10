#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, seventh floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the seventh floor of the Chaos Tower.%^RESET%^
You can see four doors, one in each direction. 
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. 
MELNMARN
    );
    set_exits( ([
	"up"    : CHAOSDIR+"floor8.c",
	"down"  : CHAOSDIR+"floor6.c",
	"east"  : CHAOSDIR+"east7.c",
	"west"  : CHAOSDIR+"west7.c",
	"south" : CHAOSDIR+"south7.c",
	"north" : CHAOSDIR+"north7.c"
        ]) );
    set_door("north door",CHAOSDIR+"north7","north",0);
    set_door("south door",CHAOSDIR+"south7","south",0);
    set_door("east door",CHAOSDIR+"east7","east",0);
    set_door("west door",CHAOSDIR+"west7","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
}
