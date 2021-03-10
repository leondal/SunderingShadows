#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^You have reached the end of the dense forest area.  Ahead of you lies immense crag ridden mountains, looming out of a thick grey mist.  The path becomes rough, strewn with rock and other debris.  This area is the definition of the word ominous.");
set_smell("default", "%^BOLD%^BLUE%^The mist carries with it an odour of stale death.");
set_listen("default", "%^CYAN%^The sounds of the forest begin to slide away, leaving a quietness you can almost touch.");
set_listen("default", "%^CYAN%^The sounds of the forest begin to slide away, to leave a quietness you can almost touch.");
set_exits(([
"north" : PDROW+"room151.c",
"southeast" : PMID+"room149.c"
]));
set_items(([
"mountains" : "Craggy, broken, sharp mountains loom from the mist ahead of you.",
"rock" : "Small rubble, sharp to your feet and grey in colour lay where the mountains have tumbled.",
"mist" : "A thick grey mist covers the area ahead of you, making it difficult to see.",
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
if(!present("babu"));
new("/d/deku/monster/babu")->move(TO);
}
