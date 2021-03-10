#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("The guards room");
set_long("%^YELLOW%^This is the guards room and where the guards can relax.  Bottles of wine, mugs, and half eaten food lays about on old beaten tables.  Cards, dice, and daggers also lay scattered.");
set_smell("default", "%^MAGENTA%^\nStale ale, old food and body odours fill this room, making it quite unpleasant.");
set_listen("default", "%^ORANGE%^Muffled curses and coarse laughter reaches your ears.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomcastle5c",
"east" : "/d/dagger/Elvanta/forest/roomcastle2c",
"northeast" : "/d/dagger/Elvanta/forest/roomcastle4c"
]) );
set_items(([
"tables" : "Old beaten trestle tables and benches line the walls",
"dice" : "A beaten pair of dice lay upon old used cards",
"daggers" : "Daggers of every size and description lay about, obviously the guards favourite weapons",
"cards" : "Old bent, torn, cracked cards rest on the tables, waiting for someone to continue to lose money"
]) );
}
void reset() {
::reset();
if(!present("castleguard"))
new("/d/dagger/Elvanta/forest/mon/castleguard")->move(TO);
}
