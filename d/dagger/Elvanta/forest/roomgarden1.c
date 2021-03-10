#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set ("day long", "%^GREEN%^You have reached an iron fence, that rises twenty feet into the air, its summit spiked and laced with sharpened spurs.  Beyond the forbiddng barrier, tree-shaded grounds stretch away to a sprawling turreted building that can only be the palace of the Elven rulers.%^RESET%^");
set ("night long", "%^CYAN%^You have reached an iron fence, lit by <globes> hanging from silver chains.  The fence rises twenty feet into the air, its summit spiked and laced with sharpened spurs.  Beyond the forbidding barrier, tree-shaded grounds stretch away to a sprawling turreted building that can only be the palace of the Elven rulers.%^RESET%^");
set_smell ("default", "%^CYAN%^The fragrance of a thousand flowers hovers in the air.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roomgarden15",
"south" : "/d/dagger/Elvanta/forest/room128",
"gate" : "/d/dagger/Elvanta/forest/roomgarden2"
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
