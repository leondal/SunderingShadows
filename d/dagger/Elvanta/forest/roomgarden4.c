#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set_long ("%^GREEN%^This small patch of green heaven has a gazebo in the middle where you can sit and rest.  Wind chimes fill the air with song joined by birds of wondrous sound.  Peace and contentment reside here.%^RESET%^");
set_smell ("default", "%^CYAN%^The fragrance of a thousand flowers hovers in the air.");
set_listen ("default", "Wind chimes, birds singing, insects humming creates an orchestra of sound.");
set_exits (([
"enter" : "/d/dagger/Elvanta/forest/roomgazebo1",
"east" : "/d/dagger/Elvanta/forest/roomgarden5",
"west" : "/d/dagger/Elvanta/forest/roomgarden3"
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
