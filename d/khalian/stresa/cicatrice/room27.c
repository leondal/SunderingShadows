
//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^A dune rises in front of you, one hundred feet high.
You have to climb over it, as to go around would take days.  The sand 
shifts under your tired feet, making each step forward feel like two 
steps back.  The sun overhead beats down upon your head, making you feel
dizzy and disoriented.  Your skin feels as though it was on fire and 
blisters are forming on your feet.  You try to see off into the distance
for some sort of landmark, but shimmering heat waves distort reality,
and give no clue as to where you are, where you have been or where you 
are going.");


set_smell("default", "%^CYAN%^You can smell only the hot air as it tries
to sear your eyes, nose and lungs.");
set_listen("default", "%^CYAN%^The sound of vultures cackling still 
lingers in your ears and mind");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room16",
"south" : "/d/khalian/stresa/cicatrice/room51",
"east" : "/d/khalian/stresa/cicatrice/room28",
"west" : "/d/khalian/stresa/cicatrice/room26",
"northeast" : "/d/khalian/stresa/cicatrice/room17",
"northwest" : "/d/khalian/stresa/cicatrice/room15",
"southwest" : "/d/khalian/stresa/cicatrice/room50"
]));


set_items
(([
"dune" : "Dunes ranging from 20 feet to 150 feet form in the desert, bleak
and unforgiving.",
"sand" : "Pale gold grains shimmer as league upon league upon league
stretches before you.",
"landmark" : "No landmarks are forthcoming, only sand and sand dunes"
]));


}
