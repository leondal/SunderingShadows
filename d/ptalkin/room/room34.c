#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The ground rises underfoot, broken now and again by granite boulders.  The emptiness interupted only by the sounds of small wildlife and the odd bird.  The emptiness stretches before you, with short growths of vegetation, the soil badly leached.");
set_smell("default", "%^BOLD%^BLUE%^\nYou smell the dry earth and long sweet grasses");
set_listen("default", "%^CYAN%^You can hear scurrying sounds along with the occaisional bark.");
set_exits (([
"north" : PROOM+"room35.c",
"south" : PROOM+"room33.c"
]));
set_items(([
"grasses" : "Three to four feet high wild grassess appear to sway to the music of the breeze.",
"hills" : "Dust coloured hills appear, somewhat barren, but you can hear sounds of life.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are going.",
"rocks" : "Small grey and tan coloured rocks make walking the pathway somewhat hard on your feet",
"boulders" : "Some of the boulders look as large as a small house",
"tumbleweed" : "Dead branches woven into a ball scatter the area, like a childs toy, rolling here and there",
"bushes" : "Dead branches woven into a ball scatter the area, like a childs toy, rolling here and there"
]));
if(!present("sparrow"))
new("/d/dagger/Elvanta/forest/mon/sparrow")->move(TO);
}
