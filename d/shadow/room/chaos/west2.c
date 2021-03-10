#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The White room");
    set_long( 
@MELNMARN
%^BOLD%^This is the White room.%^RESET%^
You are standing in a white room. All the furnishings in the room are
also white. It is hard to see everything in the room, you are forced to 
make a very slow scan of the room. Even then. You see noting of interest.
MELNMARN
    );
    set_exits( ([
	"east" : CHAOSDIR+"floor2"
        ]) );
    set_door("west door",CHAOSDIR+"floor2","east",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of scurrying rats fills your ears.");

}
void init(){
    ::init();
	do_random_encounters(({MONDIR+"giantrat",MONDIR+"rat"}),50,9);
}
