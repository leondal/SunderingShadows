#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property ("indoors", 1);
set_short ("The Wrath of Grapes Inn, Dining Room");
set_long ("%^CYAN%^This room is the dining room of the inn.  Long trestle <tables> with high backed <chairs> fill the room.  Foot long <candles> are every two feet on the table and beautiful <stoneware> is set at each place.  <Goblets> and <decanters> stand waiting to be filled.%^RESET%^");
set_smell ("default", "The smell of roasted meat, potatoes, wines and pastry fill the air.");
set_listen ("default", "You hear singing, music and laughter from the commons room.");
set_exits (([
"south" : "/d/dagger/Elvanta/forest/room38",
"east" : "/d/dagger/Elvanta/forest/Inn1"
]));
set_items
(([
"tables" : "Twelve foot slabs of highly polished redwood resides here with carved bases in the shapes of lions.",
"chairs" : "The chairs are twelve to a table and are carved with designs of pheasants and partridge on the chairback.",
"candles" : "Candles made of beeswax and scented with ginger are set every two feet along the tables.",
"stoneware" : "The dishes and bowls are shaped from grey-green granite.",
"goblets" : "Goblets of silver are placed at each setting.  Each goblet is etched with a cluster of hanging grapes.",
"decanters" : "A hanging cluster of grapes adorns the decanters, matching the silver goblets."
]));
}
