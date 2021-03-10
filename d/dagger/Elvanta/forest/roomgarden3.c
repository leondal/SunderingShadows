#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set ("day long", "%^GREEN%^You walk upon deep emerald green moss grounds, with trees shading your head.  The many flowers fill the air with perfume and you feel welcome and warm here.  Birds of every hue flutter and flow through the air filling it with song.  You see statues upon the grounds of many animals and human like creatures.%^RESET%^");
set ("night long", "%^CYAN%^You walk upon deep emerald gree moss grounds, with trees lending a romantic aura.  The many night flowers fill the air with perfume and you safe and welcome here.  Night creatures scurry by you appearing to have no fear.  You see statues upon the grounds of many animals and human like creatures.%^RESET%^");
set_smell ("default", "%^CYAN%^The fragrance of a thousand flowers hovers in the air.");
set_listen ("default", "You hear many songs from the birds flying and settling upon the branches of the trees.");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomgarden4",
"west" : "/d/dagger/Elvanta/forest/roomgarden2"
]));
set_items
(([
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"globes" : "Great cirles of light pour from these globes, lighting the way for you and other travellers.  They hang from intricately forged silver chains, which give off a glow of their own.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset() {
::reset();
if(!present("anuin"))
new("/d/dagger/Elvanta/forest/mon/anuin")->move(this_object());
if(!present("duac"))
new("/d/dagger/Elvanta/forest/mon/duac")->move(this_object());
}
