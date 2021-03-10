#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^You see a break in the path ahead of you, as the trees begin to thin.  Smoke is rising in lazy spirals, and you can hear water splashing.");
set_smell("default", "%^BOLD%^BLUE%^\nThe occasional waft of perfume fills the air.");
set_listen("default", "%^CYAN%^Over the drone of insects you hear the occasional lap of water.");
set_exits (([
"north" : PMID+"room77.c",
"south" : PMID+"room75.c"
]));
set_items(([
"trees" : "Large aged oaks surround you, making it difficult to see ahead to any distance.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
