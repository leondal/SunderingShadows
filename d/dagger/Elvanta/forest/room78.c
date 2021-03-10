#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The rustling of leaves fills your ears, and there is a snapping of branches.  Birds dart through the cavernous forest, spurts of colour and movement that are gone in a blink of an eye.  The forest shimmers damp and frozen about you, a still life, in which only you move.%^RESET%^");
set ("night long", "%^CYAN%^The rustling of leaves fills your ears, and there is a snapping of branches.  Birds dart through the cavernous forest, spurts of colour and movement that are gone in a blink of an eye.  The forest shimmers damp and frozen about you, a still life, in which only you move.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "You hear sounds more haunting than comforting, bits and pieces of life that sprinkles the gloom with hints of what lies hidden.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room77",
"east" : "/d/dagger/Elvanta/forest/room79"
]));
set_items
(([
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"pathway" : "The pathway continues in a southeast direction, but is not as clear as it once was, as mist starts to rise from out of nowhere."
]));
}
void reset(){
::reset();
if(!present("ironroot treefolk"))
new("/d/dagger/Elvanta/forest/mon/ironroot")->move(TO);
}
