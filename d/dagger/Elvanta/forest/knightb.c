#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The Knightly Inn");
set_long("%^ORANGE%^This room is a little quieter than the other commons room. More separate tables and chairs are set here for dining purposes.  The light is still dim and the various types of peoples adds a certain charm to the place.  Dinners are served here as well as ales, wines and spirits.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of food mingles with smoke and stale ale.");
set_listen ("default", "While it is a bit quieter, laughter, sone and raucous voices still rings out.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/knightd",
"east" : "/d/dagger/Elvanta/forest/room62"
]));
set_items
(([
"tables" : "Over twenty tables fill this room, each is polished to a gleam each day, but still look old, due to spilled wine, beer, and food.  Pipe burns cover each table as well, giving the tables character.",
"counter" : "The counter is thirty feet long and wiped constantly by the owner.  Large platters of food and drink rest upon it.  Several stains made by elf and age cover the counter as well.  It rises from the floor to stand about four and a half feet, and no carpentry marks mar it.",
"chairs" : "Comfortable chairs made of redwood, covered in blue hide crowd the tables.  They look inviting and welcome after your trek.",
"log-fire" : "A fireplace built ten feet long, five feet high and four feet deep holds logs the size of a man, and burns brightly",
"lamps" : "Crude iron lamps hang from the beams.  They are filled with candles burning dimly.",
"beam" : "The beams in this Inn are huge and appear to have been cut from very old trees.",
"benches" : "The benches are well made and solid, but worn from years of feet, rumps, burns and gouges."
]));
}
void reset(){
::reset();
if(!present("elf"))
new("/d/dagger/Elvanta/forest/mon/elf")->move(this_object());
if(!present("dwarf"))
new("/d/dagger/Elvanta/forest/mon/dwarf")->move(this_object());
}
