#include "chaos.h"
inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Red Room");
    set_long( 
@MELNMARN
%^BOLD%^This is the Red Room.%^RESET%^
In this room, everything is red. The walls, ceiling, 
even the floor. There is even broken red furniture
scattered around the room.
MELNMARN

    );
    set_exits( ([
	"north" : CHAOSDIR+"floor2"
        ]) );
    set_door("south door",CHAOSDIR+"floor2","north",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat",MONDIR+"giantrat"}),60,8);
}
