#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^It is an awesome sight, you cannot help but feel the undeniable presence of a life force in these woods so incredibly ancient that it commands a deep grudging respect, if only for its years within this realm.");
set_smell("default", "%^BOLD%^BLUE%^Damp earth and scrubby bushes, both join to fill your senses.");
set_listen("default", "%^CYAN%^Within the forest, the mingled sound of insect life and animal life whisper.");
set_exits (([
"northwest" : PMID+"room132.c",
"south" : PMID+"room128.c",
"southwest" : PMID+"129.c",
"west" : PMID+"room130.c"
]));
set_items(([
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
if(!present("barrel"))
new("/realms/general/mon/barrel")->move(TO);
}
