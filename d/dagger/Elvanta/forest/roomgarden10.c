#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^You continue to walk through beautiful rose gardens, this time, the roses are all tea roses, small and delicate, in rainbow hues.  You find %^BOLD%^WHITE%^Starglo%^RESET%^, %^BOLD%^RED%^Loveglo%^RESET%^, %^BOLD%^ORANGE%^Fire Princess%^RESET%^, %^RED%^Starina%^RESET%^, %^BOLD%^RED%^Galaxy%^RESET%^, %^BLUE%^Moonshadow%^RESET%^, and %^MAGENTA%^Morning Dew%^RESET%^.");
set_smell("default", "%^BOLD%^CYAN%^Your senses are reeling with the heavenly odours of the many roses.%^RESET%^");
set_listen("default", "You hear bees buzzing and insects humming");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomgarden9",
"west" : "/d/dagger/Elvanta/forest/roomgarden11"
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
if(!present("redbloodrose"))
new("/realms/pegasus/mon/redbloodrose")->move(TO);
if(!present("ironroot treefolk"))
new("/d/dagger/Elvanta/forest/mon/ironroot")->move(this_object());
}
