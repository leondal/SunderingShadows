#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, the music room");
set_long ("%^GREEN%^It is only too obvious that the sould of the elf who lives here resides in this room. The furniture is rich old woods, the covering materials warm brocades, and the atmosphere one of peace and contentment.  A music <stand> is in the left corner of the room, a <flute>, <horn> and <music> are carefully positioned upon a long narrow <table>.  A tall <stool> stands in front of the music stand, as though waiting for the owner to commence.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe odour of sandlewood and cedar mix within this room.");
set_listen ("default", "Music, haunting, soulful, dreamlike, evokes a past in you, pulling a memory from the vaults of history.");
set_exits( ([
"northeast" : "/d/dagger/Elvanta/forest/roomH4e"
]) );
set_items(([
"stand" : "The music stand is made of rich oak and stands upon four carved legs.  The table portion is fretwork of doves, vines, and flowers.  Metal edges shimmer as the sun catches the stand.",
"flute" : "This is an old and cherished flute.  Made of wood, several tubes are placed together to form this flute.  The sound from this flute, fills the day and night with visions of peace, contentment and perhaps a little sorrow.",
"horn" : "This french horn is made of brass, and gleams.  Many years of polishing and care have left it with a hue of its own.",
"music" : "Sheets of yellowed music rest upon the stand, the few notes you do recognize start you humming a very old and well loved air.",
"table" : "The table is old, well worn and well looked after.  It gleams in the sunlight or moonlight and gives of an air of permanence.",
"stool" : "This stool stands four feet high, its carved legs remind you of trees, vines, and flowers."
]) );
}
