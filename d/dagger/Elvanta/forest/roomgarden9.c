#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^You have come upon a rose garden full of tea roses and old world roses.  Amongst them you will find %^BOLD%^WHITE%^Sea Foam%^RESET%^, %^RED%^Elmshorn%^RESET%^, %^YELLOW%^Golden Wings%^RESET%^, %^BOLD%^WHITE%^Maidens Blush%^RESET%^, %^BOLD%^RED%^Paradise%^RESET%^, %^ORANGE%^Fragrant Cloud%^RESET%^, and %^BOLD%^YELLOW%^Brandy.%^RESET%^");
set_smell("default", "%^BOLD%^CYAN%^Your senses are reeling with the heavenly odours of the many roses.%^RESET%^");
set_listen("default", "You hear bees buzzing and insects humming");
set_exits (([
"west" : "/d/dagger/Elvanta/forest/roomgarden10",
"south" : "/d/dagger/Elvanta/forest/roomgarden8"
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
if(!present("thorn"));
new("/d/dagger/Elvanta/forest/mon/thorn")->move(this_object());
if(!present("ironroot treefolk"))
new("/d/dagger/Elvanta/forest/mon/ironroot")->move(this_object());
if(!present("bloodrose"))
new("/realms/pegasus/mon/bloodrose")->move(TO);
if(!present("bee"))
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
new("/d/dagger/Elvanta/forest/mon/bee")->move(this_object());
}
