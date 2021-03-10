#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long ("%^GREEN%^A few plants grow here, sloping to meet more of a wild section of longweed, grains, and wild roses.  A bit of the wilds set within a peaceful encounter, to remind you that all is not always what it seems.  The contrast also helps you to appreciate the symmetry of the gardens and the plants within.%^RESET%^");
set_smell ("default", "%^CYAN%^The smell of grasses, the faint miasma of the wild roses and the bold odour of the long weed mix to form a sneezing mixture.");
set_listen ("default", "The growl of a black bear, the screech of an eagle and the creak of an old tree are the sounds met here.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roomgarden7",
"south" : "/d/dagger/Elvanta/forest/roomgarden5"
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
if(!present("blackbear"))
new("/d/dagger/Elvanta/forest/mon/blackbear")->move(this_object());
if(!present("eagle"))
new("/d/dagger/Elvanta/forest/mon/eagle")->move(this_object());
}
