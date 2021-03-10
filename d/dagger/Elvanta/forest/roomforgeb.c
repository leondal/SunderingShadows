#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Inside the Elvanta forge works-Ironsmiths");
set_long ("%^GREEN%^In this room the ironsmiths hold leadership.  <Swords>, <knives>, <shields> and <armour> are made to order here.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of cherry wood and coal reaches your nose.");
set_listen ("default", "The clanking of iron hitting iron and the sizzling of hot metal being placed in water thunders in your ears.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomforgee",
"east" : "/d/dagger/Elvanta/forest/roomforge"
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
if(!present("ironsmith"));
new("/d/dagger/Elvanta/forest/mon/ironsmith")->move(this_object());
}
