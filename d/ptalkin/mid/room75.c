#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The forest stretches on before you, with no indication of a break other than the single path, between the great trees.");
set_smell("default", "%^BOLD%^BLUE%^\nThe occasional waft of perfume fills the air.");
set_listen("default", "%^CYAN%^The insects maintain their steady drone in contentment.");
set_exits (([
"north" : PMID+"room76.c",
"southwest" : PMID+"room74.c"
]));
set_items(([
"trees" : "The trees thicken here, becoming huge monuments to time itself, everlasting, imposing and quite serene.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
void reset(){
::reset();
if(!present("owlbear"));
new("/d/dagger/Elvanta/forest/mon/owlbear")->move(TO);
}
