#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A dark, still moat around a castle");
set_long("%^CYAN%^The moat's waters are still and quiet, a blackgreen in colour.  While he water is not muddy you cannot see what lies a foot below the surface.  Occasionally you will see a rock, small dirt mound or raft in the moat.  Should you be brave enough you could swim through these dark waters. BUT BEWARE!%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell stale water, reeds and some unknown creatures perhaps.");
set_listen("default", "You hear the occasional cricket, a slither of some animal, and your own breath echoing of the banks of the moat.");
set_exits (([
"swimnorth" : "/d/dagger/Elvanta/forest/roommoat6",
"swim" : "/d/dagger/Elvanta/forest/roommoat4"
]));
set_items
(([
]));
}
