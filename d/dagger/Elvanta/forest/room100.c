#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway");
set ("day long", "%^ORANGE%^Finally, you have left the dark and dismal portion of the <forest>, now you can see further ahead along the <pathway>.  The <trees> have returned to their former state of loveliness and shelter.  Ahead of you several <buildings> start to emerge.%^RESET%^");
set ("night long", "%^CYAN%^Finally, you have left the dark and dismal portion of the <forest>, now you can see further ahead along the <pathway>.  The <trees> have returned to their former state of loveliness and shelter.  Ahead of you several <buildings> start to emerge.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nFresh pine, damp air, the scent of flowers fills the air.");
set_listen ("default", "Twitters, squeaks, and laughter emerges from the forest.");
set_exits (([
"northwest" : "/d/dagger/Elvanta/forest/room101",
"southeast" : "/d/dagger/Elvanta/forest/room99"
]));
set_items
(([
"pathway" : "The pathway leads never ending ahead of you, to the northwest, following a plan laid out eons ago.",
"buildings" : "Many buildings appear ahead of you, peeking out from tree trunks, limbs and branches.",
"trail" : "A trail of sorts, you try to follow the heavy limbs, slipping on wet and slimy boughs.",
"stairs" : "Hundreds of steps await you, roughly hewn, badly worn, and hidden beneath, beside and above them, something may lay in wait.... for you... who knows......",
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
]));
}
void reset(){
::reset();
if(!present("elf"))
new("/d/dagger/Elvanta/forest/mon/elf")->move(TO);
if(!present("dwarf"))
new("/d/dagger/Elvanta/forest/mon/dwarf")->move(TO);
if(!present("archer"))
new("/d/dagger/Elvanta/forest/mon/archer")->move(TO);
if(!present("elfchild"))
new("/d/dagger/Elvanta/forest/mon/elfchild")->move(TO);
}
