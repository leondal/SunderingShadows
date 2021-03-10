#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void init(){
	::init();
	add_action("read_func", "read");
}
void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^GREEN%^The path now winds through scrubby bushes, as the grasslands recede to have the forest take over.  The bushes are so crowded it is difficult to travel through, and even more difficult to take direction. There is a small sign by the side of the path, reading it would be a good idea");
set_smell("default", "%^BOLD%^BLUE%^\nThe scent of the forest begins to reach you, damp earth and rotting vegetation.");
set_listen("default", "%^CYAN%^Crickets give way to scurrying small creatures, and the sounds of scrabbling claws.");
set_exits (([
"north" : PMID+"room68.c",
"south" : PROOM+"room23.c"
]));
set_items(([
"path" : "It is a long and winding roadway to something, to somewhere.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are going.",
"forests" : "Lush green canopies of leaves cover the skyline"
]));
if(!present("rattlesnake"))
new("/d/dagger/Elvanta/forest/mon/rattlesnake")->move(TO);
}
int read_func(string str){
	write("You are entering the forest area of Ptalkin, home to the Sylvan elves.  More unknown monsters and friends await you, but, should you kill the mud-puppy you will incure the wrath of the Elves.  You are welcome to travel, to fight, to love, but remember, this IS the home of the Sylvan Elves");
	return 1;
}
