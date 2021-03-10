#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, third floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the third floor of the Chaos Tower.%^RESET%^
You can see four doors, one in each direction. 
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. 
MELNMARN
);
    set_exits( ([
	"up"    : CHAOSDIR+"floor4.c",
	"down"  : CHAOSDIR+"floor2.c",
	"east"  : CHAOSDIR+"east3.c",
	"west"  : CHAOSDIR+"west3.c",
	"south" : CHAOSDIR+"south3.c",
	"north" : CHAOSDIR+"north3.c"
        ]) );
    set_door("north door",CHAOSDIR+"north3","north",0);
    set_door("south door",CHAOSDIR+"south3","south",0);
    set_door("east door",CHAOSDIR+"east3","east",0);
    set_door("west door",CHAOSDIR+"west3","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
}
