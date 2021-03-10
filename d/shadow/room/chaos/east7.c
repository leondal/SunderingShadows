#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Waiting Room");
    set_long( "a room."
	
    );
    set_exits( ([
	"west" : CHAOSDIR+"floor7"
        ]) );
    set_door("east door",CHAOSDIR+"floor7","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat"}),70,3);
}
