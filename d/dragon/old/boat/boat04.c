#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Dark Oliphant");
    set_long("%^BLUE%^%^RED%^
This dusty cubicle is as lifeless as the rest of the upper deck.  Several
barrels are filled with ballista bolts, tips pitted by rust and shafts
corroded by slime and lichen.  The catapult shots heaped in crumbling wooden
bins are still in fine condition, though blanketed with thick dust.
");
    set_exits(([
       "north" : "/d/dragon/boat/boat02"
    ]));
    set_listen("default","There is a very slight howl within the wind.");
    set_items(([
        "weapons":"The weapons include rusty ballista bolts and slimed shafts."
    ] ));
}
