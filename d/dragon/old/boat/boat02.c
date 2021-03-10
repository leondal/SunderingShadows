#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("no teleport",1);
    set_property("indoors",1);
    set_short("Dark Oliphant");
    set_long("%^BLUE%^%^RED%^
The cavernous upper deck is as large as a warehouse.  Its open space is 
unbroken except for a few enclosed alcoves that store stone shots and bolts.
Ladders descend to the decks below, and rise into the weapons cockpits
above.
");
    set_exits(([
       "up" : "/d/dragon/boat/boat01",
       "down" : "/d/dragon/boat/boat02",
       "south" : "/d/dragon/boat/boat04",
       "north" : "/d/dragon/boat/boat03"
    ] ));
    set_listen("default","There is a very slight howl within the wind.");
    set_items(([
       "weapons":"The weapons include rusty ballista bolts."
    ] ));
}
