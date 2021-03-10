#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Office");
    set_long( "a room."
    );
    set_exits( ([
	"south" : CHAOSDIR+"floor7"
        ]) );
    set_door("north door",CHAOSDIR+"floor7","south",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat",MONDIR+"giantrat"}),60,8);
}
