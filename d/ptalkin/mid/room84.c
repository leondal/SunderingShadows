#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A small town");
set_long("%^BOLD%^RED%^You can hear the sounds coming from the southwest area, the sounds of laughter, and the rough talk of sailors.");
set_smell("default", "%^BOLD%^BLUE%^\nThe smell of sea air is overcome by the smell of stale ale and smoke.");
set_listen("default", "%^CYAN%^Sounds of laughter, cursing and clinking mugs abounds.");
set_exits (([
"east" : PMID+"room83.c",
"northeast" : PMID+"room85.c",
"southeast" : PMID+"room79.c"
]));
set_items(([
"tavern" : "The run down look of the tavern almost puts you off of going into there, however, the sounds of laughter draw you closer.",
"sailors" : "What can one say, they are rough, rowdy, ready for women and trying to find some",
"windows" : "They are crudely cut into the building, only to let in some fresh air",
"doorways" : "Well, it's the way in, however, the way out, may be a bit more dramatic...",
"ocean" : "The smell of brine reaches you as you peer down into crystal clear green/blue waters",
"dirt" : "Dirt walls seem to hold up the cliffs, a pale yellow brown colour, with roots from trees sticking out like wild hair",
"sand" : "Sand mixes with the dirt, making you wonder just how safe this cliff really is.",
"cliffs" : "Sixty feet to the ocean is a long way to drop......",
"town" : "A small town appears ahead of you, ramshackle for the most part",
"dock" : "Unlike the town, this dock appears to be well made and exceedingly well maintained.",
"rafts" : "While they appear to be rather small, holding only 3 - 4 individuals, they too, are well made and maintained.",
"trees" : "Mostly saplings appear, but you can see large age`d trees ahead of you.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
