#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A dark, still moat around a castle");
set_long("%^CYAN%^As you peer about this area you see a small island of dirt.  The rest of the moat seems calm, perhaps a bit too calm.  The air is full of apprehension.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slither of some animal, and your own breath echoing of the banks of the moat.");
set_exits (([
"swimnorth" : "/d/dagger/Elvanta/forest/roommoat10",
"swimsouth" : "/d/dagger/Elvanta/forest/roommoat8",
"island" : "/d/dagger/Elvanta/forest/roomisland1"
]));
set_items
(([
]));
}
