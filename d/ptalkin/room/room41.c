#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^As you travel you wonder what kind of being or beast could survive in this desolate area.  Only the sound of the wind rustling through the dry, short grasses keeps you company.");
set_smell("default", "%^BOLD%^BLUE%^\nYou smell dry earth and stone");
set_listen("default", "%^CYAN%^You can hear scurrying sounds along with the occaisional bark.");
set_exits (([
"north" : PROOM+"room42.c",
"southeast" : PROOM+"room40.c",
"northwest" : PROOM+"room45.c",
"west" : PROOM+"room46.c",
"southwest" : PROOM+"room47.c"
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
if(!present("lizard"))
new("/d/dagger/Elvanta/forest/mon/lizard")->move(TO);
}
