#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^You have passed through the rock gardens to find yourself in an aviary.  All types of bird life reside here, some of which you have only heard of in fairy tales.%^RESET%^");
set_smell("default", "%^CYAN%^Wet feathers, bird droppings, and leftover remains of kills offends your sense of smell somewhat.");
set_listen("default", "The raucaus call of many birds fills the air with a caliope of sound.");
set_exits (([
"south" : "/d/dagger/Elvanta/forest/roomgarden15",
"north" : "/d/dagger/Elvanta/forest/roomgarden13"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"fretwork" : "Fretwork, like delicate lace is done is beautiful swirls, curls and flowers, to create a fairy like structure.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"globes" : "Great cirles of light pour from these globes, lighting the way for you and other travellers.  They hang from intricately forged silver chains, which give off a glow of their own.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
if(!present("eagle"))
new("/d/dagger/Elvanta/forest/mon/eagle")->move(this_object());
if(!present("roc"))
new("/d/dagger/Elvanta/forest/mon/roc")->move(this_object());
if(!present("sparrow"));
new("/d/dagger/Elvanta/forest/mon/sparrow")->move(this_object());
if(!present("cockatrice"))
new("/d/dagger/Elvanta/forest/mon/cockatrice")->move(this_object());
}
