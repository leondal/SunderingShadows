#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^You see ahead, a dark wall of foliage.  Small trees appear beside the path.  The grasslands are left behind you for the low plant life that survives beneath a great canopied forest.");
set_smell("default", "%^BOLD%^BLUE%^\nThe scent of the forest begins to reach you, damp earth and rotting vegetation.");
set_listen("default", "%^CYAN%^Sounds of the forest become louder, rustling, scurrying and calls of the wild.");
set_exits (([
"northwest" : PMID+"room126.c",
"southeast" : PMID+"room124.c"
]));
set_items(([
"trees" : "Mostly saplings appear, but you can see large age`d trees ahead of you.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
