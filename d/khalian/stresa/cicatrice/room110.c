//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^The heat shimmers, giving you an illusion.  You see 
the light glisten off a small oasis in the distance.  As you draw nearer
large palm trees appear.  Cool, damp breezes flicker across you skin,
carressing, easing the heat away.  Tiny plants with flowers of every hue,
and the scent of angels dot around the oasis.  Your tongue longs for a 
taste of the silver water.  A beautiful maiden, and a handsome, delectable
young man stand at the side of the water, jugs poised, platters of fruit
ready.  Your first thought is that the desert has claimed another
victim.");

set_smell("default", "%^CYAN%^Odours of fresh fruit, clean water, and a
heady perfume reel your senses.");
set_listen("default", "%^CYAN%^Lapping water and young laughter somehow
reaches your ears.");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room91",
"south" : "/d/khalian/stresa/malveillant/room41",
"east" : "/d/khalian/stresa/cicatrice/room111",
"west" : "/d/khalian/stresa/malveillant/room29",
"northeast" : "/d/khalian/stresa/cicatrice/room104",
"northwest" : "/d/khalian/stresa/cicatrice/room102",
"southeast" : "/d/khalian/stresa/cicatrice/room117",
"southwest" : "/d/khalian/stresa/malveillant/room40"
]));


set_items
(([
"oasis" : "A fertile or green area in an arid region.",
"trees" : "Large palm trees make theirselves known as they sway in the 
breeze offering a much needed respite from the sun.",
"plants" : "Small plants, golden-heart, bloodrune and purple dragonseye
make their homes around the oasis.",
"maiden" : "A lovely young lady.",
"man" : "Opposite of young lady, however, NOT opposite of lovely.",
"jugs" : "Use your imagination, gentlemen",
"platters" : "Kiwi, limes, oranges, pineapples, fruits of the gods lay
upon the platters."
]));
											

}
