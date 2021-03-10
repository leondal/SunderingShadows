#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A small village");
set_long("%^ORANGE%^You have found the inhabitants of the mounds, and now perhaps wish you hadn't.  You have reached a small settlement of Slordige Gnomes.  They are a small creature (people wouldn't really fit), standing maybe three feet high.  They are furry, unkept ground creatures which for the most part appear to have just poked their heads up out of their earthen dens.");
set_smell("default", "%^BOLD%^BLUE%^Smoke rises from the mounds, smelling slightly of peat.");
set_listen("default", "%^CYAN%^You can hear childrens laughter, women muttering and men yelling over the sounds of the forest.");
set_exits (([
"northeast" : PMID+"room139.c",
"west" : PMID+"room137.c",
"south" : PMID+"room135.c",
"southwest" : PMID+"room134.c"
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
void reset() {
::reset();
if(!present("sloridgegnome"))
new("/d/ptalkin/mon/sloridgegnome")->move(TO);
if(!present("sloridgegnome"))
new("/d/ptalkin/mon/sloridgegnome")->move(TO);
if(!present("sloridgegnomeF"))
new("/d/ptalkin/mon/sloridgegnomeF")->move(TO);
if(!present("mudpuppy"))
new("/d/ptalkin/mon/mudpuppy")->move(TO);
}
