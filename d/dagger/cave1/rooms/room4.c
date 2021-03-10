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
set_long("The cave walls seem colder to the touch here, it is fairly dim but you can still see, who's shadow is that?");

set_smell("default", "The air smells damper here.");
set_listen("default", "You hear the sound of your footsteps echoing over and over, deep in the cave.");
set_exits( ([
"west" : "/d/dagger/cave1/rooms/room3",
"east" : "/d/dagger/cave1/rooms/room5"
]) );

}
