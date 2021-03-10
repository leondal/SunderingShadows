
//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^All around you nothing but sand. The dunes seem to 
be getting larger, and the holes or whatever also appear to be getting 
more frequent.  Vultures appear overhead and upon the sand, waiting...
for what or whom to cross their path and complete their next meal.");

set_smell("default", "%^CYAN%^You can smell only the hot air trying to
sear your eyes, nose and lungs");
set_listen("default", "%^CYAN%^Only the sound of sand carressing sand, as
time shifts the grains can be heard.");

set_exits(([
"north" : "/d/khalian/stresa/cicatrice/room9",
		"south" : "/d/khalian/stresa/cicatrice/room27",
		"west" : "/d/khalian/stresa/cicatrice/room15",
		"east" : "/d/khalian/stresa/cicatrice/room17",
		"northeast" : "/d/khalian/stresa/cicatrice/room10",
		"northwest" : "/d/khalian/stresa/cicatrice/room8",
		"southeast" : "/d/khalian/stresa/cicatrice/room28",
		"southwest" : "/d/khalian/stresa/cicatrice/room26"
]));

set_items
(([
"dunes" : "Large piles of sand built up by the wind.",
"vultures" : "A large raptorial bird that are related to hawks, eagles,
and falcons, but have weaker claws and usually subsist primarily on 
carrion.",
"holes" : "Small shifting sand seems to be sucked into the earth through
these tiny cup like holes."
]));

}






