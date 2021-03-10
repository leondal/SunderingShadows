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
You move on, walking quietly.  At one point you pass through a large
carvern where limestone icicles hang from the ceiling dripping 
continually.  Then the tunnel continues on into the rock.  Occasionally,
you disturb a colony of bats hanging from the ceiling and the 
creatures chitter shrilly as they flap frantically away in huge, dark
clouds.");
set_smell("default", "A new odour takes over, something of a cross between rancid meat and cinnamon");
set_listen("default", "%^CYAN%^There now comes a sound of water endlessly dripping somewhere in the distance.");
set_exits (([
"down" : "/d/ptalkin/mid/roomledge6"
]));
}
