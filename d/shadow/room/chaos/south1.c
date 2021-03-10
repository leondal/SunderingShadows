#include "chaos.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Entry Hall");
    set_long(
@MELNMARN
%^BOLD%^You are in the entry hall, on the first floor.%^RESET%^
This is the entrance hall to the Chaos tower. 
This is the only known way in and out of the tower.
MELNMARN
    );
    set_exits( ([
	"north" : CHAOSDIR+"floor1",
	"south" : CHAOSDIR+"road5"
        ]) );
    set_smell("default","You can smell a musky odor.");
    set_listen("default","There is a deathly silence here.");
}
