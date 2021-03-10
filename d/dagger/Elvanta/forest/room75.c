#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^As you look upward you encounter a great web concealed overhead and set like a snare to fall on whatever passes underneath.  The strands of the webbing are as thick as your fingers, and so close to transparent that they are invisible if you are not looking for them.  As you poke at it with a stick, the stick is instantly stuck fast.%^RESET%^");
set ("night long", "%^CYAN%^As you look upward you encounter a great web concealed overhead and set like a snare to fall on whatever passes underneath.  The strands of the webbing are as thick as your fingers, and so close to transparent that they are invisible if you are not looking for them.  As you poke at it with a stick, the stick is instantly stuck fast.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "You hear sounds more haunting than comforting, bits and pieces of life that sprinkles the gloom with hints of what lies hidden.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room74",
"southeast" : "/d/dagger/Elvanta/forest/room76"
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
if(!present("ghost"))
new("/d/dagger/Elvanta/forest/mon/ghost")->move(this_object());
}
