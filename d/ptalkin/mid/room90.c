#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^White-bark trees rise tall and lean lacing the blueness of the clear sky in fascinating designs.  You wind steadily forward through mazes of trunks and boughs.");
set_smell("default", "%^BOLD%^BLUE%^\nYou smell the earthy scents of damp earth and leaves.");
set_listen("default", "%^CYAN%^Fallen leaves and twigs are soaked with a heavy dew making a cushion that masks your passage.");
set_exits (([
"southwest" : PMID+"room89.c",
"southeast" : PMID+"room91.c"
]));
set_items(([
"town" : "A small town, ramshackle for the most part",
"trees" : "Tall lanky birch trees rise to the sky, thier top boughs hidden within clouds it seems.",
"trunks" : "Almost paper white, the trunks seem to be like columns of an old amphitheater.",
"limbs" : "Going straight to the sky, you wonder how well they could be used as limbs for a bow",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"oaks" : "Massive, giant sized, huge, whatever words you may use to describe grandeur would fit here.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
if(!present("cooshee"));
new("/d/ptalkin/mon/cooshee")->move(TO);
}
