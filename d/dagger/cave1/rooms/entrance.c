#include <std.h>
inherit ROOM;
void create (){
::create ();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
set_property ("light", 1);
set_property("indoors", 1);
set_property("no teleport",1);
set_short("caves");
set_long("The cave ends here at the bottom of a steep inclining chute,
a mat made of woven reeds lies on top of a huge pile of furs here.");

set_smell("default", "The sharp odor of oil and furs tickles your your nose.");
set_listen("default", "You hear voices in the distance.");
set_items(([
"mat" : "This mat of woven reeds was your ticket down here, but not your ride back out.",
"chute" : "This chute leads steeply upwards and is coated with some kind of slippery oil. It would be impossible to climb.",
"furs" : "This huge pile of furs stopped your slide earlier and kept you from breaking any bones.",
]));
set_exits( ([
"east" : "/d/dagger/drow/rooms/tun1",
"south" : "/d/dagger/cave1/rooms/alcove",
]) );
}
