#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Inside the Elvanta forge works - Storage Room");
set_long ("%^GREEN%^This is the storage room for the forge works.  Piles of iron, copper, gold, silver and other metals lay in neat ordered heaps.  Large bins of oak, cherry, birch and coal are set against the west wall.  Shovels, tongs and other lifting utensils line the north wall.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of cherry wood and coal reaches your nose.");
set_listen ("default", "Clank, tink, sizzle and curses surround you.");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomforgeb",
"east" : "/d/dagger/Elvanta/forest/roomforgea"
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
