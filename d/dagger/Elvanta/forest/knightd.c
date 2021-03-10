#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The Knightly Inn, a Parlour");
set_long ("%^ORANGE%^This is a small and cozy room.  There is a bright fire burning on the <hearth> and in front of it some low and comfortable <chairs>.  There is a round <table> already spread with a white <cloth> and on it is a large hand <bell>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nOdours of food and burning cherry wood fill your senses.");
set_listen ("default", "The rumble of noise from the common rooms reaches your ears but is not disturbing.");
set_exits (([
"south" : "/d/dagger/Elvanta/forest/knightb",
"east" : "/d/dagger/Elvanta/forest/knightk"
]));
set_items
(([
"hearth" : "The hearth made of grey stone, filled with a bright and cheerful fire welcomes you.",
"chairs" : "Low and comfortable chairs face the hearth as if asking you to share the warmth.",
"table" : "The table is set and waiting for your food and drink to fill it.",
"cloth" : "The white cloth is heavey linen with embroidery of a knight in arms upon it.",
"bell" : "The large hand bell waits to be used to summon the Innkeeper, for whatever your needs may be."
]));
}
