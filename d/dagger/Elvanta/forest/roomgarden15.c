#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^You have returned once more to the green moss area of the gardens, all that is here, however, is a large %^MAGENTA%^amethyst%^RESET%^ stone %^GREEN%^with a plaque inlaid upon it.%^RESET%^");
set_smell ("default", "%^CYAN%^The odour of warm earth and gentle breezes reaches your senses.");
set_listen("default", "Quiet fills the air here, as if in homage to the stone set in this place.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roomgarden14",
"south" : "/d/dagger/Elvanta/forest/roomgarden16"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"plaque" : "As you look at the bronze plaque set within the rock you notice some writing etched upon it",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"globes" : "Great cirles of light pour from these globes, lighting the way for you and other travellers.  They hang from intricately forged silver chains, which give off a glow of their own.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset() {
::reset();
if(!present("stone"))
new("/d/dagger/Elvanta/forest/items/objs/stone")->move(this_object());
if(!present("plaque"))
new("/d/dagger/Elvanta/forest/items/objs/plaque")->move(this_object());
}
