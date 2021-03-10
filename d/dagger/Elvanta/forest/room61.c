#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The <walkway> continues to take you to somewhere within the trees.  Small children run past you, laughing loudly, inviting you to come join them.  Ahead of you a cluster of buildings appears to the west.  They appear to be a hotel of some sort, as the sign reads 'The Knightly Inn'.%^RESET%^");
set ("night long", "The <walkway> continues to take you to somewhere within the trees.  People are travelling past you laughing and smiling.  Ahead of you a cluster of buildings throw light upon the way.  The building appears to be a hotel of some sort, as the sign reads 'The Knightly Inn'.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nLingering smoke and the scent of pine mingle for a pleasant warm aroma.");
set_listen ("default", "You hear the strains of music, sounds of laughter and some off key singing");
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/room60",
"south" : "/d/dagger/Elvanta/forest/room62"
]));
set_items
(([
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"circle" : "You note as you peer through the trees, that the city is laid out in an ever diminishing circle.  You wonder what is at its heart.",
"city" : "The fabled city of Elvanta lies before you, gleaming of silver, nacre and wood.  'Tis a wonder to behold.",
"owl" : "A very large old owl hoots at you from within the tree.  He is about four feet tall, brown, of course, and does not look too happy to see you.",
"houses" : "The houses you see ahead of you appear also to be molded from the trees themselves.  They are more rounded than what you are used to but blend in with the forest so well that they are difficult to see unless you are close to them.",
"guard shacks" : "A shack is hardly what one would call these marvels of workmanship.  They gleam with golden colour as years of polishing leaves a sheen to them.",
"planks" : "As you have noticed before these planks are made of finest wood, from a tree unknown to you, as the colour is a deep purple.  The carvings in the planks are of scenes of hunts, wars, and history.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"branches" : "The branches can be walked upon they are so wide.  They travel through the forest like a maze.  It looks as though somehow they were coaxed to form roadways for the elves who live here.",
"children" : "Children scramble through the forest, running up and down the huge trees as if it was their personal playground, but, perhaps it is and you are the intruder.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"buildings" : "Buildings large and small loom ahead of you, in a curve, closer inspection will be required",
"staircase" : "The staircase appears in front of you, how is that possible?  The vines holding the staircase above ground seems to be molded to the stairs.  Intricate designs of animals and flowers entweined adorn the stairs themselves.  The artwork is phenomenal.  Someone spent a lifetime carving these.",
"walkway" : "As you travel along the walkway you can't help notice how well it is built.  There is no swaying or shaking of the walkway.  The trees themselves seem to have molded the walkway and it is as sturdy as the ground below.",
"building" : "You look ahead and see a small building within the trees.  It looks like a guard post, perhaps.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
