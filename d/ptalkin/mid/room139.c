#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^You pass out of the shabby little village of the Sloridge Gnomes and then continue on your way.  To the east you see another path that takes you in another direction, perhaps to more forest, perhaps not.");
set_smell("default", "%^BOLD%^BLUE%^Once again, the scent of the forest fills your senses, pine needles, rotting vegetation and the smell of animals.");
set_listen("default", "%^CYAN%^Sounds of the forest return, bird calls, winds through the limbs of trees, scurrying animals.");
set_exits (([
"northwest" : PMID+"room140.c",
"southwest" : PMID+"room136.c"
]));
set_items(([
"village" : "It is a small area, full of mounds of hollowed out dirt and doesn't look none too clean.",
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
