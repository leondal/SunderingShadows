#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^This area holds mostly green moss covering the ground like a carpet.  A few animals, deer, rabbit and raccoon are seen passing by, no fear shown.  It seems to be a peaceful place, for the eyes and the soul.%^RESET%^");
set_smell ("default", "%^CYAN%^The odour of warm earth and gentle breezes reaches your senses.");
set_listen ("default", "You hear the snuffling of a deer grazing, birds carolling overhead, and small animals scurrying to and fro.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roomgarden9",
"south" : "/d/dagger/Elvanta/forest/roomgarden7"
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
if(!present("deer"));
new("/d/dagger/Elvanta/forest/mon/deer")->move(this_object());
if(!present("rabbit"));
new("/d/dagger/Elvanta/forest/mon/rabbit")->move(this_object());
if(!present("raccoon"));
new("/d/dagger/Elvanta/forest/mon/raccoon")->move(this_object());
}
