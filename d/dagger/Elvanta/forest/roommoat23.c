#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A dark, still moat around a castle");
set_long("%^CYAN%^You have come full circle around the moat and only have this one little area to pass through safely to come to the castle.  However, you do have to pass the little monster lying in wait for you. Hehe.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slither of some animal, and your own breath echoing of the banks of the moat.");
set_exits (([
"crawl" : "/d/dagger/Elvanta/forest/room128",
"swimnorth" : "/d/dagger/Elvanta/forest/roommoat22"
]));
set_items
(([
]));
}
void reset() {
::reset();
if(!present("wight"))
new("/d/dagger/Elvanta/forest/mon/wight")->move(this_object());
}
