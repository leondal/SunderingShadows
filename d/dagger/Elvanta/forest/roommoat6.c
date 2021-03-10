#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A dark, still moat around a castle");
set_long("%^CYAN%^Once again the waters in the moat start to stir around a small raft held in place by stakes.  %^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slither of some animal, and your own breath echoing of the banks of the moat.");
set_exits (([
"raft" : "/d/dagger/Elvanta/forest/roomraft1",
"swimnorth" : "/d/dagger/Elvanta/forest/roommoat7",
"swimsouth" : "/d/dagger/Elvanta/forest/roommoat5"
]));
set_items
(([
]));
}
