#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Black Room");
    set_long(
@MELNMARN
%^BOLD%^This is the Black Room. %^RESET%^
Everything in this room is a shade of black. You can make out some chairs 
in the corner of the room. There are some pictures on the wall. You get 
an errie feeling as you look around.
MELNMARN
    );
    set_exits( ([
	"west" : CHAOSDIR+"floor2"
        ]) );
    set_door("east door",CHAOSDIR+"floor2","west",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");
    set_items(([
	"chairs":"Wooden chairs painted black.",
	"pictures":"Black and white paintings of demons",
    ]) );
}
void init(){
    ::init();
        do_random_encounters(({MONDIR+"giantrat"}),70,3);
}
