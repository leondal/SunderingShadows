#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You slip through the <trees>, past the <stairs> to find the trail continuing in a circle once more.  As you peer into the darkness of the forest you see some light ahead, flickering.%^RESET%^");
set ("night long", "%^CYAN%^You slip through the <trees>, past the <stairs> to find the trail continuing in a circle once more.  As you peer into the darkness of the forest you see some light ahead, flickering.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "Sounds of broken twigs, whispers of fear, growls of inhumanity still fill your ears.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room84",
"northeast" : "/d/dagger/Elvanta/forest/room92"
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
if(!present("dwarf"))
new("/d/dagger/Elvanta/forest/mon/dwarf")->move(TO);
if(!present("elf"))
new("/d/dagger/Elvanta/forest/mon/elf")->move(TO);
if(!present("ghost"))
new("/d/dagger/Elvanta/forest/mon/ghost")->move(TO);
if(!present("jackalwere"))
new("/d/dagger/Elvanta/forest/mon/jackalwere")->move(TO);
}
