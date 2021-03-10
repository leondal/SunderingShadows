#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, the balconey");
set_long ("%^GREEN%^This is the balconey, and here you find the source of the music.  A fair young elven maiden, of golden hair, pale white limbs and graceful fingers sits upon a <stool>, playing upon a wooden pan <flute>.  She seems totally engrossed upon what she is playing, her hair blowing gently in the breeze, her fingers flying over the flute, and her face radiant, yet seemingly far away, in another time and place.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nPine needles, and earthy scents fill the air.");
set_listen ("default", "Music, haunting, soulful, dreamlike, evokes a past in you, pulling a memory from the vaults of history.");
set_exits( ([
"east" : "/d/dagger/Elvanta/forest/roomH4c"
]) );
set_items(([
"stool" : "This is a simple three legged stool, standing perhaps three feet high, no decoration is upon it, only the lovely elf.",
"flute" : "This is an old and cherieshed flute.  Made of wood, hollowed with care, the sound from this flute, fills the day and night with visions of peace and contentment and perhaps a little sorrow."
]) );
}
void reset(){
::reset();
if(!present("singer"))
new("/d/dagger/Elvanta/forest/mon/singer")->move(this_object());
}
