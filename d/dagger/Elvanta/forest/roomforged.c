#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Inside the Elvanta forge works-Silversmiths");
set_long ("%^GREEN%^This is the silversmiths area.  A small <firepit> is placed in the middle of the room.  Several silversmiths are working at separate <tables>.  Each appears to be working on different items. <Cutlery>, <goblets>, <decanters>, and <jewellry> seem to be the primary items.  Although you can see some <swords> and <knives> being worked upon as well.  Both dwarves and elves work here side by side.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of cherry wood and coal reaches your nose.");
set_listen ("default", "The loud banging of the anvil has been replaced by soft thudding of smaller hammers shaping silver.");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomforgec",
"west" : "/d/dagger/Elvanta/forest/roomforgea",
]) );
set_items
(([
"firepit" : "The firepit is smaller and more intricate that the main firepit, as the smiths do finer and more delicate work here.",
"tables" : "Several tables four feet long and three feet wide are placed around the walls.  Gouges, burns and silver dust imply these tables have been used for many, many years.",
"cutlery" : "Fine pieces of silverware are made here.  Intricate designs of leaves, trees, flowers and animals cover the cutlery.",
"goblets" : "The goblets follow the same patterns as the cutlery.  Some are in shapes of flowers themselves.",
"decanters" : "Decanters of every shape and size lay in stages of completion upon the tables.",
"jewellry" : "The jewellry evokes ideas of finest lace and spider webs.",
"swords" : "Several sword blades lay upon a table. They are artfully embellished and are for ceremonial use.",
"knives" : "The knife blades, identical to the swords are also for ceremonial use."
]));
}
void reset(){
::reset();
if(!present("silversmith"))
new("/d/dagger/Elvanta/forest/mon/silversmith")->move(this_object());
if(!present("dwsmith"))
new("d/dagger/Elvanta/forest/mon/dwsmith")->move(this_object());
}
