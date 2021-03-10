#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A ledge");
set_long("%^ORANGE%^You have managed to swing to the sliver of a ledge on the side of the cliff.  However, NOW, what do you do? You can see a small crevice to your right, maybe if you wiggle over there, you could sort of slide into the cliff itself.  It looks very black inside.....");
set_smell("default", "All you can smell is the dust in your nose");
set_listen("default", "%^CYAN%^You can however, hear waves crashing against the rocks below and you hope you won't fall any further!");
set_exits (([
"crevice" : "/d/ptalkin/mid/roomledge3"
]));
}
