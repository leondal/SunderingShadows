#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The winding path wanders where it will.  Large trees tower above you, shutting out sunlight and moonlight to give the forest a sense of timelessness.");
set_smell("default", "%^BOLD%^BLUE%^Scents from the forest surround you, pine needles, wind through the trees, and the occaisional tattered bit of moss hanging from the trees.");
set_listen("default", "%^CYAN%^Calling birds, grunts and groans of small animals and the occaisional loud thump reaches your ears.");
set_exits (([
"east" : PMID+"room146.c",
"west" : PMID+"room144.c",
"northeast" : PMID+"room147.c"
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
if(!present("aurumvorax"));
new("/d/dagger/Elvanta/forest/mon/aurumvorax")->move(TO);
}
