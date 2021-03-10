#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A room full of dirt.");
    set_long( 
@MELNMARN
%^BOLD%^This is a room full of dirt.%^RESET%^
This room has, what appears to be, a dirt floor. Dirt
covers every inch of the floor. You see a picture of 
a sun on the ceiling, and mountians painted on the walls.
One wall depicts a spectacular waterfall, flowing down a 
mountian.
MELNMARN
    );
    set_exits( ([
	"west" : CHAOSDIR+"floor3"
        ]) );
    set_door("east door",CHAOSDIR+"floor3","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
        do_random_encounters(({MONDIR+"giantrat"}),70,3);
}
