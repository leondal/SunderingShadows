#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The <pathway> you travel upon is surrounded by <redwoods>.  As you peer up into the trees you can make out tiny <globes> and intricate <stairways>.  You begin to wonder where exactly is the fabled city of Elvanta.%^RESET%^");
set ("night long", "%^CYAN%^The <pathway> you travel upon is surrounded by <redwoods>.  As you peer up into the trees you can make out tiny <lights> and intricate <stairways>.  You begin to wonder where the fabled city of Elvanta could actually be.%^RESET%^");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
new("/d/dagger/Elvanta/forest/mon/deer")->move(TO);
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/room8",
"southwest" : "/d/dagger/Elvanta/forest/room6"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"stairways" : "Intricate stairways rise from the middle of some of the trees ahead it seems.  Vines of an unknown plant form the railings and supports for the stairs.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so."
]));
}
void reset(){
::reset();
if(!present("deer"));
new("/d/dagger/Elvanta/forest/mon/deer")->move(TO);
}
