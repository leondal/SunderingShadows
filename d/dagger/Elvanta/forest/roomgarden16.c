#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^You have reached the end of the Gardens of Moibin.  The gardens completely surround the castle giving it a further advantage of an area between tree and stone to help protect the dwellers within.  You see a statue of a gnome and can either go east to enter the castle, north to return to the gardens, or south to leave the castle area.%^RESET%^");
set_smell ("default", "%^CYAN%^The odour of warm earth and gentle breezes reaches your senses.");
set_listen("default", "Birds chirping, bees droning, insects and small animals scurrying can be heard.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roomgarden15",
"south" : "/d/dagger/Elvanta/forest/roomgarden1",
"east" : "/d/dagger/Elvanta/forest/roomcastle1"
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"plaque" : "As you look at the bronze plaque set within the rock, you notice some etching on it.  You could read the plaque and satisfy your curiosity.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"globes" : "Great cirles of light pour from these globes, lighting the way for you and other travellers.  They hang from intricately forged silver chains, which give off a glow of their own.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset() {
::reset();
if(!present("hesna"))
new("/d/dagger/Elvanta/forest/mon/hesna")->move(this_object());
}
