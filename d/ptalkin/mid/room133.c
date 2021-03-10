#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A small village");
set_long("%^ORANGE%^You find the trees begin to thin in the area just ahead of you.  Small hills or mounds seem to have been formed, but by whom, or what, you don't know.");
set_smell("default", "%^BOLD%^BLUE%^Damp earth and scrubby bushes, both join to fill your senses.");
set_listen("default", "%^CYAN%^Within the forest, the mingled sound of insect life and animal life whisper.");
set_exits (([
"north" : PMID+"room138.c",
"northeast" : PMID+"room137.c",
"east" : PMID+"room134.c",
"southwest" : PMID+"room132.c"
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
