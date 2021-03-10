#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Inside the Elvanta forge works_Goldsmiths");
set_long ("%^GREEN%^This is the goldsmiths workshop.  A small (firepit) is placed off to one side of the shop.  Several goldsmiths are working at different <tables> upon <jewellry>, <plates> and <arms>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of cherry wood and coal reaches your nose.");
set_listen ("default", "The loud clanking of anvils has been replaced by soft thudding of smaller hammers shaping gold.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomforged",
"west" : "/d/dagger/Elvanta/forest/roomforge",
]) );
set_items
(([
"firepit" : "The firepit is smaller and more intricate that the main firepit, as the smiths do finer and more delicate work here.",
"tables" : "Several tables four feet long and three feet wide are placed around the walls.  Gouges, burns and gold dust imply these tables have been well used over the centuries.",
"jewellry" : "Delicate items of gold abound in piles.  Chains as fine as hair, earrings set with rare and precious stones, and rings in shapes to bedazzle the most jaded palette lay here.",
"plates" : "Golden plates with designs of flora, fauna, war and peace are made here.  Each is a story in itself and would grace any home with its presence.",
"arms" : "Swords, knives and shields bearing coats of arms of many clans are forged here.  These are family treasures to be adored and passed down like legends of time."
]));
}
void reset(){
::reset();
if(!present("goldsmith"));
new("/d/dagger/Elvanta/forest/mon/goldsmith")->move(this_object());
}
