#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 1);
set_short("%^ORANGE%^Inside a cliff");
set_long("%^ORANGE%^Okay, now you are IN the cliff, so where to now.  You can barely make out that you have made it to a small tunnel system.  You can't go back, so you might as well gird your loins and head onward..... praying to whatever Diety that guards you.");
set_smell("default", "A new odour takes over, something of a cross between rancid meat and cinnamon");
set_listen("default", "%^CYAN%^You can still hear the wave crashing, however, you also hear scuffling sounds, like claws on rock");
set_exits (([
"north" : "/d/ptalkin/mid/roomledge4"
]));
}
