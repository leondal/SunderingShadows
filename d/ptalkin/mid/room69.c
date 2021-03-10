#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^You walk slowly, picking your way along the winding path that has now narrowed beyond the grasslands and which seems to disappear into a wall of trees and bushes.");
set_smell("default", "%^BOLD%^BLUE%^\nThe scent of the forest begins to reach you, damp earth and rotting vegetation.");
set_listen("default", "%^CYAN%^Sounds of the forest become louder, rustling, scurrying and calls of the wild.");
set_exits (([
"north" : PMID+"room70.c",
"south" : PMID+"room68.c"
]));
set_items(([
"trees" : "Mostly saplings appear, but you can see large age`d trees ahead of you.",
"bushes" : "Pale wild rose bushes and carigana make up most of the bushes, but several angular looking plants greet your eyes as well.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
void reset(){
::reset();
if(!present("sylvanelf_male"));
new("/d/ptalkin/mon/sylvanelf_male")->move(TO);
}
