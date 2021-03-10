#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A cliff");
set_long("%^ORANGE%^You are hanging on for dear life and limb to a piece of scrub.  There is a ledge to your left and maybe by swinging you could make it, you only have to hope the piece of scrub brush is going to hold long enough.");
set_smell("default", "All you can smell is the dust in your nose");
set_listen("default", "%^CYAN%^You can however, hear waves crashing against the rocks below and you hope you won't fall any further!");
set_exits (([
"swing" : "/d/ptalkin/mid/roomledge2"
]));
}
