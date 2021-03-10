#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Inside the Elvanta forge works");
set_long ("%^GREEN%^This room is the main area of the forgeworks.  A large firepit sits in the middle of the room with several anvils set all around it.  A large <bellows> is attached to the firepit and is being attended to by a young <elf>.  Piles of <metal> lie all around, and partly finished <swords>, <knives>, and <shoes> are scattered everywhere.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of heated metal is even stronger in this room, you wonder what the odour is doing to your sense of smell.");
set_listen ("default", "The sounds of metals being banged into different forms is overwhelming.");
set_exits( ([
"south" : "/d/dagger/Elvanta/forest/roomforge",
"north" : "/d/dagger/Elvanta/forest/roomforgef",
"west" : "/d/dagger/Elvanta/forest/roomforgee",
"east" : "/d/dagger/Elvanta/forest/roomforged"
]) );
set_items
(([
"bellows" : "This bellows is the size of a small elephant on its own, it is used to heat the fire in the large firepit.",
"elf" : "This poor young fellow is an apprentice to the smith.  He is muchly overworked and sweat mingles with the iron filings upon his face and clothes.",
"metal" : "Mostly iron seems to be the metal worked here, but other types in colours of gold, silver, and blue lay around in piles.",
"swords" : "Partly finished swords lay waiting to be picked up and finished.  Most of them seem to be ready to be fired for the final time.",
"knives" : "Knives of every type and description seem to be made here.  Blades with curved edges, serpentine shapes and saw tooth edges abound.",
"shoes" : "Most of the shoes appear to be made for horses, but there are some strange shaped shoes as well, you wonder what they would fit."
]));
}
void reset(){
::reset();
if(!present("genelfchild"))
new("/d/dagger/Elvanta/forest/mon/genelfchild")->move(this_object());
if(!present("dwarf"))
new("/d/dagger/Elvanta/forest/mon/dwarf")->move(this_object());
}
