#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A raft sitting in the middle of the moat");
set_long("%^CYAN%^You start to shake in fear as you reach this small island in the middle of the moat.  A large beast of unknown depths has arisen to greet you, it does not look friendly.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slithering sound from some animal close by, and your own breath echoing off the banks of the moat.");
set_exits (([
"down" : "/d/dagger/Elvanta/forest/roommoat13"
]));
set_items
(([
]));
}
void reset(){
::reset();
if(!present("moatmonst"))
new("/d/dagger/Elvanta/forest/mon/moatmonst")->move(this_object());
}
