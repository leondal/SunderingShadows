#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^This part of the path appears to be well travelled.  At least three feet wide, the path does not appear to have been left just to nature.  Small rocks appear underfoot, but not uncomfortably so, and the larger boulders appear to have been moved out of the way.");
set_smell("default", "%^BOLD%^BLUE%^\nYou smell the dry earth and long sweet grasses");
set_listen("default", "%^CYAN%^You can hear scurrying sounds along with the occaisional bark.");
set_exits (([
"north" : PROOM+"room49.c",
"west" : PROOM+"room31.c",
"south" : PROOM+"room28.c",
"southwest" : PROOM+"room29.c"
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
if(!present("highelfmale"))
new("/d/ptalkin/mon/highelf_male")->move(TO);
if(!present("highelffemale"))
new("/d/ptalkin/mon/highelf_female")->move(TO);
}
