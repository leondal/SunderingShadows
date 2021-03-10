#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set("day long", "%^ORANGE%^You continue to travel within the forest, noticing small creatures, running up and down the redwoods.  Pine needles line the floor of the forest, making your travels soft and fragrant.%^RESET%^");
set("night long", "%^CYAN%^You continue to travel within the forest, noticing creatures of the night, as they scurry past you on the floor of the forest, or overhead upon intertwining branches.%^RESET%^");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/room4",
"south" : "/d/dagger/Elvanta/forest/room2"
]));
set_items
(([
"creatures" : "Small forest mice, centipedes, rabbits, and other animals cross your path.",
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset (){
::reset();
if(!present("rat"))
new("/d/shadow/mon/rat")->move(this_object());
}
