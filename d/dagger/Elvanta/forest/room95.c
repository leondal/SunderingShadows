#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway, through danger");
set ("day long", "%^ORANGE%^Like Mistress Death she comes for you.  Tall, gray hair long and woven thick with nightshade, black robes trailing from her slender form, a whisper of silk in the the deep silence.  She is beautiful, her face delicate and finely wrought, her skin so pale that she seems almost ethereal.  There is an ageless look to her, a timelessness, as if she is a thing that has always been and will be.%^RESET%^");
set ("night long", "%^CYAN%^Like Mistress Death she comes for you.  Tall, gray hair long and woven thick with nightshade, black robes trailing from her slender form, a whisper of silk in the deep silence.  She is beautiful, her face delicate and finely wrought, her skin so pale that she seems almost ethereal.  There is an ageless look to her, a timelessness, as if she is a thing that has always been and will be.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of fear encompasses you.");
set_listen ("default", "A deep hush has filled the forest, no birds, no people, no insects, just silence, hovering, waiting.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/room96",
"south" : "/d/dagger/Elvanta/forest/room94"
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
if(!present("d'naia"))
new("/d/dagger/Elvanta/forest/mon/d'naia")->move(TO);
}
