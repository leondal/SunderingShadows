#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway, through danger");
set ("day long", "%^ORANGE%^Shadows waft all about as the mist shifts and reforms, cloaking and lifting clear from islands of trees.  No monsters appear, but you suspect they are there, watching and waiting, the spectres that whisper from the mist.%^RESET%^");
set ("night long", "%^CYAN%^Shadows waft all about as the mist shifts and reforms, cloaking and lifting clear from islands of trees.  No monsters appear, but you suspect they are there, watching and waiting, the spectres that whisper from the mist.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of fear encompasses you.");
set_listen ("default", "Insects buzz invisibly and things cry out from the mist, but nothing moves.  Nothing seems alive.");
set_exits (([
"northwest" : "/d/dagger/Elvanta/forest/room99",
"south" : "/d/dagger/Elvanta/forest/room97"
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
