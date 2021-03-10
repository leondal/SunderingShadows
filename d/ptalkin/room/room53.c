#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^ORANGE%^The street is well tended, with flower beds along the sides.  Many shops line the street their names carved or burned into wooden signs, hung by metal chains.  To the south is D'seon's Inn and the the east is the Healers");
set_smell("default", "%^BLUE%^\nThe odour of flowers mingles with ale and smoke");
set_listen("default", "%^CYAN%^You can hear the normal sounds of a small town, laughter, cursing and talk");
set_exits (([
"north" : PROOM+"room54.c",
"northwest" : PROOM+"room66.c",
"west" : PROOM+"room52.c",
"south" : PROOM+"inn.c",
"east" : PROOM+"healer.c"
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
}
