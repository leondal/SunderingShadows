//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light",2);
set_property("indoors", 0);

set_short("%^BLUE%^The Dario River");
set_long("%^BLUE%^The Dario River lies before you, a jewel in a world of
refuse.  After your long and arduous trek through the desert you cannot
but wonder and gape at the free flowing river.  The river water babbles
over pink stones, while gems wink out at you in colours of gold, green and
deep red.  You can feel the waters edge lap against your weary feet, 
cooling them, trickling through your toes, sending shivers up your spine.
Plants of every hue, purple, blue, yellow, red, orange, pink, and other
colours you cannot name, lay upon the verdant green edge as lace upon a
stretch of velvet.  You cannot help but feel that you should stop and 
rest here.  Of course, the gems lying in the river could be holding your
attention as well.");

set_smell("default", "%^CYAN%^The sweet heady aroma of flowers fills your
senses with peace and contentment.");
set_listen("default", "%^CYAN%^The babbling stream soothes your weary brow
and sings to you of kings and paupers.");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room35",
"south" : "/d/khalian/stresa/cicatrice/room76",
"east" : "/d/khalian/stresa/cicatrice/room55",
"west" : "/d/khalian/stresa/cicatrice/room53"
]));

set_items
(([
"desert" : "A desolate and sparsely occupied or unoccupied area.",
"gems" : "Chunks of gold, emeralds, and deep red rubies.. an emporers 
ransom, lies here, just for the taking.",
"plants" : "Heady scents flow upwards from these delicate bouquets of 
summer.",
"river" : "The river is long, not too wide and very cold, the water comes
down from the mountains and still retains its ice cold refreshment."
]));

}
