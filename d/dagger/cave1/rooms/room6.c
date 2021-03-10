#include <std.h>

inherit ROOM;

void create ()
{
::create ();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
set_property ("light", 1);
set_property("indoors", 1);
set_short("caves");
set_long("The cave is narrower here again. There are a few strange <%^YELLOW%^footprints%^RESET%^> here.");

set_smell("default", "You smell the dust around you, it almost makes you sneeze.");
set_listen("default", "You hear the echo of your own footsteps.");
set_exits( ([
"west" : "/d/dagger/cave1/rooms/room5",
"east" : "/d/dagger/cave1/rooms/room7"
]) );
set_items( ([
"footprints" : "The footprints are covered in a film of dust, and they do not look human at all."
]) );
}
