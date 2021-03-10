#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("An elven home, bath");
set_long ("%^BOLD%^BLUE%^This the the bathing room.  Something you do not see often in a home in the city of Elvanta.  There is a large copper <tub>, <towels>, and <soap>, just waiting to be enjoyed.  Several blown glass <containers> hold oils and scents.  Several tall <candles> sit around the small room, obviously waiting to shed romantic light upon the owner.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe scent from many different containers mix to make an erotic essence.");
set_listen ("default", "You hear soft music being played upon a wooden flute.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/roomH4e",
"east" : "/d/dagger/Elvanta/forest/roomH4j"
]) );
set_items(([
"tub" : "This copper tub could hold three to four people comfortably, the only problem would be the source of water.  However, the simple enjoyment of a warm, bubbly bath carressing your body, would be worth the labour.",
"towels" : "Rich, thick towels wait to dry the lucky elf off, who has been invited to share the bath.",
"soap" : "Several bars of hand made soap, apple scented, jasmine scented and sandlewood scented lay in waiting for the owner to scrub.",
"containers" : "Several containers mostly cobalt blue in colour hold many different oils and scents.",
"candles" : "The candles stand four feet high and eight inches around.  They would lend a romantic and exotic light for the owner, and any guest."
]) );
}
void reset(){
::reset();
if(!present("janice"))
new("/d/dagger/Elvanta/forest/mon/janice")->move(TO);
}
