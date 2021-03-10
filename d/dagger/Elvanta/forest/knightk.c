#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The Knightly Inn, the Kitchen");
 set_long ("%^ORANGE%^A small oblong room filled with overheated elves and long <stoves>.  Gleaming <pots> and <pans> line the walls while <foodstuffs> lay upon ten foot <tables> waiting to be scrubbed, pared, diced, mashed and cooked.  The air is filled with smoke and curses.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell burnt offerings and stale ale.");
set_listen ("default", "You hear sizzling, splashig, chopping and cursing.");
set_exits (([
"south" : "/d/dagger/Elvanta/forest/room62",
"west" : "/d/dagger/Elvanta/forest/knightd",
"east" : "/d/dagger/Elvanta/forest/knightc",
"up" : "/d/dagger/Elvanta/forest/knighti"
]));
set_items
(([
"stoves" : "Long iron monstosities, belching out smoke and ash are what passes here for stoves.",
"pots" : "Bright copper pots line the walls.  Obviously a decoration only as the cooking pots are blackened with continual use.",
"pans" : "Like the pots, the pans hang gleaming from great hooks.  Unlike the rest of the kitchen these look cared for.",
"foodstuffs" : "All manner of foodstuffs lay upon the tables, root vegetables, mushrooms, salad makings and an unidentifiable meat course, wait to be made into dinners.",
"tables" : "The tables are white from years of scrubbing and misuse.  Gouges, burns and cuts confirm the age of these massive forms of wood."
]));
}
