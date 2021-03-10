#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^BLUE%^You are now walking along white cliffs beside the ocean.  Water laps its way up the side of the cliff, eating away at the dirt and sand.  A small town appears ahead of you, and a dock with rafts.");
set_smell("default", "%^BOLD%^BLUE%^\nThe sea air reaches you, filled with the smell of brine.");
set_listen("default", "%^CYAN%^The waves crashing upon the cliffs drowns out any other sound.");
set_exits (([
"northwest" : PMID+"room83.c",
"southwest" : PMID+"room78.c",
"east" : PMID+"roombank.c",
"north" : PMID+"room81.c",
"south" : PMID+"room77.c",
"west" : PMID+"room79.c"
]));
set_items(([
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
void reset(){
::reset();
if(!present("crab"));
new("/d/islands/common/mon/crab")->move(TO);
}
