#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You walk along a <pathway> set within the <forest>, high above the ground.  <Squirrels> and <birds> fills the air with sight and sound.  You see more <buildings> in the distance, as though a main street has been laid out, through out the <trees>.%^RESET%^");
set ("night long", "%^CYAN%^You walk along a <pathway> lit by <globes> hanging from great <limbs>.  More <buildings> appear in the distance, as though a main street has been laid out, through out the <trees>.%^RESET%^");
set_smell("default", "%^MAGENTA%^\nThe smell of damp earth, flowers, and pine fills the air.");
set_listen ("default", "Animal sounds are heard, squeeks, squawks, and scurrying.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room108",
"east" : "/d/dagger/Elvanta/forest/room106"
]));
set_items
(([
"buildings" : "Buildings of all sorts appear in the distance, obviously the commercial centre of the city.",
"limbs" : "Great limbs laden with homes, and buildings amaze you, how WAS this city made, with such grace, grandeur and with the forests apparent submission.",
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"pathway" : "Laid out eons ago, by a hand, unknown to you, the pathway continues through the trees, enticing and dangerous.",
"city" : "The main part of the city of Elvanta seems to be near, more people seem to be here.",
"owl" : "Very large owls live here in this forest.  They stand about four feet tall, and have large talons and wicked beaks.  They hoot from their perches, and it would be wise to give them a wide berth.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"squirrels" : "These little creatures are of all colours, brown, black and grey.  Their chittering reminds you of small children laughing.",
"birds" : "Birds of many different hues live in this forest, protected it seems, by the keepers.",
"animals" : "As you walk through this city you notice how many small animals make their homes here as well, mice, crickets, rabbits, and other four legged and six legged creatures.  They seem not to be alarmed by your passing.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"houses" : "Several houses, set within the trees themselves, or upon a limb dot the forest.",
"children" : "Running, laughing, giggling children race past you in a game that only they seem to understand.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
