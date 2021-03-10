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
set_long("This part of the cave narrows slightly, you feel slightly claustrophobic.");

set_smell("default", "The air her smells drier and mustier.");
set_listen("default", "You hear the faint whispering of the wind and the echo of your footsteps.");
set_exits( ([
"south" : "/d/dagger/cave1/rooms/room1",
"northeast" : "/d/dagger/cave1/rooms/room5"
]) );

}
