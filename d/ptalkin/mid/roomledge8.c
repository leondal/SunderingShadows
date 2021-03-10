#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 1);
set_short("%^ORANGE%^A tunnel");
set_long("%^ORANGE%^
As you get closer you see a large carvern.  You stop...peer around the
corner...the cavern is a place of wonder.  Its roof is lost in purple
shadow, and the seething waterfall plunges in glowing, golden mist into
an unimaginable deep chasm from which the hollow roar echoes up in 
endless babble.  The walls, stretching out as far as the eye can reach,
glitter with flecks and veins of gold, and gems more precious than the
ransom of kings, sparkling in the shifting, rainbow-hued light.");
set_smell("default", "A new odour takes over, something of a cross between rancid meat and cinnamon");
set_listen("default", "%^CYAN%^There now comes a sound of water endlessly dripping somewhere in the distance.");
set_exits (([
"east" : "/d/ptalkin/mid/roomledge9"
]));
}
