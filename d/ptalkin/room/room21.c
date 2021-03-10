#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The path now winds through scrubby bushes, as the grasslands recede to have the forest take over.  The bushes are so crowded it is difficult to travel through, and even more difficult to take direction.");
set_smell("default", "%^BOLD%^BLUE%^\nThe scent of the forest begins to reach you, damp earth and rotting vegetation.");
set_listen("default", "%^CYAN%^Crickets give way to scurrying small creatures, and the sounds of scrabbling claws.");
set_exits (([
"northeast" : PROOM+"room22.c",
"southwest" : PROOM+"room20.c"
]));
set_items(([
"path" : "It is a long and winding roadway to something, to somewhere.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are going.",
"forests" : "Lush green canopies of leaves cover the skyline"
]));
if(!present("rat"))
new("/d/shadow/mon/rat")->move(TO);
}
