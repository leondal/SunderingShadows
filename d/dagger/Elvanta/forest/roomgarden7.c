#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^You have come across two statues, one carved out of bloodstone and in honour of Timot, the greatest elven archer, and one carved from amber, in honour of Guy, the greatest swordsman of all time.%^RESET%^");
set_smell ("default", "%^CYAN%^The metallic tinny taste of blood reaches the back of your throat as if you were cast back into the time of Timot and Guy.");
set_listen ("default", "You can almost hear the war cries from Timot, and the laughter of a true fighter from Guy.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roomgarden8",
"south" : "/d/dagger/Elvanta/forest/roomgarden6"
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
if(!present("timot"))
new("/d/dagger/Elvanta/forest/mon/timot")->move(this_object());
if(!present("guy"))
new("/d/dagger/Elvanta/forest/mon/guy")->move(this_object());
}
