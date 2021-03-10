#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^
The winding path seems to take a northeast turn as it wanders where it
will.  Large trees tower above you, shielding the sky with large boughs
of green.  Ahead of you, a break in the forest appears and you catch
the occasional word or two upon the wind.");
set_smell("default", "%^BOLD%^BLUE%^Damp earth and scrubby bushes, both join to fill your senses.");
set_listen("default", "%^CYAN%^Within the forest, the mingled sound of insect life and animal life whisper.");
set_exits (([
"northeast" : PMID+"room133.c",
"south" : PMID+"room130.c",
"southeast" : PMID+"room131.c"
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
if(!present("cottonmouth"))
new("/d/tharis/monsters/snakes/cottonmouth")->move(TO);
}
