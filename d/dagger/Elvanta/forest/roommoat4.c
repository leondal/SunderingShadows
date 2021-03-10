#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A dark, still moat around a castle");
set_long("%^CYAN%^The moat's waters are slightly stirring here.  You see a large flat rock set in the middle of the moat.  Hmmm, what is it there for?  Perhaps you could crawl to it and see what is there.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slither of some animal, and your own breath echoing of the banks of the moat.");
set_exits (([
"swimeast" : "/d/dagger/Elvanta/forest/roommoat5",
"swimwest" : "/d/dagger/Elvanta/forest/roommoat3"
]));
set_items
(([
]));
}
