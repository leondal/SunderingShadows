#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The <trail> narrows sharply now, and the woods close in about you.  Slipping through the dark, glistening limbs and sagging boughs heavy with rain you follow the <pathway> as it begins to slope downward.  The path ends at a long rambling flight of wooden <stairs> that wind down out of the forest.%^%^RESET%^");
set ("night long", "%^CYAN%^The <trail> narrows sharply now, and the woods close in about you.  Slipping through the dark, glistening limbs and sagging boughs heavy with rain, you follow the <pathway> as it begins to slope downward.  The path ends at a long rambling flight of wooden <stairs> that wind down out of the forest.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "Growls sound, disembodied and directionless, low and threatening as they rise and fall away again.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room83",
"east" : "/d/dagger/Elvanta/forest/room91",
"down" : "/d/dagger/Elvanta/forest/room85"
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
