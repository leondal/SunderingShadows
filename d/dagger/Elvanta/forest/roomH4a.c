#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, kitchen");
set_long ("%^GREEN%^It is obvious from the size and state of this kitchen that the owner of this home does not count epicury as an art form.  There are a few <pots> and <pans> with leftover food hardened into unrecognizable lumps.  Some <cutlery> which may never be the same lays upon a small <table>.  A cooking <firepit> looks full of soot, half burned logs and coal.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe odour of old food and stale ale fills this room.");
set_listen ("default", "You can still hear the sound of a wooden flute, haunting and soulful.");
set_exits( ([
"up" : "/d/dagger/Elvanta/forest/roomH4f",
"south" : "/d/dagger/Elvanta/forest/roomH4",
"west" : "/d/dagger/Elvanta/forest/roomH4b"
]) );
set_items(([
"pots" : "These pots were once bright copper and gleamed.  Now encrusted with several days food they look disgusting.",
"pans" : "The pans are in the same shape as the pots except for one.  It hangs upon the wall, shining, gleaming, untouched.",
"cutlery" : "Cutlery of several sizes and patterns is strewn upon the table.  You wouldn't want to use any of it.",
"table" : "The table has seen better days.  Burns, cuts, old food and gouges show the neglect.",
"firepit" : "A firepit placed within the left wall is filled with soot, half burned logs, and spilled food.  Obviously not used often nor well."
]) );
}
