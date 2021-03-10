#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A small village");
set_long("%^ORANGE%^It appears you have stumbled upon a small village, of some sort of strange creature.  The mounds stand four to six feet in height and about twenty feet around.  Bright tattered curtains are hung from windows carved into the mounds and small wooden doorways are set within the dirt walls.  You see some sort of small two legged creature rushing about, sweeping, tending gardens and talking to each other.  They do not appear either aware of your presence or they just don't really care.");
set_smell("default", "%^BOLD%^BLUE%^Smoke rises from the mounds, smelling slightly of peat.");
set_listen("default", "%^CYAN%^You can hear childrens laughter, women muttering and men yelling over the sounds of the forest.");
set_exits (([
"north" : PMID+"room136.c",
"northwest" : PMID+"room137.c",
"west" : PMID+"room134.c"
]));
set_items(([
"village" : "It is a small area, full of mounds of hollowed out dirt and doesn't look none too clean",
"gardens" : "Creatures attend small gardens, but it looks like the weeds are winning, a little water wouldn't hurt either",
"creature" : "You will get to them in time...and you won't want to",
"doorways" : "The doorways look to have been hacked out of the mound to form a primitive entrance",
"windows" : "Like the doorways, the windows have been badly carved from the mounds, but do serve a purpose, like yelling at the neighbour",
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
if(!present("sloridgegnome"))
new("/d/ptalkin/mon/sloridgegnome")->move(TO);
if(!present("sloridgegnomeF"))
new("/d/ptalkin/mon/sloridgegnomeF")->move(TO);
if(!present("mudpuppy"))
new("/d/ptalkin/mon/mudpuppy")->move(TO);
}
