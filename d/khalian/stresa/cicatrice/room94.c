
//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^White skies, white sun, gold sand.  Nothing else
appears before you.  The dunes rise like golden mountains surrounding you.
Small tracks appear in the sand before being swept away by the wind.  
Serpentine s's all etched in the dunes, left by travelling snakes, give
the only clue to life.  There is life here, in the desert, but where
and what it is, is unknown and hidden.  You would be well advised to 
tread carefully.");

set_smell("default", "%^CYAN%^Only the smell of hot air trying to smother
the air from your lungs reaches you.");
set_listen("default", "%^CYAN%^Rustling sounds of some unknown creature
manages to make itself heard over the wind.");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room79",
"south" : "/d/khalian/stresa/cicatrice/room105",
"southeast" : "/d/khalian/stresa/cicatrice/room106"
]));

set_items
(([
"tracks" : "Tracks of some small animal, lizard or snake appear in the 
sand.  What it is, you cannot tell, however, walking carefully at this
point might be a good idea.",
"snakes" : "Long, slithery, deadly, thats about all there is to a snake, 
and the idea of being very careful where one sits or steps."
]));


}
