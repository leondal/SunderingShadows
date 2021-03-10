#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A small village");
set_long("%^ORANGE%^As you travel closer to the mounds, you notice small doorways and windows, hung with brightly coloured tattered bits of cloth.  You see small gardens, terribly unkept and some movement by the mounds.");
set_smell("default", "%^BOLD%^BLUE%^Damp earth and scrubby bushes, both join to fill your senses.");
set_listen("default", "%^CYAN%^You hear a word or two cast upon the breeze, mingling with the drone of insect life");
set_exits (([
"west" : PMID+"room133.c",
"east" : PMID+"room135.c",
"north" : PMID+"room137.c",
"northeast" : PMID+"room136.c",
"northwest" : PMID+"room138.c"
]));
set_items(([
"hills" : "Hills no larger than small huts appear to have been placed here randomly, but close together to form a tiny village.",
"mounds" : " Mounds no larger than small huts appear to have been placed here randomly, but close together to form a tiny village.",
"woods" : "Larger than life, trees loom about you, rising 200 - 300 feet overhead, their tops hidden within the skies.",
"trees" : "Large oaks, elms, chestnut and pine trees appear ahead.",
"bushes" : "The bushes are mostly carrigana, holly and everbright.  Greens, yellows and reds meet the eye.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
void reset(){
::reset();
if(!present("sloridgegnome"));
new("/d/ptalkin/mon/sloridgegnome")->move(TO);
}
