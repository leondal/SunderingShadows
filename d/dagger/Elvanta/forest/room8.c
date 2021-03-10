#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set("day long", "%^ORANGE%^The trail ends.  Abruptly.  No warning.  But, there is a huge tree in front of you, with some sort of writing upon it.  Perhaps, you could enter the tree as there seems to be a hollow of sorts within it.%^RESET%^");
set("night long", "%^CYAN%^The trail ends. Abruptly.  No warning.  However, you can see a hollow in the tree standing right in front of you.  Perhhaps you could enter the tree somehow.%^RESET%^");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"enter" : "/d/dagger/Elvanta/forest/room9",
"southwest" : "/d/dagger/Elvanta/forest/room7"
]));
set_items
(([
"tree" : "This tree is enormous.  It appears to be hollow, yet you can see something like stairs within it.  How different.",
"writing" : "As you look closer at the writing upon the tree you see that it is written in Elvish, if you could understand it, you would realize it is the answer to the question of where the city of Elvanta is.",
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"stairways" : "Intricate stairways rise from the middle of some of the trees ahead it seems.  Vines of an unknown plant form the railings and supports for the stairs.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so."
]));
}
