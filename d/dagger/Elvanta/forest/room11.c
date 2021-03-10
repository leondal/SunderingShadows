#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You are now withing the trees themselves, as they are so entwined, they appear to become one.  Ahead of you lies a small building and to the east and west more <walkway>.%^RESET%^");
set ("night long", "%^CYAN%^You are now within the trees themselves, as they are so entwined, they appear to become one.  The light from the globes hanging throughout the forest gives off a glowing welcome.  Ahead of you lies a small building and to the east and west more <walkway>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can smell the fragrance of pine needles and freshly dampened earth.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roomG1.c",
"south" : "/d/dagger/Elvanta/forest/room10",
"east" : "/d/dagger/Elvanta/forest/room12",
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"stairways" : "Intricate stairways rise from the middle of some of the trees ahead it seems.  Vines of an unknown plant form the railings and supports for the stairs.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"staircase" : "The staircase appears in front of you, how is that possible?  The vines holding the staircase above ground seems to be molded to the stairs.  Intricate designs of animals and flowers entweined adorn the stairs themselves.  The artwork is phenomenal.  Someone spent a lifetime carving these.",
"walkway" : "As you travel along the walkway you can't help notice how well it is built.  There is no swaying or shaking of the walkway.  The trees themselves seem to have molded the walkway and it is as sturdy as the ground below.",
"building" : "You look ahead and see a small building within the trees.  It looks like a guard post, perhaps.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
