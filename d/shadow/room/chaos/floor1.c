#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, first floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the first floor of the Chaos Tower.%^RESET%^
You can see four doors, one in each direction. 
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. The place seems to be abandoned.
MELNMARN
);
    set_exits( ([
	"up"    : CHAOSDIR+"floor2.c",
	"down"  : CHAOSDIR+"basement1.c",
	"east"  : CHAOSDIR+"east1.c",
	"west"  : CHAOSDIR+"west1.c",
	"south" : CHAOSDIR+"south1.c",
	"north" : CHAOSDIR+"north1.c"
        ]) );
    set_door("north door",CHAOSDIR+"north1","north",0);
    set_door("east door",CHAOSDIR+"east1","east",0);
    set_door("west door",CHAOSDIR+"west1","west",0);
    
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
    set_items( ([
	"staircase":"It is an old oak spiral staircase. There is room for two people to walk side by side.",
	"doors":"They are old and broken. You could easily open them."
    ]) );

}
