#include "chaos.h"
inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A breezy room.");
    set_long( 
@MELNMARN
%^BOLD%^This is a very breezy room.%^RESET%^
The outside wall is not a wall at all. It is all glass. 
Windows cover the wall. They are all open, and a breeze 
blows into the room. The rest of the room is empty. 
MELNMARN
    );
    set_exits( ([
	"north" : CHAOSDIR+"floor3"
        ]) );
    set_door("south door",CHAOSDIR+"floor3","north",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat",MONDIR+"giantrat"}),60,8);
}
