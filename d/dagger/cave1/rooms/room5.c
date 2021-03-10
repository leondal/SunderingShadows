#include <std.h>

inherit ROOM;

void create ()
{
::create ();
   set_travel(RUTTED_TRACK);
   set_terrain(NAT_CAVE);
set_property ("light", 1);
set_property("indoors", 1);
set_short("caves");
set_long("The cave has really opened up here. The ceiling is high and it's very wide. There are a few openings from this cave.");

set_smell("default", "The air smells somewhat cleaner here.");
set_listen("default", "You hear water dripping somewhere and echos coming from all directions.");
set_exits( ([
"southwest" : "/d/dagger/cave1/rooms/room2",
"west" : "/d/dagger/cave1/rooms/room4",
"east" : "/d/dagger/cave1/rooms/room6",
"south" : "/d/dagger/cave1/rooms/room9"
]) );

}
