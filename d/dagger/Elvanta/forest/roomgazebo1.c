#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 1);
set_short ("A round gazebo");
set_long("%^GREEN%^You have come to a round gazebo with settees set around the inside walls.  You can see outside the windows as they are open to the breezes.  Small tables rest here as well, set with flowers and wine.  A welcome resting place for your weary feet.%^RESET%^");
set_smell("default", "%^MAGENTA%^The odour of roses and lavender comes from the flowers set upon the tables.");
set_listen ("default", "Birds sing, a brook babbles, wind chimes dance in the slight breeze.");
set_exits (([
"exit" : "/d/dagger/Elvanta/forest/roomgarden4",
]));
set_items
(([
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset() {
::reset();
if(!present("settee"))
new("/d/dagger/Elvanta/forest/items/objs/settee")->move(this_object());
if(!present("table"))
new("/realms/svaha/items/table")->move(this_object());
if(!present("greenhag"))
new("/d/dagger/Elvanta/forest/mon/greenhag")->move(TO);
}
