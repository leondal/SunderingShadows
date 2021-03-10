#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^What lives here are things best left to blackness, night and shadow; bats, leathered and reeking of disease, snakes and scaled hunters that nest and feed on vermin that lives within, cat-things, sleek and quick as they stalk the treeways on silent pads.%^RESET%^");
set ("night long", "%^CYAN%^What lives here are things best left to blackness, night and shadow; bats, leathered and reeking of disease, snakes and scaled hunters that nest and feed on the vermin that live within, cat-things, sleek and quick as they stalk the treeways on silent pads.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "Growls sound, disembodied and directionless, low and threatening as they rise and fall away again.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room81",
"east" : "/d/dagger/Elvanta/forest/room83"
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
