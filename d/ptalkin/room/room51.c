#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^ORANGE%^You appear to have come to a small town of sorts.  Peoples of every description and race saunter along the well kept pathways, laughing, shouting and generally having a good time.  Small tidy buildings begin to take shape ahead of you.");
set_smell("default", "%^BOLD%^BLUE%^\nYou can smell cooking, meats being roasted, plus ale wafting on the breeze and is that candy you smell as well?");
set_listen("default", "%^CYAN%^You can hear laughter, shouting and the occaisional cursing as you walk along, plus children screaming with joy, and a dog barking.");
set_exits (([
"south" : PROOM+"hotel.c",
"north" : PROOM+"room65.c",
"west" : PROOM+"room50.c",
"east" : PROOM+"room52.c",
"southwest" : PROOM+"room49.c"
]));
set_items(([
"pathway" : "Small pebbles have been placed carefully, and somehow cemented into place, making the pathway smooth and colourful",
"buildings" : "Buildings begin to take shape in front of you, colourful with flowers and bold signs",
"people" : "Peoples of every race and description saunter across the pathway and into the shops",
"town" : "The town appears to be well kept, tidy and well known, perhaps you should investigate, you never know what surprises may await you"
]));
if(!present("highelffemale"))
new("/d/ptalkin/mon/highelf_female")->move(TO);
}
