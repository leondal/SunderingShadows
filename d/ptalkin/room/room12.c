#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The path ahead leads through grasslands, bushlands and forests, the latter not clearly visible as yet.  You can however, make out the shadowy canopies of the massive trees.");
set_smell("default", "%^BOLD%^BLUE%^\nRain soaked grasses sends clouds of pollen into the air making you sneeze.");
set_listen("default", "%^CYAN%^Crickets, mice and small birds make their presence heard.");
set_exits (([
"north" : PROOM+"room13.c",
"south" : PROOM+"room11.c"
]));
set_items(([
"path" : "It is a long and winding roadway to something, to somewhere.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are going.",
"forests" : "Lush green canopies of leaves cover the skyline"
]));
if(!present("lizard"))
new("/d/dagger/Elvanta/forest/mon/lizard")->move(TO);
if(!present("highelfboy"))
new("/d/ptalkin/mon/highelf_boy")->move(TO);
if(!present("highelfgirl"))
new("/d/ptalkin/mon/highelf_girl")->move(TO);
}
