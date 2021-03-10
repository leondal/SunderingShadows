#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The floor of the forest is soft and smooth, a comfortable bed compared to the brush of the grasslands.");
set_smell("default", "%^BOLD%^BLUE%^\nThe scent of the forest begins to reach you, damp earth and rotting vegetation.");
set_listen("default", "%^CYAN%^Sounds of the forest become louder, rustling, scurrying and calls of the wild.");
set_exits (([
"north" : PMID+"room74.c",
"southwest" : PMID+"room72.c"
]));
set_items(([
"trees" : "Mostly saplings appear, but you can see large age`d trees ahead of you.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
void reset(){
::reset();
if(!present("gargantua"));
new("/d/cursed/mon/gargantua")->move(TO);
}
