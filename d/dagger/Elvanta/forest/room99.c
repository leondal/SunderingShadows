#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway, through danger");
set ("day long", "%^ORANGE%^Cloaked head to foot in robes the colour of damp ashes, it is almost invisible, its face carefully concealed within the shadow of a broad hood.  It is a guardian for this part of the forest. Evil?, perhaps, perhaps not.%^RESET%^");
set ("night long", "%^CYAN%^Cloaked head to foot in robes the colour of damp ashes, it is almost invisible, its face carefully concealed within the shadow of a broad hood.  It is a guardian for this part of the forest.  Evil?, perhpaps, perhaps not.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nRotting vegetation, the bitter metallic smell of old blood, all of this creates an odour of danger.");
set_listen ("default", "Growls sound, disembodied and directionless, low and threatening as they rise and fall away again.");
set_exits (([
"northwest" : "/d/dagger/Elvanta/forest/room100",
"southeast" : "/d/dagger/Elvanta/forest/room98"
]));
set_items
(([
"trail" : "A trail of sorts, you try to follow the heavy limbs, slipping on wet and slimy boughs.",
"pathway" : "Like the trail, your pathway is difficult to travel, and you know not where it may lead you.",
"stairs" : "Hundreds of steps await you, roughly hewn, badly worn, and hidden beneath, beside and above them, something may lay in wait.... for you... who knows......",
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
]));
}
void reset(){
::reset();
if(!present("shadow monk"))
new("/d/dagger/drow/mon/smonk")->move(TO);
}
