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
set_short ("A pathway");
set_long("%^ORANGE%^You enter a stretch of forest thick with old-growth trees.  Vines and mosses cling to the barked surfaces in brilliant green strips and patches.");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "Quiet surrounds you, sound is muffled by leaves and a carpeting of pine needles.");
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/roompath5",
"southwest" : "/d/dagger/Elvanta/forest/roompath3"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
int read_func(string str){
	write("%^RED%^Dear Travellers, you are entering an area where angels fear to tread.  Be advised that some of your god-given talents may not work here, and that injury and death are commonplace.");
	return 1;
}
