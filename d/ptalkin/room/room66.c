#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^ORANGE%^You have reached the centre of the small town.  Park benches, small tables, and a fountain complete the scene of peace, quiet, and contentment.  A number of families seem to be enjoying the outdoors with picnics and games.");
set_smell("default", "%^BLUE%^You can smell flowers and food in the air.");
set_listen("default", "%^CYAN%^You can hear the normal sounds of a small town, laughter, cursing and talk");
set_exits (([
"north" : PROOM+"room67.c",
"northeast" : PROOM+"room55.c",
"northwest" : PROOM+"room64.c",
"south" : PROOM+"room52.c",
"southeast" : PROOM+"room53.c",
"southwest" : PROOM+"room51.c",
"east" : PROOM+"room54.c",
"west" : PROOM+"room65.c"
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
new("/realms/svaha/items/fountain")->move(TO);
new("/d/ptalkin/items/table")->move(TO);
new("/d/ptalkin/items/benches")->move(TO);
if(!present("highelfgirl"))
new("/d/ptalkin/mon/highelf_girl")->move(TO);
if(!present("highelffemale"))
new("/d/ptalkin/mon/highelf_female")->move(TO);
}
