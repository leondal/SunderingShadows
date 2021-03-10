#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You are starting to tire of this long trek, and only hope that whatever is at the end of this circle is worth the walk.%^RESET%^");
set ("night long", "%^CYAN%^You ar starting to tire of this long trek, and only hope that whatever lies at the end of the circle is worth the walk.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell pine trees and damp forest.");
set_listen ("default", "Birds by the thousands it seems, are making themselves heard.");
set_exits (([
"southeast" : "/d/dagger/Elvanta/forest/room31",
"north" : "/d/dagger/Elvanta/forest/room33"
]));
set_items
(([
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
