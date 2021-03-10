#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^ORANGE%^The street is narrow, although the occasional bucket of flowers appears to brighten the way.  To the east is the Armoury.");
set_smell("default", "%^BLUE%^\nOdours of cooking and flowers fill your nose.");
set_listen("default", "%^CYAN%^You can hear the normal sounds of a small town, laughter, cursing and talk");
set_exits (([
"east" : PROOM+"armour.c",
"north" : PROOM+"room58.c",
"south" : PROOM+"room56.c",
"southwest" : PROOM+"room55.c"
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
}
