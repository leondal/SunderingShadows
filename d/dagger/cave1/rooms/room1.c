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
set_long("The entrance to the cave is wide but not very high, you have to crouch a bit to enter. The <%^YELLOW%^walls%^RESET%^> are smooth to your touch. There is a bit of dust and <%^YELLOW%^debris%^RESET%^> on the floor.");

set_smell("default", "You smell the fresh air from outside and a bit of musty air from the cave.");
set_listen("default", "You hear the wind whispering by the entrance.");
set_exits( ([
"north" : "/d/dagger/cave1/rooms/room2",
"south" : "/d/dagger/keep/road/entrance1",
]) );
set_items( ([
"walls" : "The walls are smooth, cold and dry to your touch.",
"debris" : "The debris on the floor is mixed of leaves, shards and bits of bone and dust."
]) );
}
