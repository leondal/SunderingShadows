#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^Long buff coloured grasses sway in the slight breeze.  Rocks and large boulders dot the rugged terrain.  Small tumbleweed bushes are tossed this way and that by gentle gusts of wind.");
set_smell("default", "%^BOLD%^BLUE%^\nYou smell the dry earth and long sweet grasses");
set_listen("default", "%^CYAN%^You can hear scurrying sounds along with the occaisional bark.");
set_exits (([
"northwest" : PROOM+"room28.c",
"south" : PROOM+"room26.c"
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
if(!present("rat"))
new("/d/shadow/mon/rat")->move(TO);
if(!present("highelfgirl"))
new("/d/ptalkin/mon/highelf_girl")->move(TO);
}
