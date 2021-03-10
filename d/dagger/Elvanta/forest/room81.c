#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The light is gray and weak, diffused by the mist, reflected by the dampness, and scattered so that is seems to come from everywhere.  There is nothing to take direction from, not even the lichen and moss.%^RESET%^");
set ("night long", "%^CYAN%^Ahead, the gloom tightens into pockets of deep shadow that has the look of burrows.  Mist coils out and winds through the tree limbs and vines like snakes.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nDamp earth and the musty odour of wet leaves prevails.");
set_listen ("default", "Growls sound, disembodied and directionless, low and threatening as they rise and fall away again.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/room80",
"east" : "/d/dagger/Elvanta/forest/room82"
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
if(!present("jackalwere"))
new("/d/dagger/Elvanta/forest/mon/jackalwere")->move(this_object());
}
