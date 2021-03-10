#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("An inn, of sorts");
set ("day long", "%^ORANGE%^Here is the tavern in which the denizens of this area gather, at rough-hewn tables and bars formed of boards set atop barrels, about glasses and tankards of ale and wine, their voices loud and rough, their laughter shrill.  They drift from one area to the next, hard-eyed men and women of all races, some dressed gaily, some ragged, bold in the glare of lamplight, or furtive as they steal through the night.%^RESET%^");
set ("night long", "%^CYAN%^Here is the tavern which serves the denizens of this area.  They gather at rough-hewn tables and bars formed of boards set atop barrels, about glass and tankards of ale and wine, their voices loud and rough, their laughter shrill.  They drift from one area to the next, hard-eyed men and women  of all races, some dressed gaily, some ragged, bold in the glare of the lamplight, or furtive as they steal through the night.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nStale ale, smoke and the odour of unwashed bodies mingles for an unpleasant aroma.");
set_listen ("default", "Sounds of laughter, yells for ale, and wine fill the room.");
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/room93",
"southwest" : "/d/dagger/Elvanta/forest/room91"
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
if(!present("courtier"))
new("/d/dagger/Elvanta/forest/mon/courtier")->move(TO);
if(!present("archer"))
new("/d/dagger/Elvanta/forest/mon/archer")->move(TO);
if(!present("guard"))
new("/d/dagger/Elvanta/forest/mon/guard")->move(TO);
}
