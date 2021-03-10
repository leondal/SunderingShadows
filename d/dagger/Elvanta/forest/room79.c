#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^There are certain plants, bright coloured and intricately formed, that snare and trap anything that comes within reach.%^RESET%^");
set ("night long", "%^CYAN%^The darkness descends in a slow setting of gray veils, one after another, that gradually screens away the light.  The day's silence gradually gives way to a rising tide of night sounds.  A mix, rough-edged and sharp, rising out of the darker patches to echo through the gloom.  Bits and pieces of foliage begin to glow with a silver phosphorescence, and flying insects glimmer and fade as they skip across the mist.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "You hear sounds more haunting than comforting, bits and pieces of life that sprinkles the gloom with hints of what lies hidden.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room78",
"southeast" : "/d/dagger/Elvanta/forest/room80"
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
if(!present("treant"))
new("/d/tharis/monsters/treant")->move(this_object());
if(!present("bushtiger"))
new("/d/dagger/Elvanta/forest/mon/bushtiger")->move(TO);
}
