#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The little vegetation starts to give way to golden sand.  Still a few bits of crabgrass and small growth clings to life upon the carpet of never ending sand.");
set_smell("default", "%^BOLD%^BLUE%^\nThe smell of heat wafting over the sands fills your senses.");
set_listen("default", "%^CYAN%^Crickets, mice and small birds make their presence heard.");
set_exits (([
"northeast" : PROOM+"room47.c"
]));
set_items(([
"path" : "It is a long and winding roadway to something, to somewhere.",
"sand" : "Sand, the colour of golden beads lies ahead of you in mile after mile of hills and dunes.",
"crabgrass" : "Small tufts of crabgrass and other small bits of vegetation dots the sand, but that is about all",
"vegetation" : "Small tufts of crabgrass and other bits of vegetation dots the sand, but that is about all"
]));
if(!present("lizard"))
new("/d/dagger/Elvanta/forest/mon/lizard")->move(TO);
}
