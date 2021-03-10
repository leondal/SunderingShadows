#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Elvanta city, a kitchen within a home");
set_long ("%^GREEN%^The kitchen is a marvel.  Bright copper <pots> and <pans> line the <walls>.  <Foodstuffs> cover several <shelves>.  A small <table> and four <stools> sit off to one side.  A small <firepit> is int he middle of the room.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of meat being cooked on the firepit fills your senses.");
set_listen ("default", "You hear meat sizzling, and begin to wonder when dinner is.");
set_exits( ([
"up" : "/d/dagger/Elvanta/forest/roomH3c",
"east" : "/d/dagger/Elvanta/forest/roomH3"
]) );
set_items(([
"pots" : "Bright copper pots of all sizes hang on the walls.",
"pans" : "Bright copper pans of all sizes hang on the walls.",
"walls" : "The walls of the kitchen are also the inside of the tree and glow a pale red colour.",
"foodstuffs" : "Potatoes, onions, vegetables and spices fill several shelves.",
"shelves" : "The shelves too, are extruded from the tree.  The more you look at this architecture, the more you wonder.",
"table" : "A small table is off to one side with a bowl of flowers in the middle.",
"stools" : "Stools reaching about three feet high surround the table.",
"firepit" : "A four foot wide firepit lined with stones is what is used for cooking in the room.  A roast of some kind is turning over a spit, mmmmmm smells good."
]) );
}
