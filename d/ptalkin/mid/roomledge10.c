//rooms by the house of Svaha

#include <std.h>
#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 1);
set_short("%^BOLD%^GREEN%^A cavern");
set_long("%^BOLD%^GREEN%^You have entered the realm of Bazzburr.
This large red dragon, when here, sits amid all of his treasures.
Gold, his favourite, plus rubies, emeralds, sapphires and diamonds.
Other items draw your attention, crosses of exquisitely carved gold,
knives of the hardest metals, with priceless gems inlain upon 
glittering pommels.  Cups, platters, mugs, and other items,
made of gold and silver.  You wonder how you could get your hands
on this treasure, without losing your life in the process.");
set_smell("default", "A new odour takes over, something of a cross between rancid meat and cinnamon");
set_listen("default", "%^CYAN%^There comes a sound of water endlessly dripping somewhere in the distance.");
set_exits (([
"east" : "/d/ptalkin/mid/roomledge9"
]));

if(!present("red_dragon"))
new("/d/ptalkin/mon/red_dragon")->move(this_object());
new("/d/ptalkin/items/ruby")->move(TO);
new("/d/ptalkin/items/emerald")->move(TO);
new("/d/ptalkin/items/sapphire")->move(TO);
}
