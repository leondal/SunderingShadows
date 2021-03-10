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
set_long("The cave dips downwards slightly, there are more
footprints and the walls seem to be closer together here.");

set_smell("default", "The odor of stale mouldy air assaults your senses.");
set_listen("default", "You hear the echo of your footsteps and the faint sound of dripping water.");
set_exits( ([
"west" : "/d/dagger/cave1/rooms/room6",
"north" : "/d/dagger/cave1/rooms/room11",
"southeast" : "/d/dagger/cave1/rooms/room10"
]) );

}
