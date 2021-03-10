#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^There are strange animals that show themselves briefly and disappear again, hunters all, scaled and spiked, clawed and sharp-toothed.  No monsters appear, but you suspect they are there, watching and waiting, the spectres that whisper from the mist.%^RESET%^");
set ("night long", "%^CYAN%^There are strange animals that show themselves briefly and disappear again, hunters all, scaled and spiked, clawed and sharp-toothed.  No monsters appear, but you suspect they are there, watching and waiting, the spectres that whisper from the mist.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "You hear sounds more haunting than comforting, bits and pieces of life that sprinkles the gloom with hints of what lies hidden.");
set_exits (([
"northwest" : "/d/dagger/Elvanta/forest/room75",
"southeast" : "/d/dagger/Elvanta/forest/room77"
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
if(!present("groaning spirit"))
new("/d/dagger/Elvanta/forest/mon/groaning_spirit")->move(this_object());
if(!present("golem"))
new("/realms/pegasus/mon/fgolem")->move(TO);
}
