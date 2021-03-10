#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^While you are walking through this city you notice that not much appears to be going on here.  You are, it seems on the outer limits of the city and a few <houses> and <guard shacks> are all that is here.  The main part of the city must be further ahead.%^RESET%^");
set ("night long", "%^CYAN%^While you are walking through this city you notice that not much appears to be going on here.  You are, it seems on the outer limits of the city as the lights appear to be more in abundance further ahead.  A few <houses> and <guard shacks> are all that is here, it seems.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can smell odours of cooking and smoke from the chimneys.");
set_listen ("default", "You hear the rustling of the wind through the trees, and soft murmurs of voices.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomG6",
"south" : "/d/dagger/Elvanta/forest/room27",
"northwest" : "/d/dagger/Elvanta/forest/room29"
]));
set_items
(([
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"houses" : "The houses you see ahead of you appear also to be molded from the trees themselves.  They are more rounded than what you are used to but blend in with the forest so well that they are difficult to see unless you are close to them.",
"guard shacks" : "A shack is hardly what one would call these marvels of workmanship.  They gleam with golden colour as years of polishing leaves a sheen to them.",
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
void reset(){
::reset();
if(!present("elf"));
new("/d/dagger/Elvanta/forest/mon/elf")->move(this_object());
}
