#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property ("indoors", 1);
set_short ("The Wrath of Grapes Inn, Private Rooms");
set_long ("%^CYAN%^These are the private dining areas.  There are several, but they are all the same.  Swinging <doors> separate each little parlour.  <Goblets>, <decanters> and <stoneware> await to be used by a party of one or twenty.%^RESET%^");
set_smell ("default", "The smell of roasted meat, potatoes, wines and pastry fill the air.");
set_listen ("default", "You hear singing, music and laughter from the commons room.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/Inn1"
]));
set_items
(([
"tables" : "Twelve foot slabs of highly polished redwood resides here with carved bases in the shapes of lions.",
"doors" : "Carved doors of panelled wood swing on great metal hinges, you think, however, that a little oil wouldn't hurt on that one door. YEOW!",
"chairs" : "The chairs are twelve to a table and are carved with designs of pheasants and partridge on the chairback.",
"candles" : "Candles made of beeswax and scented with ginger are set every two feet along the tables.",
"stoneware" : "The dishes and bowls are shaped from grey-green granite.",
"goblets" : "Goblets of silver are placed at each setting.  Each goblet is etched with a cluster of hanging grapes.",
"decanters" : "A hanging cluster of grapes adorns the decanters, matching the silver goblets."
]));
}
void reset(){
::reset();
if(!present("archer"))
new("/d/dagger/Elvanta/forest/mon/archer")->move(TO);
if(!present("elf"))
new("/d/dagger/Elvanta/forest/mon/elf")->move(TO);
if(!present("singer"))
new("/d/dagger/Elvanta/forest/mon/singer")->move(TO);
}
