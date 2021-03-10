#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Blue Room");
    set_long( 
@MELNMARN
%^BOLD%^This is the Blue Room.%^RESET%^
Everything in this room is blue. The broken furniture, 
which is scattered around the blue floor, is even blue.
It is hard to make out the line between the floor and
the far wall, since the color is the same. 
MELNMARN
    );
    set_exits( ([
	"south" : CHAOSDIR+"floor2"
        ]) );
    set_door("north door",CHAOSDIR+"floor2","south",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat",MONDIR+"giantrat"}),60,8);
}
