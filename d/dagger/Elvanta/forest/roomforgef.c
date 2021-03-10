#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Inside the Elvanta forge works-Stables");
set_long ("%^GREEN%^This is where the animals wait to be shod and armoured.  You recognize horses, unicorns and the occasional dragon awaiting fittings.  There are some beasts you do no recognize and further inspection could prove harmful to you health.  Food, water and sweet hay line the stables.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell animal sweat and manure.  Thoroughly unpleasant.");
set_listen ("default", "The banging and tinking of metals continues, now joined by animal grunts, whistles and groans.");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomforgea"
]) );
set_items
(([
"swords" : "Gleaming metal swords are forged here to the exact measurements required by the customer.",
"knives" : "Knives of every shape, style and size are custom designed and crafted.  From three inches to a ten inch thrusting blade, no request is turned away.",
"shields" : "Shields of glowing iron, mostly oval in shape are created here.  You do see other shapes, circular, diamond, triangular, each a craftsmans art.",
"armor" : "Chain mail shirts are prevelant, but shin guards, wrist guards and helms are made by experts and fitted to the individual owner."
]));
}
void reset(){
::reset();
if(!present("centaur"))
new("/d/deku/monster/centaur")->move(this_object());
if(!present("dragon"))
new("/d/deku/monster/dragon")->move(this_object());
if(!present("kobold"))
new("/d/deku/monster/kobold")->move(this_object());
if(!present("unicorn"))
new("/d/tharis/monsters/unicorn")->move(this_object());
}
