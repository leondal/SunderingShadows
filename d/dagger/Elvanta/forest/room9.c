#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set("day long", "%^ORANGE%^It is dark in here, but you can make out the shape of stairs leading up.%^RESET%^");
set("night long", "%^CYAN%^It is as dark as a moonless night in here.  As you take a step forward you stub your toe upon a stairway.%^RESET%^");
set_smell("default", "%^MAGENTA%^\nYou can smell the pine needles of the forest, and the woody scent of the tree in which you are standing.");
set_listen("default", "You can still hear birds, but the sounds are muffled.");
set_exits (([
"up" : "/d/dagger/Elvanta/forest/room10",
"out" : "/d/dagger/Elvanta/forest/room8"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"stairways" : "Intricate stairways rise from the middle of some of the trees ahead it seems.  Vines of an unknown plant form the railings and supports for the stairs.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees surrounding you give you a sense of peace, however, you are worried at the fact that you cannot see where you are going.  You also seem to hear whispered voices.",
"staircase" : "The staircase appears in front of you, how is that possible? The vines holding the staircase above ground seems to be molded to the stairs.  Intricate designs of animals and flowers entwined adorn the stairs themselves.  The artwork is phenomenal.  Someone spent a lifetime carving these."
]));
}
void reset(){
::reset();
if(!present("giantbat"))
new("/d/shadow/mon/giantbat")->move(this_object());
}
