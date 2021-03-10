#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, fourth floor");
    set_long(
@MELNMARN
%^BOLD%^Your on the fourth floor of the Chaos Tower. %^RESET%^
You can see four doors, one in each direction. 
There doesn't appear to be locks on the doors. 
In the center of the room, is a spiral staircase, 
that leads up and down. 
MELNMARN
);
    set_exits( ([
	"up"    : CHAOSDIR+"floor5.c",
	"down"  : CHAOSDIR+"floor3.c",
	"east"  : CHAOSDIR+"east4.c",
	"west"  : CHAOSDIR+"west4.c",
	"south" : CHAOSDIR+"south4.c",
	"north" : CHAOSDIR+"north4.c"
        ]) );
    set_door("north door",CHAOSDIR+"north4","north",0);
    set_door("south door",CHAOSDIR+"south4","south",0);
    set_door("east door",CHAOSDIR+"east4","east",0);
    set_door("west door",CHAOSDIR+"west4","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
}
