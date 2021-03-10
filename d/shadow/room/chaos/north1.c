#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Office");
    set_long(
@MELNMARN
%^BOLD%^You are in the office, on the first floor.%^RESET%^
Back when the tower was built, this was where the 
visitors made appointments and checked in for their 
appointments. There is a broken furniture scattered 
around the room.
MELNMARN
    );
    set_exits( ([
	"south" : CHAOSDIR+"floor1.c"
        ]) );
    set_door("north door",CHAOSDIR+"floor1","south",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat",MONDIR+"giantrat"}),60,8);
}
