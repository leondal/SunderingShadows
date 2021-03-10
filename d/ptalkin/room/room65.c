#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^ORANGE%^The street is bordered by flower boxes on both sides and people walk by, intent upon their business, with small children running past you laughing.  To the west is the Bank.");
set_smell("default", "%^BLUE%^You can smell chocolate and a floral scent mingling delightfully.");
set_listen("default", "%^CYAN%^You can hear the normal sounds of a small town, laughter, cursing and talk");
set_exits (([
"northeast" : PROOM+"room67.c",
"west" : PROOM+"bank.c",
"north" : PROOM+"room64.c",
"east" : PROOM+"room66.c",
"southeast" : PROOM+"room52.c",
"south" : PROOM+"room51.c"
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
if(!present("highelfcboy"))
new("/d/ptalkin/mon/highelf_cboy")->move(TO);
}
