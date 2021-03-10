#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^ORANGE%^The street widens to approximately 6 feet and is bordered by flower boxes set along the sides.  To the north is the Weapon's Shop.");
set_smell("default", "%^BLUE%^You can smell chocolate and a floral scent mingling delightfully.");
set_listen("default", "%^CYAN%^You can hear the normal sounds of a small town, laughter, cursing and talk");
set_exits (([
"north" : PROOM+"weapon.c",
"east" : PROOM+"room55.c",
"west" : PROOM+"room64.c",
"south" : PROOM+"room66.c",
"southeast" : PROOM+"room54.c",
"southwest" : PROOM+"room65.c"
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
if(!present("highelfmale"))
new("/d/ptalkin/mon/highelf_male")->move(TO);
if(!present("highelffemale"))
new("/d/ptalkin/mon/highelf_female")->move(TO);
if(!present("highelfboy"))
new("/d/ptalkin/mon/highelf_boy")->move(TO);
if(!present("highelfgirl"))
new("/d/ptalkin/mon/highelf_girl")->move(TO);
if(!present("highelfbaby"))
new("/d/ptalkin/mon/highelf_baby")->move(TO);
}
