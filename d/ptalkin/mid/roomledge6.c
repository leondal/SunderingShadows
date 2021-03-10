#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 1);
set_short("%^ORANGE%^A tunnel");
set_long("%^ORANGE%^You see a light coming from somewhere ahead, faint at first but grown steadily stronger as you move on down the tunnel.  The light comes from the surface as a stream drops down into the cavern ahead, and it catches the sunlight or moonlight at certain times of day.  It seems as though the very rocks around you glimmer with light as well, and give off a somewhat eerie, greenish glow.");
set_smell("default", "A new odour takes over, something of a cross between rancid meat and cinnamon");
set_listen("default", "%^CYAN%^There now comes a sound of water endlessly dripping somewhere in the distance.");
set_exits (([
"east" : "/d/ptalkin/mid/roomledge7"
]));
}
