#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, fifth floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the fifth floor of the Chaos Tower. %^RESET%^
You can see four doors, one in each direction. 
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. 
MELNMARN
    );
    set_exits( ([
	"up"    : CHAOSDIR+"floor6.c",
	"down"  : CHAOSDIR+"floor4.c",
	"east"  : CHAOSDIR+"east5.c",
	"west"  : CHAOSDIR+"west5.c",
	"south" : CHAOSDIR+"south5.c",
	"north" : CHAOSDIR+"north5.c"
        ]) );
    set_door("north door",CHAOSDIR+"north5","north",0);
    set_door("south door",CHAOSDIR+"south5","south",0);
    set_door("east door",CHAOSDIR+"east5","east",0);
    set_door("west door",CHAOSDIR+"west5","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
}
