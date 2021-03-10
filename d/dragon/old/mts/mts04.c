#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Northern Mountains");
    set_long("%^BLUE%^%^BOLD%^
Dark clouds loom menacingly over the grim, snow-drenched hamlets of the
Northern Mountains.  The snow, which falls from the sky, is thick and 
stagnant, as you travel deeper into the mountains.
    ");
    set_exits(([
       "northeast" : "/d/dragon/mts/mts05",
       "southwest" : "/d/dragon/mts/mts03"
    ] ));
    set_items(([
       "path":"A small path through the peaks of the northern mountains.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
