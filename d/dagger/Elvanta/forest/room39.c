#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You are once again on the pathway through the outer rim of the city of Elvanta.  Forest creatures rush by you, small elven children are also running here and there.  You see the odd elf going about their daily business.  You seem to be coming into a more populated area.  The boughs of the redwoods continue to form pathways through this city.%^RESET%^");
set("night long", "%^CYAN%^You are once again, upon the pathway through the outer rim of the city of Elvanta.  Night creatures of the forest scurry around you, chittering, squeeking and hooting.  You see the old elf going to and from their homes or perhaps to the Inn.  The boughs of the redwood continue to form pathways through this city, and are lit by the globes that seem to flourish here.%^RESET%^");
set_smell("default", "%^MAGENTA%^\nThe smell of the pine forest, smoke from chimneys, and a forge mingle in the air.");
set_listen ("default", "You hear the sounds of creatures of the forest, of elves moving to and fro, and the slight tink-tink of metal striking metal.");
set_exits (([
"southeast" : "/d/dagger/Elvanta/forest/room38",
"west" : "/d/dagger/Elvanta/forest/room40"
]));
set_items
(([
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"pathway" : "The pathway continues to be made of exquisitely carved planks held in place by the thick vines of the forest.  It is so solid, it is hard to believe you are 300 feet above ground.",
"creatures" : "Creatures of all types seem to make their homes here, raccoons, birds, mice, and other creatures not so common.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"squirrels" : "These little creatures are of all colours, brown, black and grey.  Their chittering reminds you of small children laughing.",
"birds" : "Birds of many different hues live in this forest, protected it seems, by the keepers.",
"animals" : "As you walk through this city you notice how many small animals make their homes here as well, mice, crickets, rabbits, and other four legged and six legged creatures.  They seem not to be alarmed by your passing.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
