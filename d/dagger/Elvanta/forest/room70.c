#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The character of the woods undergoes a sudden and distinct change.  The trees turn gnarled and damp becoming monstrous sentinels for a surreal world of imaginary wraiths that slip like smoke through a mist that shrouds everything.%^RESET%^");
set ("night long", "%^CYAN%^The forest and the mist thicken and wrap around you like a cloak, everything disappearing outside a ten foot sweep.  You hear things moving all around you but see nothing.  Then abruptly a shadow detaches itself from the gloom and brings you to a halt.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of the forest returns, damp earth and pine scents.");
set_listen ("default", "You hear sounds more haunting than comforting, bits and pieces of life that sprinkles the gloom with hints of what lies hidden.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room69",
"southeast" : "/d/dagger/Elvanta/forest/room71"
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
if(!present("greenhag"))
new("/d/dagger/Elvanta/forest/mon/greenhag")->move(TO);
}
