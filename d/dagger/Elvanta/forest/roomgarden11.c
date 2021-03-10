#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long("%^GREEN%^As you pass the rose gardens you reach a peaceful area, where you can sit and rest.  An octogon shaped gazebo is here, with glorious fretwork around the roof of the building, giving it an airy and delicate look.  Perhaps you could rest and relax within the gazebo, if you so desire.%^RESET%^");
set_smell ("default", "%^CYAN%^The fragrance of a thousand flowers hovers in the air.");
set_listen ("default", "Bird sing, insects hums and bees drone by.");
set_exits (([
"enter" : "/d/dagger/Elvanta/forest/roomgazebo2",
"east" : "/d/dagger/Elvanta/forest/roomgarden10",
"west" : "/d/dagger/Elvanta/forest/roomgarden12"
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
