#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 1);
set_short("%^ORANGE%^Inside a cliff");
set_long("%^ORANGE%^The tunnel shows glimmers of some crystal in the rock reflecting what little light that sneaks in through the crevice in the cliff.  The little light there is makes it possible for you to find your way and avoid obstructions on the rough floor of the passageway.  The passage curves steadily downward and to the right.  After you have gone a few paces, you realize this is not a natural tunnel, but has been carved out of the rock.");
set_smell("default", "A new odour takes over, something of a cross between rancid meat and cinnamon");
set_listen("default", "%^CYAN%^There now comes a sound of water endlessly dripping somewhere in the distance.");
set_exits (([
"down" : "/d/ptalkin/mid/roomledge5"
]));
}
