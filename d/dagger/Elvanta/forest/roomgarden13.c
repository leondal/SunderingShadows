#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^ORANGE%^You continue to walk through the rock garden, as it rambles through the grounds.  %^MAGENTA%^Amethyst,%^RESET%^ %^YELLOW%^amber,%^RESET%^ %^RED%^ruby red crystal,%^RESET%^ %^GREEN%^swirling malachite,%^RESET%^ %^ORANGE%^and%^RESET%^ %^BLUE%^sapphire blue aquamarine%^RESET%^ %^ORANGE%^makes up this garden of brilliant colours.  Flowers and vines trail through, over and under the rock to add more colour and a delicate contrast.%^RESET%^");
set_smell ("default", "%^CYAN%^Creeping flox, bright blue forget-me-nots, and lily of the valley woven between the rocks, create an odour of gentle breezes.");
set_listen ("default", "Bird sing, insects hums and bees drone by.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomgarden12",
"south" : "/d/dagger/Elvanta/forest/roomgarden14"
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
}
void reset(){
::reset();
if(!present("pegasus"))
new("/realms/pegasus/mon/pegasus")->move(TO);
}
