#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, sixth floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the sixth floor of the Chaos Tower.%^RESET%^
You can see four doors, one in each direction. 
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. 
MELNMARN
    );
    set_exits( ([
	"up"    : CHAOSDIR+"floor7.c",
	"down"  : CHAOSDIR+"floor5.c",
	"east"  : CHAOSDIR+"east6.c",
	"west"  : CHAOSDIR+"west6.c",
	"south" : CHAOSDIR+"south6.c",
	"north" : CHAOSDIR+"north6.c"
        ]) );
    set_door("north door",CHAOSDIR+"north6","north",0);
    set_door("south door",CHAOSDIR+"south6","south",0);
    set_door("east door",CHAOSDIR+"east6","east",0);
    set_door("west door",CHAOSDIR+"west6","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
}
