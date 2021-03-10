#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You seem to be coming to a straight pathway ahead of you.  A small <house> is set to the south of you, and some <buildings> to the west.  Finally, you come to some part of this city which is inhabited.%^RESET%^");
set ("night long", "%^CYAN%^You seem to be coming to a straight pathway ahead of you.  A small <house> is set to the south of you, and some <buildings> to the west.  Finally, you come to some part of this city which is inhabited.%^RESET%^");
set_smell("default", "%^MAGENTA%^\nThe smell of the pine forest, smoke from chimneys, and a forge mingle in the air.");
set_listen ("default", "You hear the sounds of creatures of the forest, of elves moving to and fro, and the slight tink-tink of metal striking metal.");
set_exits (([
"southeast" : "/d/dagger/Elvanta/forest/room40",
"south" : "/d/dagger/Elvanta/forest/roomH3",
"west" : "/d/dagger/Elvanta/forest/room42"
]));
set_items
(([
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"house" : "A small house, part of the great redwood is here.  You cannot tell where the house leaves off and the tree begins.",
"buildings" : "Some smaller buildings are ahead of you, but at this distance it is difficult to see what they are for.  You do, however, here, metal striking metal and assume a forge of some kind is ahead.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
