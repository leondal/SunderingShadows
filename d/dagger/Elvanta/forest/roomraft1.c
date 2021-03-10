#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A raft sitting in the middle of the moat");
set_long("%^CYAN%^You are standing on a raft made of pale green wood, it measures about ten feet long and five feet wide.  It has been put here for a reason, perhaps something to stand upon while engaged in battle?%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slithering sound from some animal close by, and your own breath echoing off the banks of the moat.");
set_exits (([
"down" : "/d/dagger/Elvanta/forest/roommoat6"
]));
set_items
(([
]));
}
void reset(){
::reset();
if(!present("serpent"))
new("/d/dagger/Elvanta/forest/mon/serpent")->move(this_object());
}
