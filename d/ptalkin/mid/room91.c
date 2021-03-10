#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^On the edges of the path, in some spots, there are tall stands of pines enclosing areas in half circles as if to provide protection during the night should you wish to camp.");
set_smell("default", "%^BOLD%^BLUE%^\nYou smell the earthy scents of damp earth and leaves.");
set_listen("default", "%^CYAN%^Fallen leaves and twigs are soaked with a heavy dew making a cushion that masks your passage.");
set_exits (([
"northeast" : PMID+"room92.c",
"northwest" : PMID+"room90.c"
]));
set_items(([
"town" : "A small town, ramshackle for the most part",
"pines" : "Tall stands of pine, situated in semicircles reach to the sky.",
"trees" : "Tall lanky birch trees rise to the sky, thier top boughs hidden within clouds it seems.",
"trunks" : "Almost paper white, the trunks seem to be like columns of an old amphitheater.",
"limbs" : "Going straight to the sky, you wonder how well they could be used as limbs for a bow",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"oaks" : "Massive, giant sized, huge, whatever words you may use to describe grandeur would fit here.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
if(!present("mudpuppy"));
new("/d/ptalkin/mon/mudpuppy")->move(TO);
}
