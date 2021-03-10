#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^There is a new glow, a glow that hangs on the night air like incandescence.  Dancing, whirling, they begin to assume the forms of fairy creatures. Slight, airy things, they gather strength from the glow and from the music of pipes and take upon life.   These are the wood nymphs, elusive, childlike creatures as insubstantial as mist.");
set_smell("default", "%^BOLD%^BLUE%^\nYou can smell reeds, flowers and the soft scent of fresh water.");
set_listen("default", "%^CYAN%^All is stilled, 'cept the trickle of water over stone.");
set_exits (([
"east" : PMID+"room114.c",
"south" : PMID+"room116.c",
"southwest" : PMID+"room118.c"
]));
set_items(([
"lake" : "One of the many lakes in the area, this runs crystal clear and cold",
"flowers" : "Small buttercups, dandelions and other wildflowers grow around the rocks.",
"stones" : "Smoothed by time and water, they look comfortable enough to sit or lay upon",
"elms" : "With their great leafy boughs, these elms provide shade from the sun and shelter from the rain.",
"lakes" : "Lakes of many sizes, crystal clear dot the area.",
"ponds" : "Unlike the clear lakes, the ponds are full of reeds, algae and ducks.",
"pines" : "Tall stands of pine, situated in semicircles reach to the sky.",
"trees" : "Tall lanky birch trees rise to the sky, thier top boughs hidden within clouds it seems.",
"trunks" : "Almost paper white, the trunks seem to be like columns of an old amphitheater.",
"limbs" : "Going straight to the sky, you wonder how well they could be used as limbs for a bow",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"oaks" : "Massive, giant sized, huge, whatever words you may use to describe grandeur would fit here.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}
