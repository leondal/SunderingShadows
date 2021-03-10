#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Elvanta city, a home");
set_long ("%^GREEN%^You have come up wooden <stairs> to reach the second floor of the elf home.  To your right is a <bedroom>, to your left a <bedroom>, ahead of you a <study>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe odour of burnt candles and sweet lavender fills your senses.");
set_listen ("default", "You hear only the whisper of the wind through the trees.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomH3f",
"east" : "/d/dagger/Elvanta/forest/roomH3d",
"west" : "/d/dagger/Elvanta/forest/roomH3e",
"down" : "/d/dagger/Elvanta/forest/roomH3"
]) );
set_items(([
"stairs" : "The stairs you walk upon travel in a spiral upwards and downwards.  They are made of wood and years of travel upon them has created a smooth finish and a dip in the middle",
"bedroom" : "These bedrooms have porthole windows to let in the air and sunshine, and drapes of pale green to shut out the cold wind.  A bed, side table, and clothes press are also in the room.",
"study" : "This may need further examination.  Books, papers, and scrolls lay in heaps and untidy piles all over this room.  A small fireplace, a large chair and a long table make up this room."
]) );
}
