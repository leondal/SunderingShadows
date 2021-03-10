#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long(@SVAHA
%^ORANGE%^
The street is widening out and you return to the main street within 
the small town. To the north you see a small square in front of the  
Church. You see an Admin bell in the belltower and the Ptalkin board
can be seen on the square to the north.%^RESET%^
SVAHA
);
set_smell("default", "%^BLUE%^You can smell chocolate and a floral scent mingling delightfully.");
set_listen("default", "%^CYAN%^You can hear the normal sounds of a small town, laughter, cursing and talk");
set_exits (([
"north" : PROOM+"square.c",
"northwest" : PROOM+"room63.c",
"east" : PROOM+"room67.c",
"south" : PROOM+"room65.c",
"southeast" : PROOM+"room66.c"
]));
set_items(([
"street" : "Around 6 feet wide, stones set in mortar, this street is exceedingly well kept",
"buildings" : "Buildings begin to take shape in front of you, colourful with flowers and bold signs",
"people" : "Peoples of every race and description saunter across the pathway and into the shops",
"shops" : "Small buildings of stone and mortar line both sides of the street",
"signs" : "The signs are wood slabs with names either carved or burned into them",
"tavern" : "Do you really need to ask",
"town" : "The town appears to be well kept, tidy and well known, perhaps you should investigate, you never know what surprises may await you"
]));
if(!present("highelffemale"))
new("/d/ptalkin/mon/highelf_female")->move(TO);
if(!present("highelfgirl"))
new("/d/ptalkin/mon/highelf_girl")->move(TO);
}
