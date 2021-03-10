#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long ("%^GREEN%^Gentle slopes of green moss reach several fruit trees planted here by a master hand.  Apples, peaches, lemons, apricots, plums and pomegarante trees are just a few of the many fruits grown and tended here.%^RESET%^");
set_smell ("default", "%^CYAN%^Odours from several fallen fruits fill the air with a sweet delicious aroma.");
set_listen ("default", "Birds singing, insects humming and the grumbling of an old gardener can be heard.");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/roomgarden4",
"north" : "/d/dagger/Elvanta/forest/roomgarden6"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"globes" : "Great cirles of light pour from these globes, lighting the way for you and other travellers.  They hang from intricately forged silver chains, which give off a glow of their own.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset() {
::reset();
if(!present("gardener"))
new("/d/dagger/Elvanta/forest/mon/gardener")->move(this_object());
}
