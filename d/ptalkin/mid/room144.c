#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^With what little light there is you see the light dance and glitter against rough bark and the soft green moss that clings in dark patches to the massive trees.");
set_smell("default", "%^BOLD%^BLUE%^Scents from the forest surround you, pine needles, wind through the trees, moss hanging in tattered strips.");
set_listen("default", "%^CYAN%^Calling birds, grunts and groans of small animals and the occaisional loud thump reaches your ears.");
set_exits (([
"west" : PMID+"room143.c",
"east" : PMID+"room145.c"
]));
set_items(([
"hills" : "Hills no larger than small huts appear to have been placed here randomly, but close together to form a tiny village.",
"moss" : "Dark patches of moss clings to the massive trees, as you reach out to touch it, you realize the moss is as soft as it looks.",
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
