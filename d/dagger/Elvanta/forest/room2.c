#include <std.h>
inherit ROOM;

void init(){
	::init();
	add_action("read_func", "read");
}
void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set("day long", "%^ORANGE%^As you travel along the pathway through The Deep Shadow forest, you notice the coolness, as little light reaches down past the huge redwoods.  You feel a couple of pine cones drop upon your head, and laughter following.  You can see a finely painted sign to your left.  You should probably <read> it before going ahead.");
set("night long", "%^CYAN%^As you travel upon the pathway into the Deep Shadow Forest, you hear night sounds and see flickers of movement.  However, you cannot make out any forms, as the darkness is all encompassing.  There is a small finely written sign to your left and perhaps it should be <read> before going any further into this area.");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/room3",
"south" : "/d/dagger/Elvanta/forest/room1"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset(){
::reset();
if(!present("sparrow"))
new("/d/dagger/Elvanta/forest/mon/sparrow")->move(TO);
if(!present("elfchild"))
new("/d/dagger/Elvanta/forest/mon/genelfchild")->move(TO);
}
int read_func(string str){
	write("%^RED%^Dear Travellers, you are entering an area where angels fear to tread.  Be advised that some of your god-given talents may not work here, and that injury and death are commonplace.");
	return 1;
}
