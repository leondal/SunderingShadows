#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Waiting Room");
    set_long(
@MELNMARN
%^BOLD%^You are in the waiting room, on the first floor.%^RESET%^
Back when the tower was built, this was where visitors 
would wait to talk to the mages. It is unused now. There 
is some old broken furniture scattered around the room. 
MELNMARN
	
    );
    set_exits( ([
	"west" : CHAOSDIR+"floor1.c"
        ]) );
    set_door("door",CHAOSDIR+"floor1","west",0);
    set_smell("default","There is a musky odor about the place.");
     set_listen("default", "The sounds of scurrying rats fill your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat"}),70,3);
}
