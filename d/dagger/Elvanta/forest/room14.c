#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^As you pause to look at the <walkway> you are upon, you can't help but notice the fine workmanship.  The vines themselves are a wonder to behold as they weave themselves into the wooden <planks>.%^RESET%^");
set ("night long", "%^CYAN%^As you pause to look at the <walkway> you are upon, you can't help but notice the fine workmanship.  The vines themselves are a wonder to behold as they weave themselves into the wood <planks>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can smell odours of cooking and smoke from the chimneys.");
set_listen ("default", "You hear the rustling of the wind through the trees, and soft murmurs of voices.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/room15",
"southwest" : "/d/dagger/Elvanta/forest/room13"
]));
set_items
(([
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"planks" : "As you have noticed before these planks are made of finest wood, from a tree unknown to you, as the colour is a deep purple.  The carvings in the planks are of scenes of hunts, wars, and history.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"branches" : "The branches can be walked upon they are so wide.  They travel through the forest like a maze.  It looks as though somehow they were coaxed to form roadways for the elves who live here.",
"children" : "Children scramble through the forest, running up and down the huge trees as if it was their personal playground, but, perhaps it is and you are the intruder.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"staircase" : "The staircase appears in front of you, how is that possible?  The vines holding the staircase above ground seems to be molded to the stairs.  Intricate designs of animals and flowers entweined adorn the stairs themselves.  The artwork is phenomenal.  Someone spent a lifetime carving these.",
"walkway" : "As you travel along the walkway you can't help notice how well it is built.  There is no swaying or shaking of the walkway.  The trees themselves seem to have molded the walkway and it is as sturdy as the ground below.",
"building" : "You look ahead and see a small building within the trees.  It looks like a guard post, perhaps.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
void reset() {
::reset();
if(!present("rattlesnake"))
new("/d/dagger/Elvanta/forest/mon/rattlesnake")->move(this_object());
}
