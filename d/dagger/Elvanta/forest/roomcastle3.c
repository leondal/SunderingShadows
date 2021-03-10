#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Moirbin Castle, sitting room");
set_long ("%^GREEN%^You stand in a room with a vaulted ceiling and wood-carved lintels and jams that shine with polish.  Cushioned benches have been placed against facing walls and oil lamps bracet the arched double doors.  This is a sitting room, with small tables placed within reach of the benches, and deep green drapes hang at the narrow windows and a carpet of muted brown covers the floor.  A fire crackles in the arched fireplace at one end of the room.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe odour of burning cherry wood mingles with the flowers set upon the tables.");
set_listen ("default", "%^CYAN%^You hear the crackling of the fireplace and muted voices talking softly.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomcastle4",
"down" : "/d/dagger/Elvanta/forest/roomcastle3c",
"west" : "/d/dagger/Elvanta/forest/roomcastle2"
]) );
set_items(([
"carpet" : "%^GREEN%^This richly coloured carpet comforts your weary feet.  Each step is like stepping into a cloud of warm wool.",
"elven archer" : "An archer stands approximately twelve inches tall.  He is dressed in forest browns and greens.  One arm is fully extended holding a long bow, while the other draws back the bow string.  His grey eyes seem intent upon some distant target.  His lithe body seems as taut as the string he pulls.",
]) );
}
void reset() {
::reset();
if(!present("poet"))
new("/d/dagger/Elvanta/forest/mon/poet")->move(this_object());
if(!present("bench"))
new("/d/dagger/Elvanta/forest/items/objs/bench")->move(this_object());
if(!present("table"))
new("/d/dagger/Elvanta/forest/items/objs/table")->move(this_object());
}
