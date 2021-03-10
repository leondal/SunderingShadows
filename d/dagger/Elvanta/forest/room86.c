#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The forest has become a vault of green walls that form countless chambers leading one into another, of corridors that twist and wind about in a maze that threatens to suffocate.  As you step down several stairs you find branches intertwined overhead to form a ceiling that shuts out the light.%^RESET%^");
set ("night long", "%^CYAN%^The forest has become a vault of green walls that form countless chambers leading one into another, of corridors that twist and wind about in a maze that threatens to suffocate.  As you step down several stairs you find branches intertwined overhead to form a ceiling that shuts out any light from the moon or stars.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "Growls sound, disembodied and directionless, low and threatening as they rise and fall away again.");
set_exits (([
"up" : "/d/dagger/Elvanta/forest/room85",
"down" : "/d/dagger/Elvanta/forest/room87"
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
if(!present("wight"))
new("/d/dagger/Elvanta/forest/mon/wight")->move(TO);
if(!present("roc"))
new("/d/dagger/Elvanta/forest/mon/roc")->move(TO);
}
