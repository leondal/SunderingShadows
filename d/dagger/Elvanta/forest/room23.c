#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^You continue to travel in a circle towards the middle of the <forest>.  Not much catches your attention, the <trees> are all around you, and you can see <squirrels>, <birds> and other small <animals>.%^RESET%^");
set ("night long", "%^CYAN%^You continue to travel in a circle toweards the middle of the <forest>.  Not much catches your attention.  Most of the noises are from night animals, such as <owls> and the like.  You continue to travel beneath the light of the hanging <globes>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou can smell pine and the scent of the different types of fauna in the forest.");
set_listen ("default", "You hear an owl hooting in the trees, and the sound of night animals scurrying in the underbrush.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/room24",
"southwest" : "/d/dagger/Elvanta/forest/room22"
]));
set_items
(([
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"owls" : "Very large owls live here in this forest.  They stand about four feet tall, and have large talons and a wicked beak.  They hoot from thier perches, and it would be wise to give them a wide berth.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"squirrels" : "These little creatures are of all colours, brown, black and grey.  Their chittering reminds you of small children laughing.",
"birds" : "Birds of many different hues live in this forest, protected it seems, by the keepers.",
"animals" : "As you walk through this city you notice how many small animals make their homes here as well, mice, crickets, rabbits, and other four legged and six legged creatures.  They seem not to be alarmed by your passing.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
void reset(){
::reset();
if(!present("cockatrice"))
new("/d/dagger/Elvanta/forest/mon/cockatrice")->move(this_object());
}
